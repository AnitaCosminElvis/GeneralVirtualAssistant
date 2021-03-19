#include "VADefaultPlayVideoCommand.h"

VADefaultPlayVideoCommand::VADefaultPlayVideoCommand()
{
    m_BaseCmdData.qsVerbCommand = PLAY_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
    m_StdLocation = QStandardPaths::StandardLocation::MoviesLocation;
    m_BaseCmdData.cmdType = E_COMMAND_TYPE::PLAY_VID;
}

int VADefaultPlayVideoCommand::Initialize()
{
    return 1;
}
