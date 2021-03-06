/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//  NppTags - CTags plugin for Notepad++                                   //
//  Copyright (C) 2013 Frank Fesevur                                       //
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

#include "SqliteDB.h"

class TagsDatabase : public SqliteDatabase
{
public:
	TagsDatabase() noexcept;
	TagsDatabase(LPCWSTR file);

	void Open() override;
	void InsertPragmas();

	void Generate();
	void UpdateFilename();

protected:
	void Init();
	void SetValues() noexcept;

	void SetTagsFile(const WCHAR* tagsPath);
	bool GetTagsFilename(bool mustExist);
	bool GenerateTagsFile();
	bool ImportTags();

	int _dbVersion;				// The schema version
	std::string _tagsFile;		// The 'tags' filename
	std::wstring _curDir;		// The current directory
};
