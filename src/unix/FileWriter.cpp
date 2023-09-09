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
#include "../FileWriter.h"

using namespace VTFLib;
using namespace VTFLib::IO::Writers;

vlBool CFileWriter::Open(VTFLibError& Error)
{
	this->Close();

	this->hFile = fopen(this->cFileName, "wb");

	if(this->hFile == NULL)
	{
		Error.Set("Error opening file.", vlTrue);

		return vlFalse;
	}

	return vlTrue;
}

vlVoid CFileWriter::Close()
{
	if(this->hFile != NULL)
	{
		fclose(this->hFile);
		this->hFile = NULL;
	}
}

vlSSize CFileWriter::GetStreamSize(VTFLibError& Error) const
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

vlSSize CFileWriter::GetStreamPointer(VTFLibError& Error) const
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

vlSSize CFileWriter::Seek(vlOffset lOffset, VLSeekMode uiMode, VTFLibError& Error)
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

vlBool CFileWriter::Write(vlChar cChar, VTFLibError& Error)
{
	if(this->hFile == NULL)
	{
		return vlFalse;
	}

	if(fputc(cChar, this->hFile) == EOF)
	{
		Error.Set("fputc() failed.", vlTrue);
		return vlFalse;
	}
	else
	{
		return vlTrue;
	}
}

vlSize CFileWriter::Write(vlVoid *vData, vlSize uiBytes, VTFLibError& Error)
{
	if(this->hFile == NULL)
	{
		return 0;
	}

	if (fwrite(vData, uiBytes, 1, this->hFile) != 1 && ferror(this->hFile))
	{
		Error.Set("fwrite() failed.", vlTrue);
		return 0;
	}
	else
	{
		return uiBytes;
	}
}
