#ifndef COMMANDSINVOKERFACTORY_H
#define COMMANDSINVOKERFACTORY_H

#include "../Data/Enums.h"
#include "ICommandInvoker.h"
#include "ICommandInvokerFactory.h"

class InvokerFactoryCreator
{
public:
    static ICommandInvokerFactory* GetCommandInvokerFactory(E_VA_TYPE invokerFactoryType);

};

#endif // COMMANDSINVOKERFACTORY_H
