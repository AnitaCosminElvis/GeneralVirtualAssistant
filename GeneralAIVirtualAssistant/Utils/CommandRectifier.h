#ifndef COMMANDRECTIFIER_H
#define COMMANDRECTIFIER_H

#include <QStringList>
#include "Data/Structs.h"

class CommandRectifier
{
public:

    static QStringList GetSanitizedCommand(const S_BASE_COMMAND_DATA& cmdData, const QString& input);
    static QStringList GetSanitizedCommandArgs(const S_BASE_COMMAND_DATA& cmdData, const QString& input);

};

#endif // COMMANDRECTIFIER_H
