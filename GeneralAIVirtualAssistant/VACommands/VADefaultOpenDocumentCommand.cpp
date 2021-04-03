#include "VADefaultOpenDocumentCommand.h"

VADefaultOpenDocumentCommand::VADefaultOpenDocumentCommand()
{
    U_LOCAL_COMMAND_TYPE cmdType;
    cmdType.command_type = E_LOCAL_COMMAND_TYPE::OPEN_DOC;
    m_BaseCmdData.cmdType = cmdType.nVal;

    m_BaseCmdData.qsVerbCommand = OPEN_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
    m_StdLocation = QStandardPaths::StandardLocation::DocumentsLocation;
}

int VADefaultOpenDocumentCommand::Initialize()
{
    return 1;
}
