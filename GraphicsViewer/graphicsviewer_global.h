#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(GRAPHICSVIEWER_LIB)
#  define GRAPHICSVIEWER_EXPORT Q_DECL_EXPORT
# else
#  define GRAPHICSVIEWER_EXPORT Q_DECL_IMPORT
# endif
#else
# define GRAPHICSVIEWER_EXPORT
#endif
