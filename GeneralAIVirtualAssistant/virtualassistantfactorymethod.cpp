#include "virtualassistantfactorymethod.h"
#include "LocalVA/localvirtualassistant.h"
#include "WebVA/webvirtualassistant.h"

IVirtualAssistant* VirtualAssistantFactoryMethod::CreateVirtualAssistant(E_VA_TYPE type)
{
    switch (type){
        case E_VA_TYPE::LOCAL: return new LocalVirtualAssistant();
        case E_VA_TYPE::WEB: return new WebVirtualAssistant();
        default: return nullptr;
    }
}

