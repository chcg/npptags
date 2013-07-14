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

#include <windows.h>
#include "TagsDatabase.h"
using namespace std;

/////////////////////////////////////////////////////////////////////////////
//

TagsDatabase::TagsDatabase() : SqliteDatabase()
{
	SetValues();
}

TagsDatabase::TagsDatabase(LPCWSTR file) : SqliteDatabase(file)
{
	SetValues();
}

/////////////////////////////////////////////////////////////////////////////
//

void TagsDatabase::SetValues()
{
	_dbVersion = 1;
}

/////////////////////////////////////////////////////////////////////////////
//

bool TagsDatabase::Open()
{
	if (!SqliteDatabase::Open())
		return false;

	// If it is the same version as we generate, we're done
	int dbVersion = GetUserVersion();
	if (dbVersion == _dbVersion)
		return true;

	// Newly created database
	if (dbVersion == 0)
	{
		// Initialise the database
		if (Init())
			return true;

		_errorMsg = "Something went wrong initialising the SqliteDatabase!";
		Close();
		return false;
	}

	// Database is not the right version!
	_errorMsg = "Wrong SqliteDatabase version, please regenerate!";
	Close();
	return false;
}

/////////////////////////////////////////////////////////////////////////////
// Need to improve error handling!

bool TagsDatabase::Init()
{
	if (!BeginTransaction())
		return false;

	RunSQL("CREATE TABLE Tags(Idx INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, Tag TEXT NOT NULL, File TEXT NOT NULL, Line INTEGER, Pattern TEXT, Type TEXT, Language TEXT, MemberOf TEXT, MemberOfType INTEGER, Inherits TEXT, Signature TEXT, Access TEXT, Implementation TEXT, ThisFileOnly INTEGER, Unrecognized TEXT);");
	RunSQL("CREATE INDEX TagsName ON Tags(Tag);");
	RunSQL("CREATE INDEX TagsLangType ON Tags(Language, Type);");
	RunSQL("CREATE INDEX TagsType ON Tags(Type);");
	RunSQL("CREATE INDEX TagsLangMember ON Tags(Language, MemberOf);");
	CommitTransaction();

	// Set the schema version
	return SetUserVersion(_dbVersion);
}

/////////////////////////////////////////////////////////////////////////////
// To speed up the inserting

bool TagsDatabase::InsertPragmas()
{
	RunSQL("PRAGMA synchronous = OFF");
	RunSQL("PRAGMA count_changes = OFF");
	RunSQL("PRAGMA journal_mode = MEMORY");
	return RunSQL("PRAGMA temp_store = MEMORY");
}
