#ifndef STRUCTS_H
#define STRUCTS_H

#include "Enums.h"
#include "Defines.h"
#include <QString>



struct S_BASE_COMMAND_DATA
{
    int                                 cmdType;
    QString                             qsVerbCommand;
    QString                             qsResourceType;
    int                                 nMinWordCount;
};

struct S_CUSTOM_CMD_PFUNCTIONS{
    pInitialize*        Initialize = nullptr;
    pContainsCommand*   ContainsCommand = nullptr;
    pExecuteCommand*    ExecuteCommand = nullptr;
    pStopCommand*       StopCommand = nullptr;
    pGetCommandResult*  GetCommandResult = nullptr;
};

struct S_CUSTOM_CMD_LIB_DATA{
    QString                     libFilename;
    QString                     libFileDir;
    QString                     libAbsoluteFilePath;
    S_CUSTOM_CMD_PFUNCTIONS     customCmdPFunctions;
};

#endif // STRUCTS_H
