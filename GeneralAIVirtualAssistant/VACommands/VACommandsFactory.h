#ifndef VACOMMANDSFACTORY_H
#define VACOMMANDSFACTORY_H

#include "IVACommand.h"
#include "../Data/Enums.h"

class VACommandsFactory{
public:
    static IVACommand* CreateVACommand(E_COMMAND_INVOKER_TYPE invokerType, int commandType);
};
#endif // VACOMMANDSFACTORY_H
