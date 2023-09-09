/*
 * VTFLib
 * Copyright (C) 2005-2010 Neil Jedrzejewski & Ryan Gregg

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later
 * version.
 */

#include <sys/stat.h>

#include "../VTFLib.h"
#include "../FileReader.h"

using namespace VTFLib;
using namespace VTFLib::IO::Readers;

vlBool CFileReader::Open(VTFLibError& Error)
{
	this->Close();

	this->hFile = fopen(this->cFileName, "rb");

	if(this->hFile == NULL)
	{
		Error.Set("Error opening file.", vlTrue);

		return vlFalse;
	}

	return vlTrue;
}

vlVoid CFileReader::Close()
{
	if(this->hFile != NULL)
	{
		fclose(this->hFile);
		this->hFile = NULL;
	}
}

vlSSize CFileReader::GetStreamSize(VTFLibError& Error) const
{
	if(this->hFile == NULL)
	{
		return 0;
	}

	struct stat buf;

	if(fstat(fileno(this->hFile), &buf) != 0) {
		Error.Set("fstat() failed.", vlTrue);
		return 0;
	}

	return buf.st_size;
}

vlSSize CFileReader::GetStreamPointer(VTFLibError& Error) const
{
	if(this->hFile == NULL)
	{
		return 0;
	}

	vlOffset offset = ftello(this->hFile);
	if(offset < 0)
	{
		Error.Set("ftello() failed.", vlTrue);
		return 0;
	}

	return offset;
}

vlSSize CFileReader::Seek(vlOffset lOffset, VLSeekMode uiMode, VTFLibError& Error)
{
	if(this->hFile == NULL)
	{
		return 0;
	}

	if(fseeko(this->hFile, lOffset, uiMode) != 0) {
		Error.Set("fseeko() failed.", vlTrue);
		return 0;
	}
	return GetStreamPointer(Error);
}

vlBool CFileReader::Read(vlChar &cChar, VTFLibError& Error)
{
	if(this->hFile == NULL)
	{
		return vlFalse;
	}
	
	int byte = fgetc(this->hFile);

	if(byte == EOF)
	{
		Error.Set("fgetc() failed.", vlTrue);
		return vlFalse;
	}
	else
	{
		cChar = (vlChar)byte;
		return vlTrue;
	}
}

vlSize CFileReader::Read(vlVoid *vData, vlSize uiBytes, VTFLibError& Error)
{
	if(this->hFile == NULL)
	{
		return 0;
	}

	if(fread(vData, uiBytes, 1, this->hFile) != 1 && ferror(this->hFile))
	{
		Error.Set("fread() failed.", vlTrue);
		return 0;
	}
	else
	{
		return uiBytes;
	}
}
