#ifndef VACOMMANDSFACTORY_H
#define VACOMMANDSFACTORY_H

#include "IVACommand.h"
#include "../Data/Enums.h"

class VACommandsFactory{
public:
    static IVACommand* CreateVACommand(E_COMMAND_TYPE commandType);
};
#endif // VACOMMANDSFACTORY_H
