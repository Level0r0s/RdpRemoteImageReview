// RdpRenderServer.h : Declaration of the CRdpRenderServer

#pragma once
#include "resource.h"       // main symbols



#include "RdpRenderChannel_i.h"



using namespace ATL;


// CRdpRenderServer

class ATL_NO_VTABLE CRdpRenderServer :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CRdpRenderServer, &CLSID_RdpRenderServer>,
	public IRdpRenderServer
{
public:
	CRdpRenderServer()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RDPRENDERSERVER)


BEGIN_COM_MAP(CRdpRenderServer)
	COM_INTERFACE_ENTRY(IRdpRenderServer)
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



	STDMETHOD(get_InWtsSession)(VARIANT_BOOL* pVal);
	STDMETHOD(RegisterView)(BSTR ViewName, ULONG* ViewId);
	STDMETHOD(UnregisterView)(ULONG ViewId);
	STDMETHOD(AddLayer)(ULONG ViewId, ULONG LayerNumber, BSTR LayerDescription);
	STDMETHOD(UpdateLayer)(ULONG ViewId, ULONG LayerNumber, BSTR PixelFormatGuid, BYTE* PixelBuffer);
	STDMETHOD(SetQuality)(ULONG ViewId, ULONG LayerNumber, ULONG QualityLevel);
};

OBJECT_ENTRY_AUTO(__uuidof(RdpRenderServer), CRdpRenderServer)
