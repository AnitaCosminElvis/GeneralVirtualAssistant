#include "VADefaultPlayVideoCommand.h"

VADefaultPlayVideoCommand::VADefaultPlayVideoCommand()
{
    U_COMMAND_TYPE cmdType;
    cmdType.localCmdType = E_LOCAL_COMMAND_TYPE::PLAY_VID;
    m_BaseCmdData.cmdType = cmdType.nVal;

    m_BaseCmdData.qsVerbCommand = PLAY_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE_VID;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
    m_StdLocation = QStandardPaths::StandardLocation::MoviesLocation;
}

int VADefaultPlayVideoCommand::Initialize(const std::string &)
{
    return 1;
}
