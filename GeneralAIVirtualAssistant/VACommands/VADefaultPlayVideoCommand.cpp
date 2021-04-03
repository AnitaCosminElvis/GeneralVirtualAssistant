#include "VADefaultPlayVideoCommand.h"

VADefaultPlayVideoCommand::VADefaultPlayVideoCommand()
{
    U_LOCAL_COMMAND_TYPE cmdType;
    cmdType.command_type = E_LOCAL_COMMAND_TYPE::PLAY_VID;
    m_BaseCmdData.cmdType = cmdType.nVal;

    m_BaseCmdData.qsVerbCommand = PLAY_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
    m_StdLocation = QStandardPaths::StandardLocation::MoviesLocation;
}

int VADefaultPlayVideoCommand::Initialize()
{
    return 1;
}
