#ifndef FACTORY_GLOBAL_H
#define FACTORY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FACTORY_LIBRARY)
#  define FACTORY_EXPORT Q_DECL_EXPORT
#else
#  define FACTORY_EXPORT Q_DECL_IMPORT
#endif

#endif // FACTORY_GLOBAL_H
