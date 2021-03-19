#include "VADefaultViewPictureCommand.h"

VADefaultViewPictureCommand::VADefaultViewPictureCommand()
{
    m_BaseCmdData.qsVerbCommand = VIEW_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
    m_StdLocation = QStandardPaths::StandardLocation::PicturesLocation;
    m_BaseCmdData.cmdType = E_COMMAND_TYPE::VIEW_PIC;
}

int VADefaultViewPictureCommand::Initialize()
{
    return 1;
}
