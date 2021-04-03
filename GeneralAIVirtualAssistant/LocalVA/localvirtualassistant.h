#ifndef LOCALVIRTUALASSISTANT_H
#define LOCALVIRTUALASSISTANT_H

#include <memory>

#include "ivirtualassistant.h"
#include "aimlparser.h"
#include "SpeechTextIO/ITextToSpeech.h"
#include "SpeechTextIO/ISpeechToText.h"
#include "../VACommands/IVACommand.h"
#include "../VACommands/LocalCommandInvoker.h"
#include "../Data/Defines.h"

class LocalVirtualAssistant : public IVirtualAssistant
{
public:
    LocalVirtualAssistant();
    ~LocalVirtualAssistant();

    bool Initialize() override;
    std::string GetResponse(std::string& input) override;

private:
    std::string GetResponseFromInput(std::string& input);

private:
    std::unique_ptr<AIMLParser>             m_pAimlParser;
    std::unique_ptr<ICommandInvoker>        m_pCommandInvoker;
    int                                     m_lastCmdType;
};

#endif // LOCALVIRTUALASSISTANT_H
