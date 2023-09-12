#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PABSTRACTITEM_LIB)
#  define PABSTRACTITEM_EXPORT Q_DECL_EXPORT
# else
#  define PABSTRACTITEM_EXPORT Q_DECL_IMPORT
# endif
#else
# define PABSTRACTITEM_EXPORT
#endif
