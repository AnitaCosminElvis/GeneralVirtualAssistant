#ifndef WEBCOMMANDINVOKERFACTORY_H
#define WEBCOMMANDINVOKERFACTORY_H

#include "ICommandInvokerFactory.h"
#include "../Data/Enums.h"

class WebInvokerFactory : public ICommandInvokerFactory

{
public:
    ICommandInvoker * CreateCommandInvoker(E_COMMAND_INVOKER_TYPE type) override;
};

#endif // WEBCOMMANDINVOKERFACTORY_H
