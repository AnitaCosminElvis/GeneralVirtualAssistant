#ifndef IBMWATSONSPEECHTOTEXTWRAPPER_H
#define IBMWATSONSPEECHTOTEXTWRAPPER_H

#include "ISpeechToText.h"

#include <memory>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QAuthenticator>

class IBMWatsonSpeechToTextWrapper: public QObject, public ISpeechToText
{
    Q_OBJECT
public:
    IBMWatsonSpeechToTextWrapper();

    int Initialize() override;
    std::string ConvertSpeechToText(const void *) override;
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
