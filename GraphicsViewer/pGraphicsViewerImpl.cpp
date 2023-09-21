#include "pGraphicsViewerImpl.h"
#include <windows.h>
#include <QCoreApplication>
pGraphicsViewerImpl::pGraphicsViewerImpl(pGraphicsViewer *_impl)
	: impl(_impl),scene(new pGraphicsScene)
{

}

bool pGraphicsViewerImpl::InitItemFunc()
{
	QStringList DLLNames{ "pPolygonItem.dll","pRectItem.dll" };
	QStringList ItemNames{ "polygon","rectangle" };
	for (size_t i = 0; i < DLLNames.size(); i++)
	{
		//init item get func
		HMODULE hDll = LoadLibraryA((qApp->applicationDirPath() + "/" + DLLNames[i]).toLocal8Bit());
		if (hDll)
		{
			fGetItem getItem = (fGetItem)GetProcAddress(hDll, "ItemCreator");
			if (getItem)
			{
				mapItemFunc[ItemNames[i]] = getItem;
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
	}
	
	return true;
}
