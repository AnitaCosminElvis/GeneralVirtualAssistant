#include "IBMWatsonSpeechToText.h"
#include <QFile>
#include <QDir>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include "../Utils/JSONHandler.h"

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
    JSONHandler jsonParser;
    QString response = m_response;
    m_response.clear();

    if (jsonParser.LoadJSONFromString(response)){
        QList<QString> jsonPath = {"results","alternatives","transcript"};
        response = jsonParser.GetValueByJSONPath(jsonPath);
    }

    return response.toLocal8Bit().data();
}

