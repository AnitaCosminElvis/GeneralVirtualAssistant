#ifndef VIRTUALASSISTANFACTORYMETHOD_H
#define VIRTUALASSISTANFACTORYMETHOD_H

#include "ivirtualassistant.h"
#include "Data/Enums.h"

class VirtualAssistantFactoryMethod
{
public:
    static IVirtualAssistant* CreateVirtualAssistant(E_VA_TYPE type);
};

#endif // VIRTUALASSISTANFACTORYMETHOD_H
