#include "pGraphicsViewerImpl.h"
#include <windows.h>
#include <QCoreApplication>
pGraphicsViewerImpl::pGraphicsViewerImpl(pGraphicsViewer *_impl)
	: impl(_impl),scene(new pGraphicsScene)
{

}

bool pGraphicsViewerImpl::InitItemFunc()
{
	QString DLLName{ "pPolygonItem.dll" };
	QString ItemName{ "polygon" };
	//init item get func
	HMODULE hDll = LoadLibraryA((qApp->applicationDirPath() + "/" + DLLName).toLocal8Bit());
	if (hDll)
	{
		fGetItem getItem = (fGetItem)GetProcAddress(hDll, "ItemCreator");
		if (getItem)
		{
			mapItemFunc[ItemName] = getItem;
		}
		else
		{
			//error:wrong dll context
			return false;
		}
	}
	else
	{
		//error:wrong dll name
		return false;
	}
	return true;
}
