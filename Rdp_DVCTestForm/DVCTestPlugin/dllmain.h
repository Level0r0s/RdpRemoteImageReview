// dllmain.h : Declaration of module class.

class CDVCTestPluginModule : public ATL::CAtlDllModuleT< CDVCTestPluginModule >
{
public :
	DECLARE_LIBID(LIBID_DVCTestPluginLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DVCTESTPLUGIN, "{FEFC7B16-9508-4624-9836-60C20A8232FA}")
};

extern class CDVCTestPluginModule _AtlModule;
