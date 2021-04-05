#ifndef ICOMMANDINVOKERFACTORY_H
#define ICOMMANDINVOKERFACTORY_H

#include "ICommandInvoker.h"
#include "../Data/Enums.h"

class ICommandInvokerFactory
{
public:
    virtual ICommandInvoker* CreateCommandInvoker(E_COMMAND_INVOKER_TYPE type) = 0;

    virtual ~ICommandInvokerFactory() = default;

};

#endif // ICOMMANDINVOKERFACTORY_H
