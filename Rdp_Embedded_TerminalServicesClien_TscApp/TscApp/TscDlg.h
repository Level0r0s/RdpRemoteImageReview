
// TscDlg.h : header file
//

#pragma once
#include "mstscax1.h"


// CTscDlg dialog
class CTscDlg : public CDialogEx
{
// Construction
public:
	CTscDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TSCAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//CMstscax1 m_mstscAx1;
	CMstscax1 m_mstscAx4;
};
