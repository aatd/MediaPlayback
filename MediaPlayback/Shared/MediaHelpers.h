//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

#pragma once

#include <windows.media.h>
#include <windows.media.core.h>
#include <windows.media.core.interop.h>
#include <windows.media.mediaproperties.h>
#include <windows.media.playback.h>
#include <windows.media.streaming.adaptive.h>
#include <windows.graphics.directx.direct3d11.interop.h>

#include "FFMpegInterop\FFmpegInteropMSS.h"

typedef ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult*> ICreateAdaptiveMediaSourceOperation;
typedef ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult*> ICreateAdaptiveMediaSourceResultHandler;

DECLARE_INTERFACE_IID_(IAdaptiveMediaSourceCompletedCallback, IUnknown, "e25c01d3-35d4-4551-bf6c-7d4be0498949")
{
    STDMETHOD(OnAdaptiveMediaSourceCreated)(ICreateAdaptiveMediaSourceOperation* pOp, AsyncStatus status) PURE;
};

HRESULT CreateMediaSource(
    _In_ LPCWSTR pszUrl,
    _COM_Outptr_ ABI::Windows::Media::Core::IMediaSource2** ppMediaSource);

HRESULT CreateFFmpegMediaSource(
    _In_ LPCWSTR pszUrl,
    _In_ bool forceAudioDecode,
    _In_ bool forceVideoDecode,
    _COM_Outptr_ FFmpegInterop::IFFmpegInteropMSS** ppFFmpegMSS,
    _COM_Outptr_ ABI::Windows::Media::Core::IMediaSource2** ppMediaSource);

HRESULT CreateAdaptiveMediaSource(
    _In_ LPCWSTR pszManifestLocation,
    _In_ IAdaptiveMediaSourceCompletedCallback* pCallback);

HRESULT CreateMediaPlaybackItem(
    _In_ ABI::Windows::Media::Core::IMediaSource2* pMediaSource,
    _COM_Outptr_ ABI::Windows::Media::Playback::IMediaPlaybackItem** ppMediaPlaybackItem);

HRESULT CreatePlaylistSource(
    _In_ ABI::Windows::Media::Core::IMediaSource2* pSource,
    _COM_Outptr_ ABI::Windows::Media::Playback::IMediaPlaybackSource** ppMediaPlaybackSource);

HRESULT GetSurfaceFromTexture(
    _In_ ID3D11Texture2D* pTexture,
    _COM_Outptr_ ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface** ppSurface);

HRESULT GetTextureFromSurface(
    _In_ ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface* pSurface,
    _COM_Outptr_ ID3D11Texture2D** ppTexture);

HRESULT CreateMediaDevice(
    _In_opt_ IDXGIAdapter* pDXGIAdapter,
    _COM_Outptr_ ID3D11Device** ppDevice);
