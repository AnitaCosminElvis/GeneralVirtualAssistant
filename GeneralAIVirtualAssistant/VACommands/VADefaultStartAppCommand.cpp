#include "VADefaultStartAppCommand.h"

VADefaultStartAppCommand::VADefaultStartAppCommand()
{
    m_BaseCmdData.qsVerbCommand = START_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
    m_StdLocation = QStandardPaths::StandardLocation::ApplicationsLocation;
    m_BaseCmdData.cmdType = E_COMMAND_TYPE::START_APP;
}

int VADefaultStartAppCommand::Initialize()
{
    return 1;
}


