#include "VADefaultPlayAudioCommand.h"

VADefaultPlayAudioCommand::VADefaultPlayAudioCommand()
{
    m_BaseCmdData.qsVerbCommand = PLAY_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
    m_BaseCmdData.cmdType = E_COMMAND_TYPE::PLAY_AUD;
    m_StdLocation = QStandardPaths::StandardLocation::MusicLocation;
}

int VADefaultPlayAudioCommand::Initialize()
{
    return 1;
}
