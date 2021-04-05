#include "localvirtualassistant.h"
#include "../VACommands/VACommandsFactory.h"
#include "../VACommands/ICommandInvoker.h"
#include "../VACommands/InvokerFactoryCreator.h"
#include "../Data/Defines.h"

LocalVirtualAssistant::LocalVirtualAssistant()
{
    m_pAimlParser.reset(new AIMLParser);

    std::unique_ptr<ICommandInvokerFactory> invokerFactory;
    invokerFactory.reset(InvokerFactoryCreator::GetCommandInvokerFactory(E_VA_TYPE::LOCAL));

    std::shared_ptr<ICommandInvoker> localDefaultCmdInvoker;
    std::shared_ptr<ICommandInvoker> localCustomCmdInvoker;

    localDefaultCmdInvoker.reset(invokerFactory->CreateCommandInvoker(E_COMMAND_INVOKER_TYPE::LOCAL_DEFAULT));

    if (localDefaultCmdInvoker) m_CmdInvokers.push_back(localDefaultCmdInvoker);

    localCustomCmdInvoker.reset(invokerFactory->CreateCommandInvoker(E_COMMAND_INVOKER_TYPE::LOCAL_CUSTOM));

    if (localCustomCmdInvoker) m_CmdInvokers.push_back(localCustomCmdInvoker);

    m_lastCmdID = 0;
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

    for (auto cmdInvoker: m_CmdInvokers){
        if (!cmdInvoker->Initialize()) return false;
    }

    return true;
}

std::string LocalVirtualAssistant::GetResponse(std::string &input)
{
    return GetResponseFromInput(input);
}

std::string LocalVirtualAssistant::GetResponseFromInput(std::string &input)
{
    std::string response;
    if (!input.empty())
    {
        if (IsStopCommand(input)) response = StopCommand();
        else if (IsCommand(input)){
            response = ExecuteCommand(input);
        }else response = m_pAimlParser->getResponse(input.data()).toLocal8Bit().data();
    }

    if (response.empty()) response = VA_SORRY;

    return response;
}

std::string LocalVirtualAssistant::StopCommand()
{
    U_COMMAND_TYPE cmdCount;
    cmdCount.localCmdType = E_LOCAL_COMMAND_TYPE::COUNT;
    std::shared_ptr<ICommandInvoker> cmdInvoker;

    if (m_lastCmdID < cmdCount.nVal) cmdInvoker = m_CmdInvokers.front();
    else cmdInvoker = m_CmdInvokers.back();

    if (cmdInvoker->StopCommand(m_lastCmdID)) return VA_STOP_CMD_SUCCESS;
    else return VA_CMD_PARTIAL;
}

bool LocalVirtualAssistant::IsStopCommand(const std::string &input)
{
    return (input.rfind(STOP_PATTERN,0) == 0);
}

bool LocalVirtualAssistant::IsCommand(const std::string &input)
{
    U_COMMAND_TYPE cmdType;
    cmdType.localCmdType = E_LOCAL_COMMAND_TYPE::UNDEFINED;

    for (auto cmdInvoker: m_CmdInvokers){
        if (cmdType.nVal = cmdInvoker->IsCommand(input); cmdType.localCmdType != E_LOCAL_COMMAND_TYPE::UNDEFINED){
            m_CurrCmdID = cmdType.nVal;
            m_CurrCmdInvoker = cmdInvoker;
            return true;
        }
    }

    return false;
}

std::string LocalVirtualAssistant::ExecuteCommand(const std::string &input)
{
    if (m_CurrCmdInvoker && m_CurrCmdInvoker->ExecuteCommand(input, m_CurrCmdID)){
        std::string result = m_CurrCmdInvoker->GetResult(m_CurrCmdID);
        m_lastCmdID = m_CurrCmdID;
        return VA_CMD_SUCCESS + result;
    } else return VA_CMD_FAIL;
}
