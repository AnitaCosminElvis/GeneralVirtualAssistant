#ifndef VADEFAULTCOMMANDS_H
#define VADEFAULTCOMMANDS_H

#define START_COMMAND   "start"
#define RESOURCE_TYPE   "app"
#define MIN_WORD_COUNT  3

#include "../Data/Enums.h"
#include "VAAbstractResourceFileCommand.h"

class VADefaultStartAppCommand: public VAAbstractResourceFileCommand
{
public:
    VADefaultStartAppCommand();

    int Initialize(const std::string& = "") override;
};

#endif // VADEFAULTCOMMANDS_H
