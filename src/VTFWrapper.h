/*
 * VTFLib
 * Copyright (C) 2005-2010 Neil Jedrzejewski & Ryan Gregg

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later
 * version.
 */

#ifndef VTFLIB_VTFWRAPPER_H
#define VTFLIB_VTFWRAPPER_H

#include "stdafx.h"

#include "VTFFile.h"
#include "VTFLib.h"

#ifdef __cplusplus
extern "C" {
#endif

//
// Creation and disposal.
//

VTFLIB_API VTFLibVTFFile* vlCreateVTFFile();
VTFLIB_API vlVoid vlDestroyVTFFile(VTFLibVTFFile* VTFFile);
VTFLIB_API VTFLibError* vlCreateVTFLibError();
VTFLIB_API vlVoid vlDestroyVTFLibError(VTFLibError* VTFLibError);

//
// Error handling.
//

VTFLIB_API const vlChar *vlGetErrorMessage(VTFLibError* VTFLibError);

//
// Library routines.  (Basically class wrappers.)
//

VTFLIB_API vlVoid vlImageCreateDefaultCreateStructure(SVTFCreateOptions *VTFCreateOptions);

VTFLIB_API vlBool vlImageCreate(VTFLibVTFFile* VTFFile, vlUInt uiWidth, vlUInt uiHeight, vlUInt uiFrames, vlUInt uiFaces, vlUInt uiSlices, VTFImageFormat ImageFormat, vlBool bThumbnail, vlBool bMipmaps, vlBool bNullImageData, VTFLibError* Error);
VTFLIB_API vlBool vlImageCreateSingle(VTFLibVTFFile* VTFFile, vlUInt uiWidth, vlUInt uiHeight, vlByte *lpImageDataRGBA8888, SVTFCreateOptions *VTFCreateOptions, VTFLibError* Error);
VTFLIB_API vlBool vlImageCreateMultiple(VTFLibVTFFile* VTFFile, vlUInt uiWidth, vlUInt uiHeight, vlUInt uiFrames, vlUInt uiFaces, vlUInt uiSlices, vlByte **lpImageDataRGBA8888, SVTFCreateOptions *VTFCreateOptions, VTFLibError* Error);

VTFLIB_API vlBool vlImageIsLoaded(const VTFLibVTFFile* VTFFile, VTFLibError* Error);

VTFLIB_API vlBool vlImageLoad(VTFLibVTFFile* VTFFile, const vlChar *cFileName, vlBool bHeaderOnly, VTFLibError* Error);
VTFLIB_API vlBool vlImageLoadLump(VTFLibVTFFile* VTFFile, const vlVoid *lpData, vlSize uiBufferSize, vlBool bHeaderOnly, VTFLibError* Error);
VTFLIB_API vlBool vlImageLoadProc(VTFLibVTFFile* VTFFile, vlVoid *pUserData, vlBool bHeaderOnly, VTFLibError* Error);

VTFLIB_API vlBool vlImageSave(const VTFLibVTFFile* VTFFile, const vlChar *cFileName, VTFLibError* Error);
VTFLIB_API vlBool vlImageSaveLump(const VTFLibVTFFile* VTFFile, vlVoid *lpData, vlSize uiBufferSize, vlSize *uiSize, VTFLibError* Error);
VTFLIB_API vlBool vlImageSaveProc(const VTFLibVTFFile* VTFFile, vlVoid *pUserData, VTFLibError* Error);

//
// Image routines.
//

VTFLIB_API vlUInt vlImageGetHasImage(const VTFLibVTFFile* VTFFile);

VTFLIB_API vlUInt vlImageGetMajorVersion(const VTFLibVTFFile* VTFFile);
VTFLIB_API vlUInt vlImageGetMinorVersion(const VTFLibVTFFile* VTFFile);
VTFLIB_API vlUInt vlImageGetSize(const VTFLibVTFFile* VTFFile);

VTFLIB_API vlUInt vlImageGetWidth(const VTFLibVTFFile* VTFFile);
VTFLIB_API vlUInt vlImageGetHeight(const VTFLibVTFFile* VTFFile);
VTFLIB_API vlUInt vlImageGetDepth(const VTFLibVTFFile* VTFFile);

VTFLIB_API vlUInt vlImageGetFrameCount(const VTFLibVTFFile* VTFFile);
VTFLIB_API vlUInt vlImageGetFaceCount(const VTFLibVTFFile* VTFFile);
VTFLIB_API vlUInt vlImageGetMipmapCount(const VTFLibVTFFile* VTFFile);

VTFLIB_API vlUInt vlImageGetStartFrame(const VTFLibVTFFile* VTFFile);
VTFLIB_API vlVoid vlImageSetStartFrame(VTFLibVTFFile* VTFFile, vlUInt uiStartFrame);

VTFLIB_API vlUInt vlImageGetFlags(const VTFLibVTFFile* VTFFile);
VTFLIB_API vlVoid vlImageSetFlags(VTFLibVTFFile* VTFFile, vlUInt uiFlags);

VTFLIB_API vlBool vlImageGetFlag(const VTFLibVTFFile* VTFFile, VTFImageFlag ImageFlag);
VTFLIB_API vlVoid vlImageSetFlag(VTFLibVTFFile* VTFFile, VTFImageFlag ImageFlag, vlBool bState);

VTFLIB_API vlSingle vlImageGetBumpmapScale(const VTFLibVTFFile* VTFFile);
VTFLIB_API vlVoid vlImageSetBumpmapScale(VTFLibVTFFile* VTFFile, vlSingle sBumpmapScale);

VTFLIB_API vlVoid vlImageGetReflectivity(const VTFLibVTFFile* VTFFile, vlSingle *sX, vlSingle *sY, vlSingle *sZ);
VTFLIB_API vlVoid vlImageSetReflectivity(VTFLibVTFFile* VTFFile, vlSingle sX, vlSingle sY, vlSingle sZ);

VTFLIB_API VTFImageFormat vlImageGetFormat(const VTFLibVTFFile* VTFFile);

VTFLIB_API vlByte *vlImageGetData(const VTFLibVTFFile* VTFFile, vlUInt uiFrame, vlUInt uiFace, vlUInt uiSlice, vlUInt uiMipmapLevel);
VTFLIB_API vlVoid vlImageSetData(VTFLibVTFFile* VTFFile, vlUInt uiFrame, vlUInt uiFace, vlUInt uiSlice, vlUInt uiMipmapLevel, vlByte *lpData);

//
// Thumbnail routines.
//

VTFLIB_API vlBool vlImageGetHasThumbnail(const VTFLibVTFFile* VTFFile);

VTFLIB_API vlUInt vlImageGetThumbnailWidth(const VTFLibVTFFile* VTFFile);
VTFLIB_API vlUInt vlImageGetThumbnailHeight(const VTFLibVTFFile* VTFFile);

VTFLIB_API VTFImageFormat vlImageGetThumbnailFormat(const VTFLibVTFFile* VTFFile);

VTFLIB_API vlByte *vlImageGetThumbnailData(const VTFLibVTFFile* VTFFile);
VTFLIB_API vlVoid vlImageSetThumbnailData(VTFLibVTFFile* VTFFile, vlByte *lpData);

//
// Resource routines.
//

VTFLIB_API vlBool vlImageGetSupportsResources(const VTFLibVTFFile* VTFFile);

VTFLIB_API vlUInt vlImageGetResourceCount(const VTFLibVTFFile* VTFFile);
VTFLIB_API vlUInt vlImageGetResourceType(const VTFLibVTFFile* VTFFile, vlUInt uiIndex);
VTFLIB_API vlBool vlImageGetHasResource(const VTFLibVTFFile* VTFFile, vlUInt uiType);

VTFLIB_API vlVoid *vlImageGetResourceData(const VTFLibVTFFile* VTFFile, vlUInt uiType, vlUInt *uiSize, VTFLibError* Error);
VTFLIB_API vlVoid *vlImageSetResourceData(VTFLibVTFFile* VTFFile, vlUInt uiType, vlUInt uiSize, vlVoid *lpData, VTFLibError* Error);

//
// Helper routines.
//

VTFLIB_API vlBool vlImageGenerateMipmaps(VTFLibVTFFile* VTFFile, vlUInt uiFace, vlUInt uiFrame, VTFMipmapFilter MipmapFilter, VTFSharpenFilter SharpenFilter, VTFLibError* Error);
VTFLIB_API vlBool vlImageGenerateAllMipmaps(VTFLibVTFFile* VTFFile, VTFMipmapFilter MipmapFilter, VTFSharpenFilter SharpenFilter, VTFLibError* Error);

VTFLIB_API vlBool vlImageGenerateThumbnail(VTFLibVTFFile* VTFFile, VTFLibError** Error);

VTFLIB_API vlBool vlImageGenerateNormalMap(VTFLibVTFFile* VTFFile, vlUInt uiFrame, VTFKernelFilter KernelFilter, VTFHeightConversionMethod HeightConversionMethod, VTFNormalAlphaResult NormalAlphaResult, VTFLibError* Error);
VTFLIB_API vlBool vlImageGenerateAllNormalMaps(VTFLibVTFFile* VTFFile, VTFKernelFilter KernelFilter, VTFHeightConversionMethod HeightConversionMethod, VTFNormalAlphaResult NormalAlphaResult, VTFLibError* Error);

VTFLIB_API vlBool vlImageGenerateSphereMap(VTFLibVTFFile* VTFFile, VTFLibError* Error);

VTFLIB_API vlBool vlImageComputeReflectivity(VTFLibVTFFile* VTFFile, VTFLibError* Error);

//
// Conversion routines.
//

VTFLIB_API SVTFImageFormatInfo const *vlImageGetImageFormatInfo(VTFImageFormat ImageFormat);
VTFLIB_API vlBool vlImageGetImageFormatInfoEx(VTFImageFormat ImageFormat, SVTFImageFormatInfo *VTFImageFormatInfo);

VTFLIB_API vlUInt vlImageComputeImageSize(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth, vlUInt uiMipmaps, VTFImageFormat ImageFormat);

VTFLIB_API vlUInt vlImageComputeMipmapCount(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth);
VTFLIB_API vlVoid vlImageComputeMipmapDimensions(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth, vlUInt uiMipmapLevel, vlUInt *uiMipmapWidth, vlUInt *uiMipmapHeight, vlUInt *uiMipmapDepth);
VTFLIB_API vlUInt vlImageComputeMipmapSize(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth, vlUInt uiMipmapLevel, VTFImageFormat ImageFormat);

VTFLIB_API vlBool vlImageConvertToRGBA8888(vlByte *lpSource, vlByte *lpDest, vlUInt uiWidth, vlUInt uiHeight, VTFImageFormat SourceFormat, VTFLibError* Error);
VTFLIB_API vlBool vlImageConvertFromRGBA8888(vlByte *lpSource, vlByte *lpDest, vlUInt uiWidth, vlUInt uiHeight, VTFImageFormat DestFormat, VTFLibError* Error);

VTFLIB_API vlBool vlImageConvert(vlByte *lpSource, vlByte *lpDest, vlUInt uiWidth, vlUInt uiHeight, VTFImageFormat SourceFormat, VTFImageFormat DestFormat, VTFLibError* Error);

VTFLIB_API vlBool vlImageConvertToNormalMap(vlByte *lpSourceRGBA8888, vlByte *lpDestRGBA8888, vlUInt uiWidth, vlUInt uiHeight, VTFKernelFilter KernelFilter, VTFHeightConversionMethod HeightConversionMethod, VTFNormalAlphaResult NormalAlphaResult, vlByte bMinimumZ, vlSingle sScale, vlBool bWrap, vlBool bInvertX, vlBool bInvertY, VTFLibError* Error);

VTFLIB_API vlBool vlImageResize(vlByte *lpSourceRGBA8888, vlByte *lpDestRGBA8888, vlUInt uiSourceWidth, vlUInt uiSourceHeight, vlUInt uiDestWidth, vlUInt uiDestHeight, VTFMipmapFilter ResizeFilter, VTFSharpenFilter SharpenFilter, VTFLibError* Error);

VTFLIB_API vlVoid vlImageCorrectImageGamma(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight, vlSingle sGammaCorrection);
VTFLIB_API vlVoid vlImageComputeImageReflectivity(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight, vlSingle *sX, vlSingle *sY, vlSingle *sZ);

VTFLIB_API vlVoid vlImageFlipImage(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight);
VTFLIB_API vlVoid vlImageMirrorImage(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight);

#ifdef __cplusplus
}
#endif

#endif
