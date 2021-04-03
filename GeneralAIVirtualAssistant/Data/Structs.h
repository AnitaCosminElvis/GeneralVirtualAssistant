#ifndef STRUCTS_H
#define STRUCTS_H

#include "Enums.h"

#include <QString>

struct S_BASE_COMMAND_DATA
{
    int                                 cmdType;
    QString                             qsVerbCommand;
    QString                             qsResourceType;
    int                                 nMinWordCount;
};

#endif // STRUCTS_H
