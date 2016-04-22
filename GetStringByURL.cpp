//#include "StdAfx.h"
#include "GetStringByURL.h"
#include <afxinet.h>

std::wstring GetStringByURL( std::wstring url )
{
	CString html;
	CInternetSession session;
	CHttpFile * file = NULL;

	try
	{
		file = (CHttpFile *)session.OpenURL(url.c_str());
		if(file)
		{
			CString line;
			while(file->ReadString(line) != NULL)
			{
				html += line + "\n";
			}
			file->Close();
		}
	}
	catch (CInternetException* e)
	{
		e->Delete();
		html = "CInternet Exception";
	}
	file = NULL;
	session.Close();

	return html.GetBuffer(0);
}