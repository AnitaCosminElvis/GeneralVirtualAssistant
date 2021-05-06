#ifndef IBMWATSONSPEECHTOTEXTWRAPPER_H
#define IBMWATSONSPEECHTOTEXTWRAPPER_H

#include "ISpeechToText.h"
#include "Data/Defines.h"
#include "../Utils/WebClient.h"

#include <memory>

class IBMWatsonSpeechToText: public ISpeechToText
{
public:
    IBMWatsonSpeechToText();

    int Initialize() override;
    std::string ConvertSpeechToText() override;
private:
    std::string GetAnswerFromResponse();

private:
    std::unique_ptr<WebClient>      m_webClient;
    QUrl                            m_url;
    QString                         m_apiKey;
    QString                         m_headerContent;
    QString                         m_response;
};

#endif // IBMWATSONSPEECHTOTEXTWRAPPER_H
