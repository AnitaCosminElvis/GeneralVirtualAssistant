#ifndef VADEFAULTCOMMANDS_H
#define VADEFAULTCOMMANDS_H

#define START_COMMAND       "launch"
#define RESOURCE_TYPE_APP   "app"
#define MIN_WORD_COUNT      2

#include "../Data/Enums.h"
#include "VAAbstractResourceFileCommand.h"

class VADefaultStartAppCommand: public VAAbstractResourceFileCommand
{
public:
    VADefaultStartAppCommand();

    int Initialize(const std::string& = "") override;
};

#endif // VADEFAULTCOMMANDS_H
