#include "WebDefaultCommandInvoker.h"
#include "../Data/Enums.h"
#include "VACommandsFactory.h"


int WebDefaultCommandInvoker::Initialize()
{
    U_COMMAND_TYPE uCmdCount;
    U_COMMAND_TYPE uCmdType;

    uCmdCount.webCmdType = E_WEB_COMMAND_TYPE::COUNT;

    for (uCmdType.nVal = 1; uCmdType.nVal < uCmdCount.nVal; ++uCmdType.nVal)
    {
        std::shared_ptr<IVACommand> command;
        command.reset(VACommandsFactory::CreateVACommand(E_VA_TYPE::WEB, uCmdType.nVal));

        if (!command || !command->Initialize()) return 0;
        m_DefaultCommands[uCmdType.nVal] = command;
    }

    return 1;
}

int WebDefaultCommandInvoker::IsCommand(const std::string &input)
{
    U_COMMAND_TYPE uCmdType;
    uCmdType.webCmdType = E_WEB_COMMAND_TYPE::UNDEFINED;

    for(auto command: m_DefaultCommands)
    {
        if (command.second->ContainsCommand(input)){
            uCmdType.nVal = command.second->GetCommandType();
            return uCmdType.nVal;
        }
    }

    return uCmdType.nVal;
}

bool WebDefaultCommandInvoker::ExecuteCommand(const std::string &input, int cmdType)
{
    U_COMMAND_TYPE uCmdType;
    uCmdType.nVal = cmdType;

    if (E_WEB_COMMAND_TYPE::UNDEFINED == uCmdType.webCmdType) return false;

    if (E_WEB_COMMAND_TYPE::CUSTOM != uCmdType.webCmdType)
    {
        return m_DefaultCommands[uCmdType.nVal]->ExecuteCommand(input);
    }else{
        //TO DO - CUSTOM COMMAND
        return false;
    }
}

bool WebDefaultCommandInvoker::StopCommand(int cmdType)
{
    U_COMMAND_TYPE uCmdType;
    uCmdType.nVal = cmdType;

    if (E_WEB_COMMAND_TYPE::UNDEFINED == uCmdType.webCmdType) return false;

    return m_DefaultCommands[uCmdType.nVal]->StopCommand();
}

std::string WebDefaultCommandInvoker::GetResult(int cmdType)
{
    return m_DefaultCommands[cmdType]->GetCommandResult();
}
