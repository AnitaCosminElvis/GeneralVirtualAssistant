#include "LocalInvokerFactory.h"
#include "LocalDefaultCommandInvoker.h"
#include "LocalCustomCommandInvoker.h"

ICommandInvoker *LocalInvokerFactory::CreateCommandInvoker(E_COMMAND_INVOKER_TYPE type)
{
    switch (type){
        case E_COMMAND_INVOKER_TYPE::LOCAL_DEFAULT: return new LocalDefaultCommandInvoker;
        case E_COMMAND_INVOKER_TYPE::LOCAL_CUSTOM: return new LocalCustomCommandInvoker;
        default: return nullptr;
    }
}
