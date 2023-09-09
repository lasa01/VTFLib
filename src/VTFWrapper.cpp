/*
 * VTFLib
 * Copyright (C) 2005-2011 Neil Jedrzejewski & Ryan Gregg

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later
 * version.
 */

#include <string.h>

#include "VTFLib.h"
#include "VTFWrapper.h"
#include "VTFFile.h"

using namespace VTFLib;

VTFLIB_API VTFLibVTFFile *vlCreateVTFFile()
{
    return new CVTFFile();
}

VTFLIB_API vlVoid vlDestroyVTFFile(VTFLibVTFFile *VTFFile)
{
	VTFFile->Destroy();
    delete VTFFile;
}

VTFLIB_API vlVoid vlImageCreateDefaultCreateStructure(SVTFCreateOptions *VTFCreateOptions)
{
	VTFCreateOptions->uiVersion[0] = VTF_MAJOR_VERSION;
	VTFCreateOptions->uiVersion[1] = VTF_MINOR_VERSION_DEFAULT;

	VTFCreateOptions->ImageFormat = IMAGE_FORMAT_RGBA8888;

	VTFCreateOptions->uiFlags = 0;
	VTFCreateOptions->uiStartFrame = 0;
	VTFCreateOptions->sBumpScale = 1.0f;
	VTFCreateOptions->sReflectivity[0] = 1.0f;
	VTFCreateOptions->sReflectivity[1] = 1.0f;
	VTFCreateOptions->sReflectivity[2] = 1.0f;

	VTFCreateOptions->bMipmaps = vlTrue;
	VTFCreateOptions->MipmapFilter = MIPMAP_FILTER_BOX;
	VTFCreateOptions->MipmapSharpenFilter = SHARPEN_FILTER_NONE;

	VTFCreateOptions->bResize = vlFalse;
	VTFCreateOptions->ResizeMethod = RESIZE_NEAREST_POWER2;
	VTFCreateOptions->ResizeFilter = MIPMAP_FILTER_TRIANGLE;
	VTFCreateOptions->ResizeSharpenFilter = SHARPEN_FILTER_NONE;
	VTFCreateOptions->uiResizeWidth = 0;
	VTFCreateOptions->uiResizeHeight = 0;

	VTFCreateOptions->bResizeClamp = vlTrue;
	VTFCreateOptions->uiResizeClampWidth = 4096;
	VTFCreateOptions->uiResizeClampHeight = 4096;

	VTFCreateOptions->bThumbnail = vlTrue;
	VTFCreateOptions->bReflectivity = vlTrue;

	VTFCreateOptions->bGammaCorrection = vlFalse;
	VTFCreateOptions->sGammaCorrection = 2.0f;

	VTFCreateOptions->bNormalMap = vlFalse;
	VTFCreateOptions->KernelFilter = KERNEL_FILTER_3X3;
	VTFCreateOptions->HeightConversionMethod = HEIGHT_CONVERSION_METHOD_AVERAGE_RGB;
	VTFCreateOptions->NormalAlphaResult = NORMAL_ALPHA_RESULT_WHITE;
	VTFCreateOptions->bNormalMinimumZ = 0;
	VTFCreateOptions->sNormalScale = 2.0f;
	VTFCreateOptions->bNormalWrap = vlFalse;
	VTFCreateOptions->bNormalInvertX = vlFalse;
	VTFCreateOptions->bNormalInvertY = vlFalse;
	VTFCreateOptions->bNormalInvertZ = vlFalse;

	VTFCreateOptions->bSphereMap = vlTrue;
}

VTFLIB_API vlBool vlImageCreate(VTFLibVTFFile* VTFFile, vlUInt uiWidth, vlUInt uiHeight, vlUInt uiFrames, vlUInt uiFaces, vlUInt uiSlices, VTFImageFormat ImageFormat, vlBool bThumbnail, vlBool bMipmaps, vlBool bNullImageData, VTFLibError* Error)
{
	return VTFFile->Create(uiWidth, uiHeight, *Error, uiFrames, uiFaces, uiSlices, ImageFormat, bThumbnail, bMipmaps, bNullImageData);
}

VTFLIB_API vlBool vlImageCreateSingle(VTFLibVTFFile* VTFFile, vlUInt uiWidth, vlUInt uiHeight, vlByte *lpImageDataRGBA8888, SVTFCreateOptions *VTFCreateOptions, VTFLibError* Error)
{
	return VTFFile->Create(uiWidth, uiHeight, lpImageDataRGBA8888, *VTFCreateOptions, *Error);
}

VTFLIB_API vlBool vlImageCreateMultiple(VTFLibVTFFile* VTFFile, vlUInt uiWidth, vlUInt uiHeight, vlUInt uiFrames, vlUInt uiFaces, vlUInt uiSlices, vlByte **lpImageDataRGBA8888, SVTFCreateOptions *VTFCreateOptions, VTFLibError* Error)
{
	return VTFFile->Create(uiWidth, uiHeight, uiFrames, uiFaces, uiSlices, lpImageDataRGBA8888, *VTFCreateOptions, *Error);
}

VTFLIB_API vlBool vlImageIsLoaded(const VTFLibVTFFile* VTFFile, VTFLibError* Error)
{
	return VTFFile->IsLoaded();
}

VTFLIB_API vlBool vlImageLoad(VTFLibVTFFile* VTFFile, const vlChar *cFileName, vlBool bHeaderOnly, VTFLibError* Error)
{
	return VTFFile->Load(cFileName, *Error, bHeaderOnly);
}

VTFLIB_API vlBool vlImageLoadLump(VTFLibVTFFile* VTFFile, const vlVoid *lpData, vlSize uiBufferSize, vlBool bHeaderOnly, VTFLibError* Error)
{
	return VTFFile->Load(lpData, uiBufferSize, *Error, bHeaderOnly);
}

VTFLIB_API vlBool vlImageLoadProc(VTFLibVTFFile* VTFFile, vlVoid *pUserData, vlBool bHeaderOnly, VTFLibError* Error)
{
	return VTFFile->Load(pUserData, bHeaderOnly, *Error);
}

VTFLIB_API vlBool vlImageSave(const VTFLibVTFFile* VTFFile, const vlChar *cFileName, VTFLibError* Error)
{
	return VTFFile->Save(cFileName, *Error);
}

VTFLIB_API vlBool vlImageSaveLump(const VTFLibVTFFile* VTFFile, vlVoid *lpData, vlSize uiBufferSize, vlSize *uiSize, VTFLibError* Error)
{
	return VTFFile->Save(lpData, uiBufferSize, *uiSize, *Error);
}

VTFLIB_API vlBool vlImageSaveProc(const VTFLibVTFFile* VTFFile, vlVoid *pUserData, VTFLibError* Error)
{
	return VTFFile->Save(pUserData, *Error);
}

VTFLIB_API vlUInt vlImageGetMajorVersion(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetMajorVersion();
}

VTFLIB_API vlUInt vlImageGetMinorVersion(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetMinorVersion();
}

VTFLIB_API vlUInt vlImageGetSize(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetSize();
}

VTFLIB_API vlUInt vlImageGetHasImage(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetHasImage();
}

VTFLIB_API vlUInt vlImageGetWidth(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetWidth();
}

VTFLIB_API vlUInt vlImageGetHeight(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetHeight();
}

VTFLIB_API vlUInt vlImageGetDepth(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetDepth();
}

VTFLIB_API vlUInt vlImageGetFrameCount(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetFrameCount();
}

VTFLIB_API vlUInt vlImageGetFaceCount(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetFaceCount();
}

VTFLIB_API vlUInt vlImageGetMipmapCount(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetMipmapCount();
}

VTFLIB_API vlUInt vlImageGetStartFrame(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetStartFrame();
}

VTFLIB_API vlVoid vlImageSetStartFrame(VTFLibVTFFile* VTFFile, vlUInt uiStartFrame)
{
	VTFFile->SetStartFrame(uiStartFrame);
}

VTFLIB_API vlUInt vlImageGetFlags(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetFlags();
}

VTFLIB_API vlVoid vlImageSetFlags(VTFLibVTFFile* VTFFile, vlUInt uiFlags)
{
	VTFFile->SetFlags(uiFlags);
}

VTFLIB_API vlBool vlImageGetFlag(const VTFLibVTFFile* VTFFile, VTFImageFlag ImageFlag)
{
	return VTFFile->GetFlag(ImageFlag);
}

VTFLIB_API vlVoid vlImageSetFlag(VTFLibVTFFile* VTFFile, VTFImageFlag ImageFlag, vlBool bState)
{
	VTFFile->SetFlag(ImageFlag, bState);
}

VTFLIB_API vlSingle vlImageGetBumpmapScale(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetBumpmapScale();
}

VTFLIB_API vlVoid vlImageSetBumpmapScale(VTFLibVTFFile* VTFFile, vlSingle sBumpmapScale)
{
	VTFFile->SetBumpmapScale(sBumpmapScale);
}

VTFLIB_API vlVoid vlImageGetReflectivity(const VTFLibVTFFile* VTFFile, vlSingle *sX, vlSingle *sY, vlSingle *sZ)
{
	VTFFile->GetReflectivity(*sX, *sY, *sZ);
}

VTFLIB_API vlVoid vlImageSetReflectivity(VTFLibVTFFile* VTFFile, vlSingle sX, vlSingle sY, vlSingle sZ)
{
	VTFFile->SetReflectivity(sX, sY, sZ);
}

VTFLIB_API VTFImageFormat vlImageGetFormat(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetFormat();
}

VTFLIB_API vlByte *vlImageGetData(const VTFLibVTFFile* VTFFile, vlUInt uiFrame, vlUInt uiFace, vlUInt uiSlice, vlUInt uiMipmapLevel)
{
	return VTFFile->GetData(uiFrame, uiFace, uiSlice, uiMipmapLevel);
}

VTFLIB_API vlVoid vlImageSetData(VTFLibVTFFile* VTFFile, vlUInt uiFrame, vlUInt uiFace, vlUInt uiSlice, vlUInt uiMipmapLevel, vlByte *lpData)
{
	VTFFile->SetData(uiFrame, uiFace, uiSlice, uiMipmapLevel, lpData);
}

VTFLIB_API vlBool vlImageGetHasThumbnail(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetHasThumbnail();
}

VTFLIB_API vlUInt vlImageGetThumbnailWidth(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetThumbnailWidth();
}

VTFLIB_API vlUInt vlImageGetThumbnailHeight(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetThumbnailHeight();
}

VTFLIB_API VTFImageFormat vlImageGetThumbnailFormat(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetThumbnailFormat();
}

VTFLIB_API vlByte *vlImageGetThumbnailData(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetThumbnailData();
}

VTFLIB_API vlVoid vlImageSetThumbnailData(VTFLibVTFFile* VTFFile, vlByte *lpData)
{
	VTFFile->SetThumbnailData(lpData);
}

VTFLIB_API vlBool vlImageGetSupportsResources(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetSupportsResources();
}

VTFLIB_API vlUInt vlImageGetResourceCount(const VTFLibVTFFile* VTFFile)
{
	return VTFFile->GetResourceCount();
}

VTFLIB_API vlUInt vlImageGetResourceType(const VTFLibVTFFile* VTFFile, vlUInt uiIndex)
{
	return VTFFile->GetResourceType(uiIndex);
}

VTFLIB_API vlBool vlImageGetHasResource(const VTFLibVTFFile* VTFFile, vlUInt uiType)
{
	return VTFFile->GetHasResource(uiType);
}

VTFLIB_API vlVoid *vlImageGetResourceData(const VTFLibVTFFile* VTFFile, vlUInt uiType, vlUInt *uiSize, VTFLibError* Error)
{
	return VTFFile->GetResourceData(uiType, *uiSize, *Error);
}

VTFLIB_API vlVoid *vlImageSetResourceData(VTFLibVTFFile* VTFFile, vlUInt uiType, vlUInt uiSize, vlVoid *lpData, VTFLibError* Error)
{
	return VTFFile->SetResourceData(uiType, uiSize, lpData, *Error);
}

VTFLIB_API vlBool vlImageGenerateMipmaps(VTFLibVTFFile* VTFFile, vlUInt uiFace, vlUInt uiFrame, VTFMipmapFilter MipmapFilter, VTFSharpenFilter SharpenFilter, VTFLibError* Error)
{
	return VTFFile->GenerateMipmaps(uiFace, uiFrame, *Error, MipmapFilter, SharpenFilter);
}

VTFLIB_API vlBool vlImageGenerateAllMipmaps(VTFLibVTFFile* VTFFile, VTFMipmapFilter MipmapFilter, VTFSharpenFilter SharpenFilter, VTFLibError* Error)
{
	return VTFFile->GenerateMipmaps(MipmapFilter, SharpenFilter, *Error);
}

VTFLIB_API vlBool vlImageGenerateThumbnail(VTFLibVTFFile* VTFFile, VTFLibError* Error)
{
	return VTFFile->GenerateThumbnail(*Error);
}

VTFLIB_API vlBool vlImageGenerateNormalMap(VTFLibVTFFile* VTFFile, vlUInt uiFrame, VTFKernelFilter KernelFilter, VTFHeightConversionMethod HeightConversionMethod, VTFNormalAlphaResult NormalAlphaResult, VTFLibError* Error)
{
	return VTFFile->GenerateNormalMap(uiFrame, *Error, KernelFilter, HeightConversionMethod, NormalAlphaResult);
}

VTFLIB_API vlBool vlImageGenerateAllNormalMaps(VTFLibVTFFile* VTFFile, VTFKernelFilter KernelFilter, VTFHeightConversionMethod HeightConversionMethod, VTFNormalAlphaResult NormalAlphaResult, VTFLibError* Error)
{
	return VTFFile->GenerateNormalMap(*Error, KernelFilter, HeightConversionMethod, NormalAlphaResult);
}

VTFLIB_API vlBool vlImageGenerateSphereMap(VTFLibVTFFile* VTFFile, VTFLibError* Error)
{
	return VTFFile->GenerateSphereMap(*Error);
}

VTFLIB_API vlBool vlImageComputeReflectivity(VTFLibVTFFile* VTFFile, VTFLibError* Error)
{
	return VTFFile->ComputeReflectivity(*Error);
}

VTFLIB_API SVTFImageFormatInfo const *vlImageGetImageFormatInfo(VTFImageFormat ImageFormat)
{
	return &CVTFFile::GetImageFormatInfo(ImageFormat);
}

VTFLIB_API vlBool vlImageGetImageFormatInfoEx(VTFImageFormat ImageFormat, SVTFImageFormatInfo *VTFImageFormatInfo)
{
	if(ImageFormat >= 0 && ImageFormat < IMAGE_FORMAT_COUNT)
	{
		memcpy(VTFImageFormatInfo, &CVTFFile::GetImageFormatInfo(ImageFormat), sizeof(SVTFImageFormatInfo));
		return vlTrue;
	}

	return vlFalse;
}

VTFLIB_API vlUInt vlImageComputeImageSize(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth, vlUInt uiMipmaps, VTFImageFormat ImageFormat)
{
	return CVTFFile::ComputeImageSize(uiWidth, uiHeight, uiDepth, uiMipmaps, ImageFormat);
}

VTFLIB_API vlUInt vlImageComputeMipmapCount(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth)
{
	return CVTFFile::ComputeMipmapCount(uiWidth, uiHeight, uiDepth);
}

VTFLIB_API vlVoid vlImageComputeMipmapDimensions(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth, vlUInt uiMipmapLevel, vlUInt *uiMipmapWidth, vlUInt *uiMipmapHeight, vlUInt *uiMipmapDepth)
{
	CVTFFile::ComputeMipmapDimensions(uiWidth, uiHeight, uiDepth, uiMipmapLevel, *uiMipmapWidth, *uiMipmapHeight, *uiMipmapDepth);
}

VTFLIB_API vlUInt vlImageComputeMipmapSize(vlUInt uiWidth, vlUInt uiHeight, vlUInt uiDepth, vlUInt uiMipmapLevel, VTFImageFormat ImageFormat)
{
	return CVTFFile::ComputeMipmapSize(uiWidth, uiHeight, uiDepth, uiMipmapLevel, ImageFormat);
}

VTFLIB_API vlBool vlImageConvertToRGBA8888(vlByte *lpSource, vlByte *lpDest, vlUInt uiWidth, vlUInt uiHeight, VTFImageFormat SourceFormat, VTFLibError* Error)
{
	return CVTFFile::ConvertToRGBA8888(lpSource, lpDest, uiWidth, uiHeight, SourceFormat, *Error);
}

VTFLIB_API vlBool vlImageConvertFromRGBA8888(vlByte *lpSource, vlByte *lpDest, vlUInt uiWidth, vlUInt uiHeight, VTFImageFormat DestFormat, VTFLibError* Error)
{
	return CVTFFile::ConvertFromRGBA8888(lpSource, lpDest, uiWidth, uiHeight, DestFormat, *Error);
}

VTFLIB_API vlBool vlImageConvert(vlByte *lpSource, vlByte *lpDest, vlUInt uiWidth, vlUInt uiHeight, VTFImageFormat SourceFormat, VTFImageFormat DestFormat, VTFLibError* Error)
{
	return CVTFFile::Convert(lpSource, lpDest, uiWidth, uiHeight, SourceFormat, DestFormat, *Error);
}

VTFLIB_API vlBool vlImageConvertToNormalMap(vlByte *lpSourceRGBA8888, vlByte *lpDestRGBA8888, vlUInt uiWidth, vlUInt uiHeight, VTFKernelFilter KernelFilter, VTFHeightConversionMethod HeightConversionMethod, VTFNormalAlphaResult NormalAlphaResult, vlByte bMinimumZ, vlSingle sScale, vlBool bWrap, vlBool bInvertX, vlBool bInvertY, VTFLibError* Error)
{
	return CVTFFile::ConvertToNormalMap(lpSourceRGBA8888, lpDestRGBA8888, uiWidth, uiHeight, *Error, KernelFilter, HeightConversionMethod, NormalAlphaResult, bMinimumZ, sScale, bWrap, bInvertX, bInvertY);
}

VTFLIB_API vlBool vlImageResize(vlByte *lpSourceRGBA8888, vlByte *lpDestRGBA8888, vlUInt uiSourceWidth, vlUInt uiSourceHeight, vlUInt uiDestWidth, vlUInt uiDestHeight, VTFMipmapFilter ResizeFilter, VTFSharpenFilter SharpenFilter, VTFLibError* Error)
{
	return CVTFFile::Resize(lpSourceRGBA8888, lpDestRGBA8888, uiSourceWidth, uiSourceHeight, uiDestWidth, uiDestHeight, *Error, ResizeFilter, SharpenFilter);
}

VTFLIB_API vlVoid vlImageCorrectImageGamma(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight, vlSingle sGammaCorrection)
{
	CVTFFile::CorrectImageGamma(lpImageDataRGBA8888, uiWidth, uiHeight, sGammaCorrection);
}

VTFLIB_API vlVoid vlImageComputeImageReflectivity(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight, vlSingle *sX, vlSingle *sY, vlSingle *sZ)
{
	CVTFFile::ComputeImageReflectivity(lpImageDataRGBA8888, uiWidth, uiHeight, *sX, *sY, *sZ);
}

VTFLIB_API vlVoid vlImageFlipImage(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight)
{
	CVTFFile::FlipImage(lpImageDataRGBA8888, uiWidth, uiHeight);
}

VTFLIB_API vlVoid vlImageMirrorImage(vlByte *lpImageDataRGBA8888, vlUInt uiWidth, vlUInt uiHeight)
{
	CVTFFile::FlipImage(lpImageDataRGBA8888, uiWidth, uiHeight);
}
