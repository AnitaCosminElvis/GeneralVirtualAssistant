#include "VADefaultStartAppCommand.h"

VADefaultStartAppCommand::VADefaultStartAppCommand()
{
    U_COMMAND_TYPE cmdType;
    cmdType.localCmdType = E_LOCAL_COMMAND_TYPE::START_APP;
    m_BaseCmdData.cmdType = cmdType.nVal;

    m_BaseCmdData.qsVerbCommand = START_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
    m_StdLocation = QStandardPaths::StandardLocation::ApplicationsLocation;
}

int VADefaultStartAppCommand::Initialize(const std::string &)
{
    return 1;
}


