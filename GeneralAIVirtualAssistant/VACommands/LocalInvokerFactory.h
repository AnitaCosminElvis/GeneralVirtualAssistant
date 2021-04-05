#ifndef LOCALCOMMANDINVOKERFACTORY_H
#define LOCALCOMMANDINVOKERFACTORY_H

#include "ICommandInvokerFactory.h"

class LocalInvokerFactory: public ICommandInvokerFactory
{
public:
    ICommandInvoker * CreateCommandInvoker(E_COMMAND_INVOKER_TYPE type) override;
};

#endif // LOCALCOMMANDINVOKERFACTORY_H
