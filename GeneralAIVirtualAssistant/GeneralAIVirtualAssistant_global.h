#ifndef GENERALAIVIRTUALASSISTANT_GLOBAL_H
#define GENERALAIVIRTUALASSISTANT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GENERALAIVIRTUALASSISTANT_LIBRARY)
#  define GENERALAIVIRTUALASSISTANT_EXPORT Q_DECL_EXPORT
#else
#  define GENERALAIVIRTUALASSISTANT_EXPORT Q_DECL_IMPORT
#endif

#endif // GENERALAIVIRTUALASSISTANT_GLOBAL_H