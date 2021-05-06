#ifndef WEBVIRTUALASSISTANT_H
#define WEBVIRTUALASSISTANT_H

#include "../ivirtualassistant.h"
#include "../VACommands/IVACommand.h"
#include "../VACommands/ICommandInvoker.h"

#include <memory>

class WebVirtualAssistant : public IVirtualAssistant
{
public:
    WebVirtualAssistant();
    ~WebVirtualAssistant();

    bool Initialize() override;
    std::string GetResponse(const std::string& input) override;

private:
    std::string GetResponseFromInput(const std::string& input);
    std::string StopCommand();
    bool IsStopCommand(const std::string& input);
    bool IsCommand(const std::string& input);
    std::string ExecuteCommand(const std::string& input);

private:
    std::list<std::shared_ptr<ICommandInvoker>>     m_CmdInvokers;
    std::shared_ptr<ICommandInvoker>                m_CurrCmdInvoker;
    int                                             m_CurrCmdID;
    int                                             m_lastCmdID;
};

#endif // WEBVIRTUALASSISTANT_H
