#ifndef WEBVIRTUALASSISTANT_H
#define WEBVIRTUALASSISTANT_H

#include "../ivirtualassistant.h"
#include "SpeechTextIO/ITextToSpeech.h"
#include "SpeechTextIO/ISpeechToText.h"
#include "../VACommands/IVACommand.h"
#include "../VACommands/LocalCommandInvoker.h"
#include "../Data/Defines.h"

class WebVirtualAssistant : public IVirtualAssistant
{
public:
    WebVirtualAssistant();
    ~WebVirtualAssistant();

    bool Initialize() override;
    std::string GetResponse(std::string& input) override;

private:
    std::string GetResponseFromInput(std::string &input);

private:
    std::unique_ptr<ICommandInvoker>            m_pCommandInvoker;
    int                                         m_lastCmdType;
};

#endif // WEBVIRTUALASSISTANT_H
