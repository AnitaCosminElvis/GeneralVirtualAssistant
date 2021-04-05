#include "VALocalCustomCommand.h"

VALocalCustomCommand::VALocalCustomCommand()
{
    m_VAType = E_VA_TYPE::LOCAL;
    m_LibData.libFileDir = CUSTOM_LOCAL_CMDS;
}

int VALocalCustomCommand::GetCommandType()
{
    U_COMMAND_TYPE localCmdType;
    localCmdType.localCmdType = E_LOCAL_COMMAND_TYPE::CUSTOM;
    return localCmdType.nVal;
}
