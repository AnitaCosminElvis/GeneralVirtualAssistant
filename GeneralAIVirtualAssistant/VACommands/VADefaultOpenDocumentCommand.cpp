#include "VADefaultOpenDocumentCommand.h"

VADefaultOpenDocumentCommand::VADefaultOpenDocumentCommand()
{
    U_COMMAND_TYPE cmdType;
    cmdType.localCmdType = E_LOCAL_COMMAND_TYPE::OPEN_DOC;
    m_BaseCmdData.cmdType = cmdType.nVal;

    m_BaseCmdData.qsVerbCommand = OPEN_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
    m_StdLocation = QStandardPaths::StandardLocation::DocumentsLocation;
}

int VADefaultOpenDocumentCommand::Initialize(const std::string&)
{
    return 1;
}
