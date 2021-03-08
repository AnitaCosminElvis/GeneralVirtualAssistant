#include "localvirtualassistant.h"
#include "SpeechTextIO/TextToSpeechWrapper.h"
#include "SpeechTextIO/SpeechToTextWrapper.h"

LocalVirtualAssistant::LocalVirtualAssistant()
{
    m_pAimlParser.reset(new AIMLParser);
    m_pTextToSpeech.reset(new TextToSpeechWrapper);
    m_pSpeechToText.reset(new SpeechToTextWrapper);
}

LocalVirtualAssistant::~LocalVirtualAssistant()
{
        m_pAimlParser->clear();
}

bool LocalVirtualAssistant::Initialize()
{
    QString qsDirPath = AIML_DIRECTORY;//+ QString("/") + qsAgeDirectory;

    if (false == m_pAimlParser->loadAIMLSet(qsDirPath))
    {
        return false;
    }

    m_pTextToSpeech->Initialize();
    m_pSpeechToText->Initialize();

    return true;
}

std::string LocalVirtualAssistant::GetResponse(std::string &input, bool isRecording)
{
    if (isRecording){
        input = m_pSpeechToText->ConvertSpeechToText();
    }

    QString response = m_pAimlParser->getResponse(input.data());

    if (response.isEmpty()) response = VA_SORRY;

    m_pTextToSpeech->ConvertTextToSpeech(response.toLocal8Bit().data());

    return std::string(response.toLocal8Bit().data());
}
