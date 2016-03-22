// RdpRenderClientPlugin.h : Declaration of the CRdpRenderClientPlugin

#pragma once
#include "resource.h"       // main symbols



#include "RdpRenderChannel_i.h"



using namespace ATL;


// CRdpRenderClientPlugin

class ATL_NO_VTABLE CRdpRenderClientPlugin :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CRdpRenderClientPlugin, &CLSID_RdpRenderClientPlugin>,
	public IWTSPlugin
{
public:
	CRdpRenderClientPlugin()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RDPRENDERCLIENTPLUGIN)


BEGIN_COM_MAP(CRdpRenderClientPlugin)
	COM_INTERFACE_ENTRY(IRdpRenderClientPlugin)
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



};

OBJECT_ENTRY_AUTO(__uuidof(RdpRenderClientPlugin), CRdpRenderClientPlugin)
