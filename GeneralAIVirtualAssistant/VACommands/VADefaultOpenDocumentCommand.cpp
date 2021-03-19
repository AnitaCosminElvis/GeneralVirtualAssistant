#include "VADefaultOpenDocumentCommand.h"

VADefaultOpenDocumentCommand::VADefaultOpenDocumentCommand()
{
    m_BaseCmdData.qsVerbCommand = OPEN_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
    m_StdLocation = QStandardPaths::StandardLocation::DocumentsLocation;
    m_BaseCmdData.cmdType = E_COMMAND_TYPE::OPEN_DOC;
}

int VADefaultOpenDocumentCommand::Initialize()
{
    return 1;
}
