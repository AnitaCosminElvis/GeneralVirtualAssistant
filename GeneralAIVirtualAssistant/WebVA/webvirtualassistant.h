#ifndef WEBVIRTUALASSISTANT_H
#define WEBVIRTUALASSISTANT_H

#include "../ivirtualassistant.h"
#include "../Data/Defines.h"
#include "SpeechTextIO/IBMWatsonSpeechToText.h"
#include "SpeechTextIO/ITextToSpeech.h"
#include "SpeechTextIO/ISpeechToText.h"
#include "../Data/Defines.h"

class WebVirtualAssistant : public IVirtualAssistant
{
public:
    WebVirtualAssistant();
    ~WebVirtualAssistant();

    bool Initialize() override;
    std::string GetResponse(std::string& input, bool isRecording = true) override;

private:
    std::unique_ptr<ITextToSpeech>  m_pTextToSpeech;
    std::unique_ptr<ISpeechToText>  m_pSpeechToText;
};

#endif // WEBVIRTUALASSISTANT_H
