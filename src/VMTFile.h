/*
 * VTFLib
 * Copyright (C) 2005-2010 Neil Jedrzejewski & Ryan Gregg

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later
 * version.
 */

#ifndef VTFLIB_VMTFILE_H
#define VTFLIB_VMTFILE_H

#include "stdafx.h"
#ifdef __cplusplus
#	include "Readers.h"
#	include "Writers.h"
#	include "VMTNodes.h"
#	include "Error.h"
#else
#	include "VMTNode.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

//! VMT parsing mode.
typedef enum tagVMTParseMode
{
	PARSE_MODE_STRICT = 0,
	PARSE_MODE_LOOSE,
	PARSE_MODE_COUNT
} VMTParseMode;

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

namespace VTFLib
{
	class VTFLIB_API CVMTFile
	{
	private:
		Nodes::CVMTGroupNode *Root;

	public:
		CVMTFile();
		CVMTFile(const CVMTFile &VMTFile);
		~CVMTFile();

	public:
		vlBool Create(const vlChar *cRoot);
		vlVoid Destroy();

		vlBool IsLoaded() const;

		vlBool Load(const vlChar *cFileName, VTFLib::Diagnostics::CError& Error);
		vlBool Load(const vlVoid *lpData, vlSize uiBufferSize, VTFLib::Diagnostics::CError& Error);
		vlBool Load(vlVoid *pUserData, VTFLib::Diagnostics::CError& Error);

		vlBool Save(const vlChar *cFileName, VTFLib::Diagnostics::CError& Error) const;
		vlBool Save(vlVoid *lpData, vlSize uiBufferSize, vlSize &uiSize, VTFLib::Diagnostics::CError& Error) const;
		vlBool Save(vlVoid *pUserData, VTFLib::Diagnostics::CError& Error) const;

	private:
		vlBool Load(IO::Readers::IReader *Reader, VTFLib::Diagnostics::CError& Error);
		vlBool Save(IO::Writers::IWriter *Writer, VTFLib::Diagnostics::CError& Error) const;

		//Nodes::CVMTNode *Load(IO::Readers::IReader *Reader, vlBool bInGroup);

		vlVoid Indent(IO::Writers::IWriter *Writer, vlUInt uiLevel, VTFLib::Diagnostics::CError& Error) const;
		vlVoid Save(IO::Writers::IWriter *Writer, Nodes::CVMTNode *Node, VTFLib::Diagnostics::CError& Error, vlUInt uiLevel = 0) const;

	public:
		Nodes::CVMTGroupNode *GetRoot() const;
	};
}

#endif

#endif
