#include "VAWebAbstractCommand.h"

VAWebAbstractCommand::VAWebAbstractCommand()
{
    m_pWebClient.reset(new WebClient);
}

int VAWebAbstractCommand::GetCommandType()
{
    return m_BaseCmdData.cmdType;
}

int VAWebAbstractCommand::GetCommandID()
{
    return m_BaseCmdData.cmdType;
}

std::string VAWebAbstractCommand::GetCommandResult()
{
    return m_result;
}
