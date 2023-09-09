/*
 * VTFLib
 * Copyright (C) 2005-2010 Neil Jedrzejewski & Ryan Gregg

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later
 * version.
 */

#ifndef VTFLIB_WRITER_H
#define VTFLIB_WRITER_H

#include "stdafx.h"
#include "Error.h"

namespace VTFLib
{
	namespace IO
	{
		namespace Writers
		{
			class IWriter
			{
			public:
				virtual ~IWriter() {}
				virtual vlBool Opened() const = 0;

				virtual vlBool Open(VTFLib::Diagnostics::CError &Error) = 0;
				virtual vlVoid Close() = 0;

				virtual vlSSize GetStreamSize(VTFLib::Diagnostics::CError &Error) const = 0;
				virtual vlSSize GetStreamPointer(VTFLib::Diagnostics::CError &Error) const = 0;

				virtual vlSSize Seek(vlOffset lOffset, VLSeekMode uiMode, VTFLib::Diagnostics::CError &Error) = 0;

				virtual vlBool Write(vlChar cChar, VTFLib::Diagnostics::CError &Error) = 0;
				virtual vlSize Write(vlVoid *vData, vlSize uiBytes, VTFLib::Diagnostics::CError &Error) = 0;
			};
		}
	}
}

#endif
