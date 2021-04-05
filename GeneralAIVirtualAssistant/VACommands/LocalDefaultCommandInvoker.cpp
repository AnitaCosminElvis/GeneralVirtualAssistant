#include "LocalDefaultCommandInvoker.h"
#include "../Data/Enums.h"
#include "../Data/Defines.h"
#include "VACommandsFactory.h"

#include <QDir>

int LocalDefaultCommandInvoker::Initialize()
{
    U_COMMAND_TYPE uCmdCount;
    U_COMMAND_TYPE uCmdType;

    uCmdCount.localCmdType = E_LOCAL_COMMAND_TYPE::COUNT;

    for (uCmdType.nVal = 1; uCmdType.nVal < uCmdCount.nVal; ++uCmdType.nVal)
    {
        std::shared_ptr<IVACommand> command;
        command.reset(VACommandsFactory::CreateVACommand(E_VA_TYPE::LOCAL, uCmdType.nVal));
        if (!command || !command->Initialize()) return 0;
        m_DefaultCommands[uCmdType.nVal] = command;
    }

    return 1;
}

int LocalDefaultCommandInvoker::IsCommand(const std::string &input)
{
    U_COMMAND_TYPE uCmdType;
    uCmdType.localCmdType = E_LOCAL_COMMAND_TYPE::UNDEFINED;

    for(auto command: m_DefaultCommands)
    {
        if (command.second->ContainsCommand(input)){
            uCmdType.nVal = command.second->GetCommandType();
            return uCmdType.nVal;
        }
    }

    return uCmdType.nVal;
}

bool LocalDefaultCommandInvoker::ExecuteCommand(const std::string &input, int cmdType)
{
    U_COMMAND_TYPE uCmdType;
    uCmdType.nVal = cmdType;

    if (E_LOCAL_COMMAND_TYPE::UNDEFINED == uCmdType.localCmdType) return false;

    return m_DefaultCommands[uCmdType.nVal]->ExecuteCommand(input);
}

bool LocalDefaultCommandInvoker::StopCommand(int cmdType)
{
    U_COMMAND_TYPE uCmdType;
    uCmdType.nVal = cmdType;

    if (E_LOCAL_COMMAND_TYPE::UNDEFINED == uCmdType.localCmdType) return false;

    return m_DefaultCommands[uCmdType.nVal]->StopCommand();

}

std::string LocalDefaultCommandInvoker::GetResult(int cmdType)
{
    return m_DefaultCommands[cmdType]->GetCommandResult();
}
