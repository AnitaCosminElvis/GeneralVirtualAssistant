#ifndef IBMWATSONSPEECHTOTEXTWRAPPER_H
#define IBMWATSONSPEECHTOTEXTWRAPPER_H

#include "ISpeechToText.h"
#include "Data/Defines.h"

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

public slots:
    void finishedReq();
    void authRequired(QNetworkReply *reply, QAuthenticator *ator);

#ifndef QT_NO_SSL
    void sslErrors(QNetworkReply *, const QList<QSslError> &errors);
#endif

private:
    QNetworkAccessManager   manager;
    QNetworkReply*          reply = nullptr;
    QUrl                    url;
    QString                 apiKey;
    QString                 headerContent;
    QString                 response;
};

#endif // IBMWATSONSPEECHTOTEXTWRAPPER_H
