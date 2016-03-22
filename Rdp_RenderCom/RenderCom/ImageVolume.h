// ImageVolume.h : Declaration of the CImageVolume

#pragma once
#include "resource.h"       // main symbols



#include "RenderCom_i.h"



using namespace ATL;


// CImageVolume

class ATL_NO_VTABLE CImageVolume :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CImageVolume, &CLSID_ImageVolume>,
	public IImageVolume
{
public:
	CImageVolume()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_IMAGEVOLUME)


BEGIN_COM_MAP(CImageVolume)
	COM_INTERFACE_ENTRY(IImageVolume)
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



	STDMETHOD(get_PixelSpacing)(SAFEARRAY * * pVal);
	STDMETHOD(put_PixelSpacing)(SAFEARRAY *newVal);
	STDMETHOD(get_Buffer)(SAFEARRAY * * pVal);
	STDMETHOD(put_Buffer)(SAFEARRAY * newVal);
};

OBJECT_ENTRY_AUTO(__uuidof(ImageVolume), CImageVolume)
