#include "VAWebCustomCommand.h"
#include "../Data/Defines.h"

VAWebCustomCommand::VAWebCustomCommand()
{
    m_VAType = E_VA_TYPE::WEB;
    m_LibData.libFileDir = CUSTOM_WEB_CMDS;
}

int VAWebCustomCommand::GetCommandType()
{
    U_COMMAND_TYPE webCmdType;
    webCmdType.webCmdType = E_WEB_COMMAND_TYPE::CUSTOM;
    return webCmdType.nVal;
}
