// dllmain.h : Declaration of module class.

class CRdpRenderChannelModule : public ATL::CAtlDllModuleT< CRdpRenderChannelModule >
{
public :
	DECLARE_LIBID(LIBID_RdpRenderChannelLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_RDPRENDERCHANNEL, "{F7D9E89A-90AB-4B51-863E-7E032915322D}")
};

extern class CRdpRenderChannelModule _AtlModule;
