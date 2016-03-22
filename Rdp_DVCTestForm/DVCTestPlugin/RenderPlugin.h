// RenderPlugin.h : Declaration of the CRenderPlugin

#pragma once
#include "resource.h"       // main symbols



#include "DVCTestPlugin_i.h"



using namespace ATL;

#define CHECK_QUIT_HR( _x_ )    if(FAILED(hr)) { return hr; }

typedef struct CompositionPacket
{
	UINT PacketSize;

	UINT64 MappingId;
	UINT LayerId;

	ULONG TimeStamp;

	D2D1_MATRIX_3X2_F ViewXform;

	D2D1_MATRIX_3X2_F MappingXform;

	GUID BufferFormat;
	UINT BufferWidth;
	UINT BufferHeight;
	UINT BufferStride;
	UINT BufferOffset;
	ULONG BufferTimeStamp;

	GUID MappingFormat;
	UINT MappingWidth;
	UINT MappingHeight;
	UINT MappingOffset;
	ULONG MappingTimeStamp;

} _CompositionPacket;

// CRenderPlugin

class ATL_NO_VTABLE CRenderPlugin :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CRenderPlugin, &CLSID_RenderPlugin>,
	public IWTSPlugin,
    public IWTSListenerCallback,
    public IWTSVirtualChannelCallback,
    public IWTSBitmapRendererCallback
{
    CComPtr<IWTSVirtualChannel> m_pChannel;
	CComPtr<IWTSBitmapRenderService> m_pRenderService;

	RenderMessage _rm;
	CAtlArray<BYTE> _buffer;

public:
	CRenderPlugin()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RENDERPLUGIN)


BEGIN_COM_MAP(CRenderPlugin)
	COM_INTERFACE_ENTRY(IWTSPlugin)
	COM_INTERFACE_ENTRY(IWTSListenerCallback)
	COM_INTERFACE_ENTRY(IWTSVirtualChannelCallback)
	COM_INTERFACE_ENTRY(IWTSBitmapRendererCallback)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

#pragma region IWTSPlugin

	HRESULT STDMETHODCALLTYPE 
		Initialize(IWTSVirtualChannelManager *pChannelMgr);

	HRESULT STDMETHODCALLTYPE 
		Connected( void) 
	{ 
		return S_OK; 
	}

	HRESULT STDMETHODCALLTYPE 
		Disconnected(DWORD dwDisconnectCode) 
	{ 
        // Prevent C4100 "unreferenced parameter" warnings.
        dwDisconnectCode;

		return S_OK; 
	}

	HRESULT STDMETHODCALLTYPE 
		Terminated( void) 
	{ 
		return S_OK; 
	}

#pragma endregion

#pragma region IWTSListenerCallback

    HRESULT STDMETHODCALLTYPE
        OnNewChannelConnection(
        __in IWTSVirtualChannel *pChannel,
        __in_opt BSTR data,
        __out BOOL *pbAccept,
        __out IWTSVirtualChannelCallback **ppCallback )
	{
		*pbAccept = FALSE;

		m_pChannel = pChannel;
		(*ppCallback) = this;

		*pbAccept = TRUE;

		return S_OK;
	}

#pragma endregion

#pragma region IWTSVirtualChannelCallback

    HRESULT STDMETHODCALLTYPE
        OnDataReceived(
        ULONG cbSize,
        __in_bcount(cbSize) BYTE *pBuffer
        )
    {
		CopyMemory(&_rm, pBuffer, sizeof(_rm));

		size_t szBuffer = _rm.Stride * _rm.Height * 4;
		_buffer.SetCount(szBuffer);
		CopyMemory(_buffer.GetData(), &pBuffer[sizeof(_rm)], szBuffer);

		CComPtr<IWTSBitmapRenderer> pMappedRenderer;
		m_pRenderService->GetMappedRenderer(_rm.MappingId, this, &pMappedRenderer);
		HRESULT hr = pMappedRenderer->Render(_rm.ImageFormat, 
			_rm.Width, _rm.Height, _rm.Stride, szBuffer, _rm.Ptr);

        return m_pChannel->Write(cbSize, pBuffer, NULL); 
    }

    HRESULT STDMETHODCALLTYPE
        OnClose()
    { 
        return m_pChannel->Close(); 
    }

#pragma endregion

#pragma region IWTSBitmapRendererCallback

    HRESULT STDMETHODCALLTYPE
		OnTargetSizeChanged( 
            __in RECT rcNewSize)
	{
		return S_OK;
	}

#pragma endregion

};

OBJECT_ENTRY_AUTO(__uuidof(RenderPlugin), CRenderPlugin)


// IWTSPlugin::Initialize implementation.
HRESULT
    CRenderPlugin::Initialize(
    __in IWTSVirtualChannelManager *pChannelMgr
    )
{
	CComQIPtr<IWTSPluginServiceProvider> pSvcProvider = pChannelMgr;

	// get the render service
	CComPtr<IUnknown> pUnk;
	HRESULT hr = pSvcProvider->GetService(RDCLIENT_BITMAP_RENDER_SERVICE, &pUnk);
    CHECK_QUIT_HR("GetService");
	m_pRenderService = pUnk;

    // Attach the callback to the "DVC_Sample" endpoint.
    CComPtr<IWTSListener> ptrListener;
    hr = pChannelMgr->CreateListener( 
        "DVC_Sample", 
        0, 
		this,
		&ptrListener);
    CHECK_QUIT_HR("CreateListener");

    return hr;
}
