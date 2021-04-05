#ifndef LOCALVIRTUALASSISTANT_H
#define LOCALVIRTUALASSISTANT_H

#include "aimlparser.h"
#include "../ivirtualassistant.h"
#include "../VACommands/IVACommand.h"
#include "../VACommands/ICommandInvoker.h"

#include <memory>

class LocalVirtualAssistant : public IVirtualAssistant
{
public:
    LocalVirtualAssistant();
    ~LocalVirtualAssistant();

    bool Initialize() override;
    std::string GetResponse(std::string& input) override;

private:
    std::string GetResponseFromInput(std::string& input);
    std::string StopCommand();
    bool IsStopCommand(const std::string& input);
    bool IsCommand(const std::string& input);
    std::string ExecuteCommand(const std::string& input);

private:
    std::unique_ptr<AIMLParser>                     m_pAimlParser;
    std::list<std::shared_ptr<ICommandInvoker>>     m_CmdInvokers;
    std::shared_ptr<ICommandInvoker>                m_CurrCmdInvoker;
    int                                             m_CurrCmdID;
    int                                             m_lastCmdID;

};

#endif // LOCALVIRTUALASSISTANT_H
