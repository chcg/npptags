/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//  NppTags - CTags plugin for Notepad++                                   //
//  Copyright (C) 2013-2015 Frank Fesevur                                  //
//                                                                         //
//  This program is free software; you can redistribute it and/or modify   //
//  it under the terms of the GNU General Public License as published by   //
//  the Free Software Foundation; either version 2 of the License, or      //
//  (at your option) any later version.                                    //
//                                                                         //
//  This program is distributed in the hope that it will be useful,        //
//  but WITHOUT ANY WARRANTY; without even the implied warranty of         //
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           //
//  GNU General Public License for more details.                           //
//                                                                         //
//  You should have received a copy of the GNU General Public License      //
//  along with this program; if not, write to the Free Software            //
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>

/////////////////////////////////////////////////////////////////////////////
//

class NppOptions
{
public:
	NppOptions() noexcept;

protected:
	bool GetBool(const WCHAR* szAppName, const WCHAR* szKeyName, const bool def) noexcept;
	int GetInt(const WCHAR* szAppName, const WCHAR* szKeyName, const int def) noexcept;
	std::wstring GetString(const WCHAR* szAppName, const WCHAR* szKeyName, const WCHAR* def) noexcept;

	void WriteBool(const WCHAR* szAppName, const WCHAR* szKeyName, const bool val) noexcept;
	void WriteInt(const WCHAR* szAppName, const WCHAR* szKeyName, const int val) noexcept;
	void WriteString(const WCHAR* szAppName, const WCHAR* szKeyName, const WCHAR* val) noexcept;

	std::wstring _IniPath;
};
