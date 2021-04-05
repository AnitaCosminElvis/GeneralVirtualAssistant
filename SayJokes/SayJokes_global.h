#ifndef SAYJOKES_GLOBAL_H
#define SAYJOKES_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SAYJOKES_LIBRARY)
#  define SAYJOKES_EXPORT Q_DECL_EXPORT
#else
#  define SAYJOKES_EXPORT Q_DECL_IMPORT
#endif

#endif // SAYJOKES_GLOBAL_H
