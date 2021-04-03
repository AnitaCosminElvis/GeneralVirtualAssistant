#include "WebCommandInvoker.h"
#include "../Data/Enums.h"
#include "VACommandsFactory.h"

WebCommandInvoker::WebCommandInvoker()
{

}

WebCommandInvoker::~WebCommandInvoker()
{

}

int WebCommandInvoker::Initialize()
{
    U_WEB_COMMAND_TYPE uCmdCount;
    U_WEB_COMMAND_TYPE uCmdType;

    uCmdCount.command_type = E_WEB_COMMAND_TYPE::COUNT;

    for (uCmdType.nVal = 1; uCmdType.nVal < uCmdCount.nVal; ++uCmdType.nVal)
    {
        std::unique_ptr<IVACommand> command;
        command.reset(VACommandsFactory::CreateVACommand(E_COMMAND_INVOKER_TYPE::WEB, uCmdType.nVal));
        m_DefaultCommands[uCmdType.nVal] = std::move(command);
        m_DefaultCommands[uCmdType.nVal]->Initialize();
    }

    return 1;
}

int WebCommandInvoker::IsCommand(const std::string &input)
{
    U_WEB_COMMAND_TYPE uCmdType;
    uCmdType.command_type = E_WEB_COMMAND_TYPE::UNDEFINED;

    for(auto& command: m_DefaultCommands)
    {
        if (command.second->ContainsCommand(input)){
            uCmdType.nVal = command.second->GetCommandType();
            return uCmdType.nVal;
        }
    }

    return uCmdType.nVal;
}

bool WebCommandInvoker::ExecuteCommand(const std::string &input, int cmdType)
{
    U_LOCAL_COMMAND_TYPE uCmdType;
    uCmdType.nVal = cmdType;

    if (E_LOCAL_COMMAND_TYPE::UNDEFINED == uCmdType.command_type) return false;

    if (E_LOCAL_COMMAND_TYPE::CUSTOM != uCmdType.command_type)
    {
        return m_DefaultCommands[uCmdType.nVal]->ExecuteCommand(input);
    }else{
        //TO DO - CUSTOM COMMAND
        return false;
    }
}

bool WebCommandInvoker::StopCommand(int cmdType)
{
    U_LOCAL_COMMAND_TYPE uCmdType;
    uCmdType.nVal = cmdType;

    if (E_LOCAL_COMMAND_TYPE::UNDEFINED == uCmdType.command_type) return false;

    if (E_LOCAL_COMMAND_TYPE::CUSTOM != uCmdType.command_type)
    {
        return m_DefaultCommands[uCmdType.nVal]->StopCommand();
    }else{
        //TO DO - CUSTOM COMMAND
        return false;
    }
}

std::list<std::string> WebCommandInvoker::GetResult(int cmdType)
{
    U_LOCAL_COMMAND_TYPE uCmdType;
    uCmdType.nVal = cmdType;

    return m_DefaultCommands[uCmdType.nVal]->GetCommandResult();
}
