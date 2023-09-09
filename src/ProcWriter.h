/*
 * VTFLib
 * Copyright (C) 2005-2010 Neil Jedrzejewski & Ryan Gregg

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later
 * version.
 */

#ifndef VTFLIB_PROCWRITER_H
#define VTFLIB_PROCWRITER_H

#include "stdafx.h"
#include "Writer.h"
#include "Error.h"

namespace VTFLib
{
	namespace IO
	{
		namespace Writers
		{
			class CProcWriter : public IWriter
			{
			private:
				vlBool bOpened;
				vlVoid *pUserData;

			public:
				CProcWriter(vlVoid *pUserData);
				~CProcWriter();

			public:
				virtual vlBool Opened() const;

				virtual vlBool Open(VTFLib::Diagnostics::CError &Error);
				virtual vlVoid Close();

				virtual vlSSize GetStreamSize(VTFLib::Diagnostics::CError &Error) const;
				virtual vlSSize GetStreamPointer(VTFLib::Diagnostics::CError &Error) const;

				virtual vlSSize Seek(vlOffset lOffset, VLSeekMode uiMode, VTFLib::Diagnostics::CError &Error);

				virtual vlBool Write(vlChar cChar, VTFLib::Diagnostics::CError &Error);
				virtual vlSize Write(vlVoid *vData, vlSize uiBytes, VTFLib::Diagnostics::CError &Error);
			};
		}
	}
}

#endif
