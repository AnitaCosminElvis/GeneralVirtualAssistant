#include "CommandsInvokerFactory.h"
#include "LocalCommandInvoker.h"
#include "WebCommandInvoker.h"

ICommandInvoker* CommandsInvokerFactory::CreateVACommand(E_COMMAND_INVOKER_TYPE commandInvokerType)
{
    switch(commandInvokerType){
        case E_COMMAND_INVOKER_TYPE::UNDEFINED: return nullptr;
        case E_COMMAND_INVOKER_TYPE::LOCAL: return new LocalCommandInvoker;
        case E_COMMAND_INVOKER_TYPE::WEB: return new WebCommandInvoker;
        default: return nullptr;
    }
}
