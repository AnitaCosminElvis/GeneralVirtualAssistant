#include "CommandInvoker.h"
#include "../Data/Enums.h"
#include "VACommandsFactory.h"

CommandInvoker::CommandInvoker()
{

}

int CommandInvoker::Initialize()
{
    U_COMMAND_TYPE uCmdCount;
    U_COMMAND_TYPE uCmdType;

    uCmdCount.command_type = E_COMMAND_TYPE::COUNT;

    for (uCmdType.nVal = 1; uCmdType.nVal < uCmdCount.nVal; ++uCmdType.nVal)
    {
        std::unique_ptr<IVACommand> command;
        command.reset(VACommandsFactory::CreateVACommand(uCmdType.command_type));
        m_DefaultCommands[uCmdType.nVal] = std::move(command);
        m_DefaultCommands[uCmdType.nVal]->Initialize();
    }

    return 1;
}

E_COMMAND_TYPE CommandInvoker::IsCommand(const std::string &input)
{
    for(auto& command: m_DefaultCommands)
    {
        if (command.second->ContainsCommand(input)) return command.second->GetCommandType();
    }

    return E_COMMAND_TYPE::UNDEFINED;
}

bool CommandInvoker::ExecuteCommand(const std::string &input, E_COMMAND_TYPE cmdType)
{
    if (E_COMMAND_TYPE::UNDEFINED == cmdType) return false;

    U_COMMAND_TYPE uCmdType;
    uCmdType.command_type = cmdType;

    if (E_COMMAND_TYPE::CUSTOM != cmdType)
    {
        return m_DefaultCommands[uCmdType.nVal]->ExecuteCommand(input);
    }else{
        //TO DO - CUSTOM COMMAND
        return false;
    }
}

bool CommandInvoker::StopCommand(E_COMMAND_TYPE cmdType)
{
    if (E_COMMAND_TYPE::UNDEFINED == cmdType) return false;

    U_COMMAND_TYPE uCmdType;
    uCmdType.command_type = cmdType;

    if (E_COMMAND_TYPE::CUSTOM != cmdType)
    {
        return m_DefaultCommands[uCmdType.nVal]->StopCommand();
    }else{
        //TO DO - CUSTOM COMMAND
        return false;
    }
}

std::list<std::string> CommandInvoker::GetResult(E_COMMAND_TYPE cmdType)
{
    U_COMMAND_TYPE uCmdType;
    uCmdType.command_type = cmdType;

    return m_DefaultCommands[uCmdType.nVal]->GetCommandResult();
}
