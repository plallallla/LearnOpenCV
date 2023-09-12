#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PPOLYGONITEM_LIB)
#  define PPOLYGONITEM_EXPORT Q_DECL_EXPORT
# else
#  define PPOLYGONITEM_EXPORT Q_DECL_IMPORT
# endif
#else
# define PPOLYGONITEM_EXPORT
#endif
