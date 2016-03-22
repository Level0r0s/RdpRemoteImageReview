

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Feb 01 11:40:53 2013
 */
/* Compiler settings for RdpRenderChannel.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __RdpRenderChannel_i_h__
#define __RdpRenderChannel_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IRdpRenderServer_FWD_DEFINED__
#define __IRdpRenderServer_FWD_DEFINED__
typedef interface IRdpRenderServer IRdpRenderServer;
#endif 	/* __IRdpRenderServer_FWD_DEFINED__ */


#ifndef __IRdpRenderClientPlugin_FWD_DEFINED__
#define __IRdpRenderClientPlugin_FWD_DEFINED__
typedef interface IRdpRenderClientPlugin IRdpRenderClientPlugin;
#endif 	/* __IRdpRenderClientPlugin_FWD_DEFINED__ */


#ifndef __RdpRenderServer_FWD_DEFINED__
#define __RdpRenderServer_FWD_DEFINED__

#ifdef __cplusplus
typedef class RdpRenderServer RdpRenderServer;
#else
typedef struct RdpRenderServer RdpRenderServer;
#endif /* __cplusplus */

#endif 	/* __RdpRenderServer_FWD_DEFINED__ */


#ifndef __RdpRenderClientPlugin_FWD_DEFINED__
#define __RdpRenderClientPlugin_FWD_DEFINED__

#ifdef __cplusplus
typedef class RdpRenderClientPlugin RdpRenderClientPlugin;
#else
typedef struct RdpRenderClientPlugin RdpRenderClientPlugin;
#endif /* __cplusplus */

#endif 	/* __RdpRenderClientPlugin_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IRdpRenderServer_INTERFACE_DEFINED__
#define __IRdpRenderServer_INTERFACE_DEFINED__

/* interface IRdpRenderServer */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRdpRenderServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F8E8E327-91AC-4F72-B137-CEE1CCBD4652")
    IRdpRenderServer : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_InWtsSession( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterView( 
            /* [in] */ BSTR ViewName,
            /* [retval][out] */ ULONG *ViewId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterView( 
            /* [in] */ ULONG ViewId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddLayer( 
            /* [in] */ ULONG ViewId,
            /* [in] */ ULONG LayerNumber,
            /* [in] */ BSTR LayerDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateLayer( 
            /* [in] */ ULONG ViewId,
            /* [in] */ ULONG LayerNumber,
            /* [in] */ BSTR PixelFormatGuid,
            /* [in] */ BYTE *PixelBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetQuality( 
            /* [in] */ ULONG ViewId,
            /* [in] */ ULONG LayerNumber,
            /* [in] */ ULONG QualityLevel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRdpRenderServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRdpRenderServer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRdpRenderServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRdpRenderServer * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_InWtsSession )( 
            IRdpRenderServer * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterView )( 
            IRdpRenderServer * This,
            /* [in] */ BSTR ViewName,
            /* [retval][out] */ ULONG *ViewId);
        
        HRESULT ( STDMETHODCALLTYPE *UnregisterView )( 
            IRdpRenderServer * This,
            /* [in] */ ULONG ViewId);
        
        HRESULT ( STDMETHODCALLTYPE *AddLayer )( 
            IRdpRenderServer * This,
            /* [in] */ ULONG ViewId,
            /* [in] */ ULONG LayerNumber,
            /* [in] */ BSTR LayerDescription);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateLayer )( 
            IRdpRenderServer * This,
            /* [in] */ ULONG ViewId,
            /* [in] */ ULONG LayerNumber,
            /* [in] */ BSTR PixelFormatGuid,
            /* [in] */ BYTE *PixelBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *SetQuality )( 
            IRdpRenderServer * This,
            /* [in] */ ULONG ViewId,
            /* [in] */ ULONG LayerNumber,
            /* [in] */ ULONG QualityLevel);
        
        END_INTERFACE
    } IRdpRenderServerVtbl;

    interface IRdpRenderServer
    {
        CONST_VTBL struct IRdpRenderServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRdpRenderServer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRdpRenderServer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRdpRenderServer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRdpRenderServer_get_InWtsSession(This,pVal)	\
    ( (This)->lpVtbl -> get_InWtsSession(This,pVal) ) 

#define IRdpRenderServer_RegisterView(This,ViewName,ViewId)	\
    ( (This)->lpVtbl -> RegisterView(This,ViewName,ViewId) ) 

#define IRdpRenderServer_UnregisterView(This,ViewId)	\
    ( (This)->lpVtbl -> UnregisterView(This,ViewId) ) 

#define IRdpRenderServer_AddLayer(This,ViewId,LayerNumber,LayerDescription)	\
    ( (This)->lpVtbl -> AddLayer(This,ViewId,LayerNumber,LayerDescription) ) 

#define IRdpRenderServer_UpdateLayer(This,ViewId,LayerNumber,PixelFormatGuid,PixelBuffer)	\
    ( (This)->lpVtbl -> UpdateLayer(This,ViewId,LayerNumber,PixelFormatGuid,PixelBuffer) ) 

#define IRdpRenderServer_SetQuality(This,ViewId,LayerNumber,QualityLevel)	\
    ( (This)->lpVtbl -> SetQuality(This,ViewId,LayerNumber,QualityLevel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRdpRenderServer_INTERFACE_DEFINED__ */


#ifndef __IRdpRenderClientPlugin_INTERFACE_DEFINED__
#define __IRdpRenderClientPlugin_INTERFACE_DEFINED__

/* interface IRdpRenderClientPlugin */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRdpRenderClientPlugin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D291CAD9-1CA9-4181-90CD-1BC6101F8808")
    IRdpRenderClientPlugin : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IRdpRenderClientPluginVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRdpRenderClientPlugin * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRdpRenderClientPlugin * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRdpRenderClientPlugin * This);
        
        END_INTERFACE
    } IRdpRenderClientPluginVtbl;

    interface IRdpRenderClientPlugin
    {
        CONST_VTBL struct IRdpRenderClientPluginVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRdpRenderClientPlugin_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRdpRenderClientPlugin_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRdpRenderClientPlugin_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRdpRenderClientPlugin_INTERFACE_DEFINED__ */



#ifndef __RdpRenderChannelLib_LIBRARY_DEFINED__
#define __RdpRenderChannelLib_LIBRARY_DEFINED__

/* library RdpRenderChannelLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_RdpRenderChannelLib;

EXTERN_C const CLSID CLSID_RdpRenderServer;

#ifdef __cplusplus

class DECLSPEC_UUID("C4ED5941-6BFE-49D6-A7EB-F5768243C807")
RdpRenderServer;
#endif

EXTERN_C const CLSID CLSID_RdpRenderClientPlugin;

#ifdef __cplusplus

class DECLSPEC_UUID("0ED88DCC-A538-4443-B9E4-0557E8571170")
RdpRenderClientPlugin;
#endif
#endif /* __RdpRenderChannelLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


