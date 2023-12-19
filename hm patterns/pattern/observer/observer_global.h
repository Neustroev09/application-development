#ifndef OBSERVER_GLOBAL_H
#define OBSERVER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(OBSERVER_LIBRARY)
#  define OBSERVER_EXPORT Q_DECL_EXPORT
#else
#  define OBSERVER_EXPORT Q_DECL_IMPORT
#endif

#endif // OBSERVER_GLOBAL_H
