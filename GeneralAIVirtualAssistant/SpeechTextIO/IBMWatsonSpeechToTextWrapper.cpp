#include "IBMWatsonSpeechToTextWrapper.h"
#include <QFile>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>

IBMWatsonSpeechToTextWrapper::IBMWatsonSpeechToTextWrapper()
{
    url.setUrl("");

    apiKey = "";

    headerContent = "audio/wav";
}

int IBMWatsonSpeechToTextWrapper::Initialize()
{

    bool bconnect = connect(&manager,    SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)),
            this,       SLOT(authRequired(QNetworkReply*,QAuthenticator*)));

#ifndef QT_NO_SSL
    bconnect = connect(&manager,      &QNetworkAccessManager::sslErrors,
            this,       &IBMWatsonSpeechToTextWrapper::sslErrors);
#endif

    return 1;
}

std::string IBMWatsonSpeechToTextWrapper::ConvertSpeechToText(const void *)
{
    std::unique_ptr<QFile>  file(new QFile("C:/Users/selectuls/Desktop/record.wav"));

    if (!file->open(QIODevice::ReadWrite)) return "";

    QEventLoop loop;
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, headerContent);
    request.setUrl(url);

    reply = manager.post(request,file->readAll());

    bool bconn = connect(reply, &QNetworkReply::finished, this, &IBMWatsonSpeechToTextWrapper::finishedReq);

    bconn = connect(reply , &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    return GetAnswerFromResponse();
}


void IBMWatsonSpeechToTextWrapper::finishedReq() {
    if (reply->error()) {
        response = reply->errorString();
        return;
    }

    response = reply->readAll();
    int i = 0;
}

void IBMWatsonSpeechToTextWrapper::authRequired(QNetworkReply *reply, QAuthenticator *ator)
{
    ator->setUser("apikey");
    ator->setPassword(apiKey);
}

#ifndef QT_NO_SSL
void IBMWatsonSpeechToTextWrapper::sslErrors(QNetworkReply *, const QList<QSslError> &errors)
{
    QString errorString;
    for (const QSslError &error : errors) {
        if (!errorString.isEmpty())
            errorString += '\n';
        errorString += error.errorString();
    }

    qDebug() << errorString;

    reply->ignoreSslErrors();

}
#endif

std::string IBMWatsonSpeechToTextWrapper::GetAnswerFromResponse(){
    QJsonDocument doc = QJsonDocument::fromJson(response.toUtf8());
    QJsonObject jObj = doc.object();
    response.clear();

    if (jObj.contains("results") && jObj["results"].isArray()) {
        QJsonArray resultsArray = jObj["results"].toArray();
        QJsonObject jObjRes = resultsArray.at(0).toObject();
        QJsonArray altArray = jObjRes["alternatives"].toArray();

        foreach (const QJsonValue & transVal, altArray)
        {
            if (transVal.toObject().contains("transcript"))
            {
                response = transVal.toObject().value("transcript").toString();
                break;
            }
        }
    }

    return response.toLocal8Bit().data();
}
