/*
 * VTFLib
 * Copyright (C) 2005-2010 Neil Jedrzejewski & Ryan Gregg

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later
 * version.
 */

#include "VTFLib.h"
#include "Proc.h"
#include "ProcWriter.h"

#include <limits>

using namespace VTFLib;
using namespace VTFLib::IO::Writers;

CProcWriter::CProcWriter(vlVoid *pUserData)
{
	this->bOpened = vlFalse;
	this->pUserData = pUserData;
}

CProcWriter::~CProcWriter()
{
	this->Close();
}

vlBool CProcWriter::Opened() const
{
	return this->bOpened;
}

vlBool CProcWriter::Open(VTFLibError &Error)
{
	this->Close();

	if(pWriteOpenProc == 0)
	{
		Error.Set("pWriteOpenProc not set.");
		return vlFalse;
	}

	if(this->bOpened)
	{
		Error.Set("Writer already open.");
		return vlFalse;
	}

	if(!pWriteOpenProc(this->pUserData))
	{
		Error.Set("Error opening file.");
		return vlFalse;
	}

	this->bOpened = vlTrue;

	return vlTrue;
}

vlVoid CProcWriter::Close()
{
	if(pWriteCloseProc == 0)
	{
		return;
	}

	if(this->bOpened)
	{
		pWriteCloseProc(this->pUserData);
		this->bOpened = vlFalse;
	}
}

vlSSize CProcWriter::GetStreamSize(VTFLibError &Error) const
{
	if(!this->bOpened)
	{
		return 0;
	}

	if(pWriteSizeProc == 0)
	{
		Error.Set("pWriteTellProc not set.");
		return (std::numeric_limits<vlSSize>::max)();
	}

	return pWriteSizeProc(this->pUserData);
}

vlSSize CProcWriter::GetStreamPointer(VTFLibError &Error) const
{
	if(!this->bOpened)
	{
		return 0;
	}

	if(pWriteTellProc == 0)
	{
		Error.Set("pWriteTellProc not set.");
		return 0;
	}

	return pWriteTellProc(this->pUserData);
}

vlSSize CProcWriter::Seek(vlOffset lOffset, VLSeekMode uiMode, VTFLibError &Error)
{
	if(!this->bOpened)
	{
		return 0;
	}

	if(pWriteSeekProc == 0)
	{
		Error.Set("pWriteSeekProc not set.");
		return 0;
	}

	return pWriteSeekProc(lOffset, (VLSeekMode)uiMode, this->pUserData);
}

vlBool CProcWriter::Write(vlChar cChar, VTFLibError &Error)
{
	if(!this->bOpened)
	{
		return vlFalse;
	}

	if(pWriteWriteProc == 0)
	{
		Error.Set("pWriteWriteProc not set.");
		return vlFalse;
	}

	vlSize uiBytesWritten = pWriteWriteProc(&cChar, 1, this->pUserData);

	if(uiBytesWritten == 0)
	{
		Error.Set("pWriteWriteProc() failed.");
	}

	return uiBytesWritten == 1;
}

vlSize CProcWriter::Write(vlVoid *vData, vlSize uiBytes, VTFLibError &Error)
{
	if(!this->bOpened)
	{
		return 0;
	}

	if(pWriteWriteProc == 0)
	{
		Error.Set("pWriteWriteProc not set.");
		return 0;
	}

	vlSize uiBytesWritten = pWriteWriteProc(vData, uiBytes, this->pUserData);

	if(uiBytesWritten == 0)
	{
		Error.Set("pWriteWriteProc() failed.");
	}

	return uiBytesWritten;
}
