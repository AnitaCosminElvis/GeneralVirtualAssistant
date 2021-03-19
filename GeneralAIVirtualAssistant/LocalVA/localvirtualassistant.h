#ifndef LOCALVIRTUALASSISTANT_H
#define LOCALVIRTUALASSISTANT_H

#include <memory>

#include "ivirtualassistant.h"
#include "aimlparser.h"
#include "SpeechTextIO/ITextToSpeech.h"
#include "SpeechTextIO/ISpeechToText.h"
#include "../VACommands/IVACommand.h"
#include "../VACommands/CommandInvoker.h"
#include "../Data/Defines.h"

class LocalVirtualAssistant : public IVirtualAssistant
{
public:
    LocalVirtualAssistant();
    ~LocalVirtualAssistant();

    bool Initialize() override;
    std::string GetResponse(std::string& input, bool isRecording = true) override;

private:
    std::string GetResponeFromInput(std::string& input);

private:
    std::unique_ptr<AIMLParser>     m_pAimlParser;
    std::unique_ptr<ITextToSpeech>  m_pTextToSpeech;
    std::unique_ptr<ISpeechToText>  m_pSpeechToText;
    std::unique_ptr<CommandInvoker> m_pCommandInvoker;
    E_COMMAND_TYPE                  m_lastCmdType;
};

#endif // LOCALVIRTUALASSISTANT_H
