#include "IBMWatsonSpeechToText.h"
#include <QFile>
#include <QDir>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>

IBMWatsonSpeechToText::IBMWatsonSpeechToText()
{
    m_url.setUrl("");

    m_apiKey = "";

    m_headerContent = "audio/wav";

    m_webClient.reset(new WebClient);
}

int IBMWatsonSpeechToText::Initialize()
{
    m_webClient->Initialize();
    m_webClient->SetCredentials("apikey", m_apiKey);
    return 1;
}

std::string IBMWatsonSpeechToText::ConvertSpeechToText()
{
    QString path = QDir::currentPath() + DATA_PATH +RECORD_PATH;

    std::unique_ptr<QFile>  file(new QFile(path));

    if (!file->open(QIODevice::ReadWrite)) return "";

    m_response = m_webClient->POST(m_url,m_headerContent, file->readAll());

    return GetAnswerFromResponse();
}


std::string IBMWatsonSpeechToText::GetAnswerFromResponse(){
    QJsonDocument doc = QJsonDocument::fromJson(m_response.toUtf8());
    QJsonObject jObj = doc.object();
    m_response.clear();

    if (jObj.contains("results") && jObj["results"].isArray()) {
        QJsonArray resultsArray = jObj["results"].toArray();
        QJsonObject jObjRes = resultsArray.at(0).toObject();
        QJsonArray altArray = jObjRes["alternatives"].toArray();

        foreach (const QJsonValue & transVal, altArray)
        {
            if (transVal.toObject().contains("transcript"))
            {
                m_response = transVal.toObject().value("transcript").toString();
                break;
            }
        }
    }

    return m_response.toLocal8Bit().data();
}

