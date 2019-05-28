//
//                 mxToolKit (c) 1999 by Mete Ciragan
//
// file:           mxFileDialog.cpp
// implementation: Win32 API
// last modified:  Mar 14 1999, Mete Ciragan
// copyright:      The programs and associated files contained in this
//                 distribution were developed by Mete Ciragan. The programs
//                 are not in the public domain, but they are freely
//                 distributable without licensing fees. These programs are
//                 provided without guarantee or warrantee expressed or
//                 implied.
//
#include <mx/mxFileDialog.h>
#include <mx/mxWindow.h>
#include <windows.h>
#include <commdlg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



static char sd_path[_MAX_PATH];



const char*
mxGetOpenFileName (mxWindow *parent, const char *path, const char *filter)
{
	char szPath[_MAX_PATH] = {0}, szFilter[_MAX_PATH] = {0};
	const char *pos;
	size_t len, i = 0;

	sd_path[0] = '\0';

	if (path)
		strcpy (szPath, path);

	if (filter)
	{
		while ((pos = strstr (filter, ";;")))
		{
			len = (pos - filter);
			pos = strchr (filter, '.') - 1;
			memcpy (&szFilter[i], filter, len);
			i += len + 1;
			filter += len + 2;
			memcpy (&szFilter[i], pos, strchr (pos, ')') - pos);
			i += 6;
	
		}
		len = strlen (filter);
                memcpy (&szFilter[i], filter, len);
                i += len + 1;
		pos = strchr (filter, '.') - 1;
                memcpy (&szFilter[i], pos, strchr (pos, ')') - pos);
	}

	OPENFILENAME ofn = {0};

	ofn.lStructSize = sizeof (ofn);
	if (parent)
		ofn.hwndOwner = (HWND) parent->getHandle ();
	ofn.hInstance = (HINSTANCE) GetModuleHandle (NULL);
	ofn.lpstrFilter = szFilter;
	ofn.lpstrFile = sd_path;
	ofn.nMaxFile = _MAX_PATH;
	if (path && strlen (path))
		ofn.lpstrInitialDir = szPath;
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;

	if (GetOpenFileName (&ofn))
		return sd_path;
	else
		return 0;
}



const char*
mxGetSaveFileName (mxWindow *parent, const char *path, const char *filter)
{
	char szPath[_MAX_PATH] = {0}, szFilter[_MAX_PATH] = {0};
	char *pos;
        size_t len, i = 0;

	sd_path[0] = '\0';

	if (path)
		strcpy (szPath, path);

	if (filter)
	{
		while ((pos = strstr (filter, ";;")))
		{
			len = (pos - filter);
			pos = strchr (filter, '.') - 1;
			memcpy (&szFilter[i], filter, len);
			i += len + 1;
			filter += len + 2;
			memcpy (&szFilter[i], pos, strchr (pos, ')') - pos);
			i += 6;
		}
		len = strlen(filter);
		memcpy (&szFilter[i], filter, len);
		i += len + 1;
		pos = strchr (filter, '.') - 1;
		memcpy (&szFilter[i], pos, strchr (pos, ')') - pos);
	}

	OPENFILENAME ofn = {0};

	ofn.lStructSize = sizeof (ofn);
	if (parent)
		ofn.hwndOwner = (HWND) parent->getHandle ();
	ofn.hInstance = (HINSTANCE) GetModuleHandle (NULL);
	ofn.lpstrFilter = szFilter;
	ofn.lpstrFile = sd_path;
	ofn.nMaxFile = _MAX_PATH;
	if (path && strlen (path))
		ofn.lpstrInitialDir = szPath;
	ofn.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;

	if (GetSaveFileName (&ofn))
		return sd_path;
	else
		return 0;
}
