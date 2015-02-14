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

#ifndef __NPPOPTIONS_H__
#define __NPPOPTIONS_H__

/////////////////////////////////////////////////////////////////////////////
//

class NppOptions
{
public:
	NppOptions();

protected:
	bool GetBool(WCHAR* szAppName, WCHAR* szKeyName, bool def);
	int GetInt(WCHAR* szAppName, WCHAR* szKeyName, int def);
	void GetString(WCHAR* szAppName, WCHAR* szKeyName, WCHAR* szReturnedString, DWORD nSize, WCHAR* def);

	void WriteBool(WCHAR* szAppName, WCHAR* szKeyName, bool val);
	void WriteInt(WCHAR* szAppName, WCHAR* szKeyName, int val);
	void WriteString(WCHAR* szAppName, WCHAR* szKeyName, WCHAR* val);

	WCHAR _szIniPath[MAX_PATH];
};

#endif // __NPPOPTIONS_H__
