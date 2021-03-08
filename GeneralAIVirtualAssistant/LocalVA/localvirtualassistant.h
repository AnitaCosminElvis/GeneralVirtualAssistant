#ifndef LOCALVIRTUALASSISTANT_H
#define LOCALVIRTUALASSISTANT_H

#include <memory>

#include "ivirtualassistant.h"
#include "aimlparser.h"
#include "SpeechTextIO/ITextToSpeech.h"
#include "SpeechTextIO/ISpeechToText.h"
#include "../Data/Defines.h"

class LocalVirtualAssistant : public IVirtualAssistant
{
public:
    LocalVirtualAssistant();
    ~LocalVirtualAssistant();

    bool Initialize() override;
    std::string GetResponse(std::string& input, bool isRecording = true) override;

private:
    std::unique_ptr<AIMLParser>     m_pAimlParser;
    std::unique_ptr<ITextToSpeech>  m_pTextToSpeech;
    std::unique_ptr<ISpeechToText>  m_pSpeechToText;
};

#endif // LOCALVIRTUALASSISTANT_H
