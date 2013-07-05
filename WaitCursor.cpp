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
#include "WaitCursor.h"

/////////////////////////////////////////////////////////////////////////////
//

WaitCursor::WaitCursor(bool show)
{
	_OldCursor = NULL;
	if (show)
		Show();
}

WaitCursor::~WaitCursor()
{
	Hide();
}

/////////////////////////////////////////////////////////////////////////////
//

void WaitCursor::Show()
{
	if (_OldCursor == NULL)
		_OldCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));
}

/////////////////////////////////////////////////////////////////////////////
//

void WaitCursor::Hide()
{
	if (_OldCursor != NULL)
	{
		SetCursor(_OldCursor);
		_OldCursor = NULL;
	}
}
