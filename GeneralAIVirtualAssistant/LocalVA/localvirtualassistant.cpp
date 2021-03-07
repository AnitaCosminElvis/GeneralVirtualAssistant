#include "localvirtualassistant.h"

LocalVirtualAssistant::LocalVirtualAssistant()
{
}

LocalVirtualAssistant::~LocalVirtualAssistant()
{
    if (NULL != m_pAimlParser)
    {
        m_pAimlParser->clear();
        delete m_pAimlParser;
        m_pAimlParser = NULL;
    }
}

bool LocalVirtualAssistant::Initialize(){
    m_pAimlParser = new AIMLParser;

    if (NULL == m_pAimlParser)
    {
        return false;
    }

    QString qsDirPath = AIML_DIRECTORY;//+ QString("/") + qsAgeDirectory;


    if (false == m_pAimlParser->loadAIMLSet(qsDirPath))
    {
        return false;
    }

    m_pTextToSpeech = new GeneralTextToSpeechWrapper;

    if (NULL == m_pTextToSpeech)
    {
        return false;
    }

    return true;
}

std::string LocalVirtualAssistant::GetResponse(const std::string &input)
{
    QString response = m_pAimlParser->getResponse(input.data());

    m_pTextToSpeech->ConvertTextToSpeech(response.toLocal8Bit().data());

    return std::string(response.toLocal8Bit().data());
}
