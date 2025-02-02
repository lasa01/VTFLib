/*
 * VTFLib
 * Copyright (C) 2005-2010 Neil Jedrzejewski & Ryan Gregg

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later
 * version.
 */

#ifndef VTFLIB_MEMORYREADER_H
#define VTFLIB_MEMORYREADER_H

#include "stdafx.h"
#include "Reader.h"
#include "Error.h"

namespace VTFLib
{
	namespace IO
	{
		namespace Readers
		{
			class CMemoryReader : public IReader
			{
			private:
				vlBool bOpened;

				const vlVoid *vData;
				vlSize uiBufferSize;

				vlSize uiPointer;

			public:
				CMemoryReader(const vlVoid *vData, vlSize uiBufferSize);
				~CMemoryReader();

			public:
				virtual vlBool Opened() const;

				virtual vlBool Open(VTFLib::Diagnostics::CError &Error);
				virtual vlVoid Close();

				virtual vlSSize GetStreamSize(VTFLib::Diagnostics::CError &Error) const;
				virtual vlSSize GetStreamPointer(VTFLib::Diagnostics::CError &Error) const;

				virtual vlSSize Seek(vlOffset lOffset, VLSeekMode uiMode, VTFLib::Diagnostics::CError &Error);

				virtual vlBool Read(vlChar &cChar, VTFLib::Diagnostics::CError &Error);
				virtual vlSize Read(vlVoid *vData, vlSize uiBytes, VTFLib::Diagnostics::CError &Error);
			};
		}
	}
}

#endif
