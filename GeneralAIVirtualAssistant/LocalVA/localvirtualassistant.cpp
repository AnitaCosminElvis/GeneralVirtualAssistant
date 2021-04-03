#include "localvirtualassistant.h"
#include "../VACommands/VACommandsFactory.h"
#include "../VACommands/ICommandInvoker.h"
#include "../VACommands/CommandsInvokerFactory.h"



LocalVirtualAssistant::LocalVirtualAssistant()
{
    m_pAimlParser.reset(new AIMLParser);
    m_pCommandInvoker.reset(CommandsInvokerFactory::CreateVACommand(E_COMMAND_INVOKER_TYPE::LOCAL));
    m_lastCmdType = 0;
}

LocalVirtualAssistant::~LocalVirtualAssistant()
{
        m_pAimlParser->clear();
}

bool LocalVirtualAssistant::Initialize()
{
    QString qsDirPath = AIML_DIRECTORY;//+ QString("/") + qsAgeDirectory;

    if (false == m_pAimlParser->loadAIMLSet(qsDirPath))
    {
        return false;
    }

    return m_pCommandInvoker->Initialize();
}

std::string LocalVirtualAssistant::GetResponse(std::string &input)
{
    return GetResponseFromInput(input);
}

std::string LocalVirtualAssistant::GetResponseFromInput(std::string &input)
{
    std::string response;
    U_LOCAL_COMMAND_TYPE cmdType;
    if (!input.empty())
    {
        if (input.rfind("stop",0) == 0)
        {
            if (m_pCommandInvoker->StopCommand(m_lastCmdType)) response = VA_STOP_CMD_SUCCESS;
            else response  = VA_CMD_PARTIAL;
        }
        else if (cmdType.nVal = m_pCommandInvoker->IsCommand(input); cmdType.command_type != E_LOCAL_COMMAND_TYPE::UNDEFINED)
        {
            m_lastCmdType = cmdType.nVal;
            if (m_pCommandInvoker->ExecuteCommand(input,cmdType.nVal)){
                response = VA_CMD_SUCCESS;
                std::list<std::string> list = m_pCommandInvoker->GetResult(cmdType.nVal);
                response += list.front();
            }else response = VA_CMD_FAIL;
        }else{
            response = m_pAimlParser->getResponse(input.data()).toLocal8Bit().data();
        }
    }

    if (response.empty()) response = VA_SORRY;

    return response;
}
