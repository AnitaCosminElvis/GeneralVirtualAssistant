#include "webvirtualassistant.h"
#include "SpeechTextIO/TextToSpeechWrapper.h"
#include "SpeechTextIO/SpeechToTextWrapper.h"

WebVirtualAssistant::WebVirtualAssistant()
{
    m_pTextToSpeech.reset(new TextToSpeechWrapper);
    m_pSpeechToText.reset(new SpeechToTextWrapper);
}

WebVirtualAssistant::~WebVirtualAssistant()
{
}

bool WebVirtualAssistant::Initialize()
{
    m_pTextToSpeech->Initialize();
    m_pSpeechToText->Initialize();
    return true;
}

std::string WebVirtualAssistant::GetResponse(std::string & input, bool isRecording)
{
    if (isRecording){
        input = m_pSpeechToText->ConvertSpeechToText();
    }

    QString response = "TEST WEB";//TODO->getResponse(inBuff.data());

    return std::string(response.toLocal8Bit().data());
}
