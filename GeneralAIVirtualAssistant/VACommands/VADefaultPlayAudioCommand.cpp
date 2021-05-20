#include "VADefaultPlayAudioCommand.h"

VADefaultPlayAudioCommand::VADefaultPlayAudioCommand()
{
    U_COMMAND_TYPE cmdType;
    cmdType.localCmdType = E_LOCAL_COMMAND_TYPE::PLAY_AUD;
    m_BaseCmdData.cmdType = cmdType.nVal;

    m_BaseCmdData.qsVerbCommand = PLAY_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE_AUD;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
    m_StdLocation = QStandardPaths::StandardLocation::MusicLocation;
}

int VADefaultPlayAudioCommand::Initialize(const std::string&)
{
    return 1;
}
