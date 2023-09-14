#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PRECTITEM_LIB)
#  define PRECTITEM_EXPORT Q_DECL_EXPORT
# else
#  define PRECTITEM_EXPORT Q_DECL_IMPORT
# endif
#else
# define PRECTITEM_EXPORT
#endif
