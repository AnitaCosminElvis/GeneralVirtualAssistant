#ifndef IBMWATSONSPEECHTOTEXTWRAPPER_H
#define IBMWATSONSPEECHTOTEXTWRAPPER_H

#include "ISpeechToText.h"
#include "Data/Defines.h"
#include "../Utils/WebClient.h"

#include <memory>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QAuthenticator>

class IBMWatsonSpeechToText: public QObject
{
    Q_OBJECT
public:
    IBMWatsonSpeechToText();

    int Initialize();
    std::string ConvertSpeechToText();
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
