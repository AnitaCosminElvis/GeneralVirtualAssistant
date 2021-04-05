#include "WebInvokerFactory.h"
#include "WebDefaultCommandInvoker.h"
#include "WebCustomCommandInvoker.h"


ICommandInvoker *WebInvokerFactory::CreateCommandInvoker(E_COMMAND_INVOKER_TYPE type)
{
    switch (type){
        case E_COMMAND_INVOKER_TYPE::WEB_DEFAULT: return new WebDefaultCommandInvoker;
        case E_COMMAND_INVOKER_TYPE::WEB_CUSTOM: return new WebCustomCommandInvoker;
        default: return nullptr;
    }

}

