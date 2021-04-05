#ifndef SIMONSAYS_GLOBAL_H
#define SIMONSAYS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIMONSAYS_LIBRARY)
#  define SIMONSAYS_EXPORT Q_DECL_EXPORT
#else
#  define SIMONSAYS_EXPORT Q_DECL_IMPORT
#endif

#endif // SIMONSAYS_GLOBAL_H
