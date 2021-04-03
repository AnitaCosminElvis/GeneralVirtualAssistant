#include "VADefaultViewPictureCommand.h"

VADefaultViewPictureCommand::VADefaultViewPictureCommand()
{
    U_LOCAL_COMMAND_TYPE cmdType;
    cmdType.command_type = E_LOCAL_COMMAND_TYPE::VIEW_PIC;
    m_BaseCmdData.cmdType = cmdType.nVal;

    m_BaseCmdData.qsVerbCommand = VIEW_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
    m_StdLocation = QStandardPaths::StandardLocation::PicturesLocation;
}

int VADefaultViewPictureCommand::Initialize()
{
    return 1;
}
