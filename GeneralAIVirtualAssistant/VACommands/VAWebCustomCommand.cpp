#include "VAWebCustomCommand.h"
#include "../Data/Defines.h"

VAWebCustomCommand::VAWebCustomCommand()
{
    m_VAType = E_VA_TYPE::WEB;
    m_CmdType.webCmdType = E_WEB_COMMAND_TYPE::CUSTOM;
    m_LibData.libFileDir = CUSTOM_WEB_CMDS;
}
