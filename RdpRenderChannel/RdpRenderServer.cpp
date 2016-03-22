// RdpRenderServer.cpp : Implementation of CRdpRenderServer

#include "stdafx.h"
#include "RdpRenderServer.h"


// CRdpRenderServer



STDMETHODIMP CRdpRenderServer::get_InWtsSession(VARIANT_BOOL* pVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}


STDMETHODIMP CRdpRenderServer::RegisterView(BSTR ViewName, ULONG* ViewId)
{
	// TODO: Add your implementation code here

	return S_OK;
}


STDMETHODIMP CRdpRenderServer::UnregisterView(ULONG ViewId)
{
	// TODO: Add your implementation code here

	return S_OK;
}


STDMETHODIMP CRdpRenderServer::AddLayer(ULONG ViewId, ULONG LayerNumber, BSTR LayerDescription)
{
	// TODO: Add your implementation code here

	return S_OK;
}


STDMETHODIMP CRdpRenderServer::UpdateLayer(ULONG ViewId, ULONG LayerNumber, BSTR PixelFormatGuid, BYTE* PixelBuffer)
{
	// TODO: Add your implementation code here

	return S_OK;
}


STDMETHODIMP CRdpRenderServer::SetQuality(ULONG ViewId, ULONG LayerNumber, ULONG QualityLevel)
{
	// TODO: Add your implementation code here

	return S_OK;
}
