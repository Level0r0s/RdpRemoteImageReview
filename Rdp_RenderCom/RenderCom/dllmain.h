// dllmain.h : Declaration of module class.

class CRenderComModule : public ATL::CAtlDllModuleT< CRenderComModule >
{
public :
	DECLARE_LIBID(LIBID_RenderComLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_RENDERCOM, "{065637FE-F8E9-4BF1-BA2A-89E689013884}")
};

extern class CRenderComModule _AtlModule;
