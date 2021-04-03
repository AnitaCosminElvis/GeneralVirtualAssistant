#ifndef COMMANDSINVOKERFACTORY_H
#define COMMANDSINVOKERFACTORY_H

#include "../Data/Enums.h"
#include "ICommandInvoker.h"

class CommandsInvokerFactory
{
public:
    static ICommandInvoker* CreateVACommand(E_COMMAND_INVOKER_TYPE commandInvokerType);

};

#endif // COMMANDSINVOKERFACTORY_H
