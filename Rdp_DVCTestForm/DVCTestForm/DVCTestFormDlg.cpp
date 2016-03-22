
// DVCTestFormDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DVCTestForm.h"
#include "DVCTestFormDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDVCTestFormDlg dialog



CDVCTestFormDlg::CDVCTestFormDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDVCTestFormDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDVCTestFormDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDVCTestFormDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CDVCTestFormDlg message handlers

#define _MAX_WAIT       60000
#define MAX_MSG_SIZE    0x20000
#define START_MSG_SIZE  4
#define STEP_MSG_SIZE   113

DWORD OpenDynamicChannel(LPCSTR szChannelName, HANDLE *phFile);
DWORD WINAPI WriteThread(PVOID param);
DWORD WINAPI ReadThread(PVOID param);

BOOL CDVCTestFormDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	UINT64 hintID;
	CRect rect(10,10,110,130);
	HRESULT hr = WTSSetRenderHint(&hintID, GetSafeHwnd(), 
		RENDER_HINT_MAPPEDWINDOW, sizeof(CRect), (BYTE*) &rect);


	HANDLE hFile;
	DWORD rc = OpenDynamicChannel ( "DVC_Sample", &hFile );
	if ( ERROR_SUCCESS != rc )
	{
		return 0;
	}

	DWORD dwThreadId;
	HANDLE hReadThread = CreateThread(
		NULL,
		0,
		ReadThread,
		hFile,
		0,
		&dwThreadId );

	HANDLE hWriteThread = CreateThread(
		NULL,
		0,
		WriteThread,
		hFile,
		0,
		&dwThreadId );

#ifdef ASYNC_
	HANDLE ah[] = {hReadThread, hWriteThread};
	WaitForMultipleObjects(2, ah, TRUE, INFINITE );

	CloseHandle( hReadThread );
	CloseHandle( hWriteThread );
	CloseHandle( hFile );
#endif

	return TRUE;  // return TRUE  unless you set the focus to a control
}

/*
*  Open a dynamic channel with the name given in szChannelName.
*  The output file handle can be used in ReadFile/WriteFile calls.
*/
DWORD OpenDynamicChannel(
	LPCSTR szChannelName, 
	HANDLE *phFile )
{
	HANDLE hWTSHandle = NULL;
	HANDLE hWTSFileHandle;
	PVOID vcFileHandlePtr = NULL;
	DWORD len;
	DWORD rc = ERROR_SUCCESS;

	hWTSHandle = WTSVirtualChannelOpenEx(
		WTS_CURRENT_SESSION,
		(LPSTR)szChannelName,
		WTS_CHANNEL_OPTION_DYNAMIC );
	if ( NULL == hWTSHandle )
	{
		rc = GetLastError();
		goto exitpt;
	}

	BOOL fSucc = WTSVirtualChannelQuery(
		hWTSHandle,
		WTSVirtualFileHandle,
		&vcFileHandlePtr,
		&len );
	if ( !fSucc )
	{
		rc = GetLastError();
		goto exitpt;
	}
	if ( len != sizeof( HANDLE ))
	{
		rc = ERROR_INVALID_PARAMETER;
		goto exitpt;
	}

	hWTSFileHandle = *(HANDLE *)vcFileHandlePtr;

	fSucc = DuplicateHandle(
		GetCurrentProcess(),
		hWTSFileHandle,
		GetCurrentProcess(),
		phFile,
		0,
		FALSE,
		DUPLICATE_SAME_ACCESS );
	if ( !fSucc )
	{
		rc = GetLastError();
		goto exitpt;
	}

	rc = ERROR_SUCCESS;

exitpt:
	if ( vcFileHandlePtr )
	{
		WTSFreeMemory( vcFileHandlePtr );
	}
	if ( hWTSHandle )
	{
		WTSVirtualChannelClose( hWTSHandle );
	}

	return rc;
}

/* 
*  Write a series of random messages into the dynamic virtual channel.
*/
DWORD WINAPI WriteThread(PVOID param)
{
	HANDLE  hFile;
	BYTE    WriteBuffer[MAX_MSG_SIZE];
	DWORD   dwWritten;
	BOOL    fSucc;
	BYTE    b = 0;
	HANDLE  hEvent;

	hFile = (HANDLE)param;

	hEvent = CreateEvent( NULL, FALSE, FALSE, NULL );

	for( ULONG msgSize = START_MSG_SIZE; 
		msgSize < MAX_MSG_SIZE; 
		msgSize += STEP_MSG_SIZE )
	{
		OVERLAPPED  Overlapped = {0};
		Overlapped.hEvent = hEvent;

		for( ULONG i = 0; i < msgSize; i++, b++ )
		{
			WriteBuffer[i] = b;
		}

		fSucc = WriteFile(
			hFile,
			WriteBuffer,
			msgSize,
			&dwWritten,
			&Overlapped );
		if ( !fSucc )
		{
			if ( GetLastError() == ERROR_IO_PENDING )
			{
				DWORD dw = WaitForSingleObject( Overlapped.hEvent, _MAX_WAIT );
				_ASSERT( WAIT_OBJECT_0 == dw );
				fSucc = GetOverlappedResult(
					hFile,
					&Overlapped,
					&dwWritten,
					FALSE );
			}
		}

		if ( !fSucc )
		{
			DWORD error = GetLastError();
			return error;
		}

		_ASSERT( dwWritten == msgSize );
	}

	return 0;
}

/* 
*  Read the data from the dynamic virtual channel reconstruct the original 
*  message and verify its content.
*/
DWORD WINAPI ReadThread(PVOID param)
{
	HANDLE hFile;
	BYTE ReadBuffer[CHANNEL_PDU_LENGTH];
	DWORD dwRead;
	BYTE b = 0;
	CHANNEL_PDU_HEADER *pHdr;
	BOOL fSucc;
	HANDLE hEvent;

	hFile = (HANDLE)param;
	pHdr = (CHANNEL_PDU_HEADER*)ReadBuffer;

	hEvent = CreateEvent( NULL, FALSE, FALSE, NULL );

	for( ULONG msgSize = START_MSG_SIZE; 
		msgSize < MAX_MSG_SIZE; 
		msgSize += STEP_MSG_SIZE )
	{
		OVERLAPPED  Overlapped = {0};
		DWORD TotalRead = 0;
		do 
		{
			Overlapped.hEvent = hEvent;

			// Read the entire message.
			fSucc = ReadFile(
				hFile,
				ReadBuffer,
				sizeof( ReadBuffer ),
				&dwRead,
				&Overlapped );
			if ( !fSucc )
			{
				if ( GetLastError() == ERROR_IO_PENDING )
				{
					DWORD dw = WaitForSingleObject( Overlapped.hEvent, INFINITE );
					_ASSERT( WAIT_OBJECT_0 == dw );
					fSucc = GetOverlappedResult(
						hFile,
						&Overlapped,
						&dwRead,
						FALSE );
				}
			}

			if ( !fSucc )
			{
				DWORD error = GetLastError();
				return error;
			}

			ULONG packetSize = dwRead - sizeof( *pHdr );
			TotalRead += packetSize;
			PBYTE pData = (PBYTE)( pHdr + 1 );
			for ( ULONG i = 0; i < packetSize; pData++, i++, b++ )
			{
				_ASSERT( *pData == b );
			}

			_ASSERT( msgSize == pHdr->length );

		} while( 0 == ( pHdr->flags & CHANNEL_FLAG_LAST ));

		_ASSERT( TotalRead == msgSize );
	}

	return 0;
}

void CDVCTestFormDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDVCTestFormDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDVCTestFormDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

