#include "VADefaultStartAppCommand.h"

VADefaultStartAppCommand::VADefaultStartAppCommand()
{
    U_LOCAL_COMMAND_TYPE cmdType;
    cmdType.command_type = E_LOCAL_COMMAND_TYPE::START_APP;
    m_BaseCmdData.cmdType = cmdType.nVal;

    m_BaseCmdData.qsVerbCommand = START_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
    m_StdLocation = QStandardPaths::StandardLocation::ApplicationsLocation;
}

int VADefaultStartAppCommand::Initialize()
{
    return 1;
}


