#include "InvokerFactoryCreator.h"
#include "LocalInvokerFactory.h"
#include "WebInvokerFactory.h"


ICommandInvokerFactory* InvokerFactoryCreator::GetCommandInvokerFactory(E_VA_TYPE invokerFactoryType)
{
    switch(invokerFactoryType){
        case E_VA_TYPE::LOCAL: return new LocalInvokerFactory;
        case E_VA_TYPE::WEB: return new WebInvokerFactory;
        default: return nullptr;
    }
}
