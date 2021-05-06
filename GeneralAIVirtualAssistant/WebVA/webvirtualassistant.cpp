#include "webvirtualassistant.h"
#include "../VACommands/VACommandsFactory.h"
#include "../VACommands/ICommandInvoker.h"
#include "../VACommands/InvokerFactoryCreator.h"
#include "../Data/Defines.h"

WebVirtualAssistant::WebVirtualAssistant()
{
    std::unique_ptr<ICommandInvokerFactory> invokerFactory;
    invokerFactory.reset(InvokerFactoryCreator::GetCommandInvokerFactory(E_VA_TYPE::WEB));

    std::shared_ptr<ICommandInvoker> webDefaultCmdInvoker;
    std::shared_ptr<ICommandInvoker> webCustomCmdInvoker;

    webCustomCmdInvoker.reset(invokerFactory->CreateCommandInvoker(E_COMMAND_INVOKER_TYPE::WEB_CUSTOM));

    if (webCustomCmdInvoker) m_CmdInvokers.push_back(webCustomCmdInvoker);

    webDefaultCmdInvoker.reset(invokerFactory->CreateCommandInvoker(E_COMMAND_INVOKER_TYPE::WEB_DEFAULT));

    if (webDefaultCmdInvoker) m_CmdInvokers.push_back(webDefaultCmdInvoker);

    m_lastCmdID = 0;
}

WebVirtualAssistant::~WebVirtualAssistant()
{

}

bool WebVirtualAssistant::Initialize()
{
    for (auto cmdInvoker: m_CmdInvokers){
        if (!cmdInvoker->Initialize()) return false;
    }

    return true;
}

std::string WebVirtualAssistant::GetResponse(const std::string &input)
{
    return GetResponseFromInput(input);
}

std::string WebVirtualAssistant::GetResponseFromInput(const std::string &input)
{
    std::string response;
    if (!input.empty())
    {
        if (IsStopCommand(input)) response = StopCommand();
        else if (IsCommand(input)){
            response = ExecuteCommand(input);
        }
    }

    if (response.empty()) response = VA_NOT_FOUND + input;

    return response;
}

std::string WebVirtualAssistant::StopCommand()
{
    U_COMMAND_TYPE cmdCount;
    cmdCount.localCmdType = E_LOCAL_COMMAND_TYPE::COUNT;
    std::shared_ptr<ICommandInvoker> cmdInvoker;

    if (m_lastCmdID < cmdCount.nVal) cmdInvoker = m_CmdInvokers.back();
    else cmdInvoker = m_CmdInvokers.front();

    if (cmdInvoker->StopCommand(m_lastCmdID)) return VA_STOP_CMD_SUCCESS;
    else return VA_CMD_PARTIAL;
}

bool WebVirtualAssistant::IsStopCommand(const std::string &input)
{
    return (input.rfind(STOP_PATTERN,0) == 0);
}

bool WebVirtualAssistant::IsCommand(const std::string &input)
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

std::string WebVirtualAssistant::ExecuteCommand(const std::string &input)
{
    if (m_CurrCmdInvoker && m_CurrCmdInvoker->ExecuteCommand(input, m_CurrCmdID)){
        std::string result = m_CurrCmdInvoker->GetResult(m_CurrCmdID);
        m_lastCmdID = m_CurrCmdID;
        return VA_CMD_SUCCESS + result;
    } else return VA_CMD_FAIL;
}

