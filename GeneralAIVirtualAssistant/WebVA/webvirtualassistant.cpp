#include "webvirtualassistant.h"
#include "../VACommands/VACommandsFactory.h"
#include "../VACommands/ICommandInvoker.h"
#include "../VACommands/CommandsInvokerFactory.h"

WebVirtualAssistant::WebVirtualAssistant()
{
    m_pCommandInvoker.reset(CommandsInvokerFactory::CreateVACommand(E_COMMAND_INVOKER_TYPE::WEB));
    m_lastCmdType = 0;
}

WebVirtualAssistant::~WebVirtualAssistant()
{

}

bool WebVirtualAssistant::Initialize()
{
    return m_pCommandInvoker->Initialize();
}

std::string WebVirtualAssistant::GetResponse(std::string & input)
{
    return GetResponseFromInput(input);
}

std::string WebVirtualAssistant::GetResponseFromInput(std::string &input)
{
    std::string response;
    U_WEB_COMMAND_TYPE cmdType;
    if (!input.empty())
    {
        if (input.rfind("stop",0) == 0)
        {
            if (m_pCommandInvoker->StopCommand(m_lastCmdType)) response = VA_STOP_CMD_SUCCESS;
            else response  = VA_CMD_PARTIAL;
        }
        else if (cmdType.nVal = m_pCommandInvoker->IsCommand(input); cmdType.command_type != E_WEB_COMMAND_TYPE::UNDEFINED)
        {
            m_lastCmdType = cmdType.nVal;
            if  (m_pCommandInvoker->ExecuteCommand(input,cmdType.nVal)){
                response = VA_CMD_SUCCESS;
                std::list<std::string> list = m_pCommandInvoker->GetResult(cmdType.nVal);
                response += list.front();
            }else response.clear();
        }
    }

    if (response.empty()) response = VA_NOT_FOUND + input;

    return response;
}
