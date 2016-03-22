

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Wed Mar 06 08:09:43 2013
 */
/* Compiler settings for RenderCom.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
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

#ifndef __RenderCom_i_h__
#define __RenderCom_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IImageVolume_FWD_DEFINED__
#define __IImageVolume_FWD_DEFINED__
typedef interface IImageVolume IImageVolume;

#endif 	/* __IImageVolume_FWD_DEFINED__ */


#ifndef __ImageVolume_FWD_DEFINED__
#define __ImageVolume_FWD_DEFINED__

#ifdef __cplusplus
typedef class ImageVolume ImageVolume;
#else
typedef struct ImageVolume ImageVolume;
#endif /* __cplusplus */

#endif 	/* __ImageVolume_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IImageVolume_INTERFACE_DEFINED__
#define __IImageVolume_INTERFACE_DEFINED__

/* interface IImageVolume */
/* [unique][nonextensible][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IImageVolume;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("860D3044-7914-4627-94D6-C99BE71FB1A8")
    IImageVolume : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_PixelSpacing( 
            /* [retval][out] */ SAFEARRAY * *pVal) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_PixelSpacing( 
            /* [in] */ SAFEARRAY * newVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Buffer( 
            /* [retval][out] */ SAFEARRAY * *pVal) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Buffer( 
            /* [in] */ SAFEARRAY * newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IImageVolumeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImageVolume * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImageVolume * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImageVolume * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_PixelSpacing )( 
            IImageVolume * This,
            /* [retval][out] */ SAFEARRAY * *pVal);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_PixelSpacing )( 
            IImageVolume * This,
            /* [in] */ SAFEARRAY * newVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buffer )( 
            IImageVolume * This,
            /* [retval][out] */ SAFEARRAY * *pVal);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Buffer )( 
            IImageVolume * This,
            /* [in] */ SAFEARRAY * newVal);
        
        END_INTERFACE
    } IImageVolumeVtbl;

    interface IImageVolume
    {
        CONST_VTBL struct IImageVolumeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImageVolume_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImageVolume_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImageVolume_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImageVolume_get_PixelSpacing(This,pVal)	\
    ( (This)->lpVtbl -> get_PixelSpacing(This,pVal) ) 

#define IImageVolume_put_PixelSpacing(This,newVal)	\
    ( (This)->lpVtbl -> put_PixelSpacing(This,newVal) ) 

#define IImageVolume_get_Buffer(This,pVal)	\
    ( (This)->lpVtbl -> get_Buffer(This,pVal) ) 

#define IImageVolume_put_Buffer(This,newVal)	\
    ( (This)->lpVtbl -> put_Buffer(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImageVolume_INTERFACE_DEFINED__ */



#ifndef __RenderComLib_LIBRARY_DEFINED__
#define __RenderComLib_LIBRARY_DEFINED__

/* library RenderComLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_RenderComLib;

EXTERN_C const CLSID CLSID_ImageVolume;

#ifdef __cplusplus

class DECLSPEC_UUID("B586DC66-1402-4A5D-8C90-666A089156D9")
ImageVolume;
#endif
#endif /* __RenderComLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


