#include "VALocalCustomCommand.h"

VALocalCustomCommand::VALocalCustomCommand()
{
    m_VAType = E_VA_TYPE::LOCAL;
    m_CmdType.localCmdType = E_LOCAL_COMMAND_TYPE::CUSTOM;
    m_LibData.libFileDir = CUSTOM_LOCAL_CMDS;
}
