

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IRdpRenderServer,0xF8E8E327,0x91AC,0x4F72,0xB1,0x37,0xCE,0xE1,0xCC,0xBD,0x46,0x52);


MIDL_DEFINE_GUID(IID, IID_IRdpRenderClientPlugin,0xD291CAD9,0x1CA9,0x4181,0x90,0xCD,0x1B,0xC6,0x10,0x1F,0x88,0x08);


MIDL_DEFINE_GUID(IID, LIBID_RdpRenderChannelLib,0x171F09F8,0x8F6E,0x42CA,0x8C,0xB6,0x02,0x10,0xA1,0xAF,0xC5,0xAE);


MIDL_DEFINE_GUID(CLSID, CLSID_RdpRenderServer,0xC4ED5941,0x6BFE,0x49D6,0xA7,0xEB,0xF5,0x76,0x82,0x43,0xC8,0x07);


MIDL_DEFINE_GUID(CLSID, CLSID_RdpRenderClientPlugin,0x0ED88DCC,0xA538,0x4443,0xB9,0xE4,0x05,0x57,0xE8,0x57,0x11,0x70);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



