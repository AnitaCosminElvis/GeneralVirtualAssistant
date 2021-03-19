#include "VAWebWikiSearchCommand.h"
#include "../Utils/WebClient.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

VAWebWikiSearchCommand::VAWebWikiSearchCommand()
{
    m_qsUrl = "https://en.wikipedia.org/w/api.php?format=json&action=query&prop=extracts&exlimit=max&explaintext&exintro&redirects=&titles=";
    m_BaseCmdData.cmdType = E_COMMAND_TYPE::FIND_WIKI;
    m_BaseCmdData.qsVerbCommand = FIND_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
    m_pWebClient.reset(new WebClient);
}

int VAWebWikiSearchCommand::Initialize()
{
    m_pWebClient->Initialize();
    return 1;
}

bool VAWebWikiSearchCommand::ContainsCommand(const std::string &input)
{
    if (input.empty()) return false;

    QString qsInput = input.data();

    if (!qsInput.startsWith(m_BaseCmdData.qsVerbCommand,Qt::CaseInsensitive)) return false;
    if (!qsInput.contains(m_BaseCmdData.qsResourceType,Qt::CaseInsensitive)) return false;

    return true;
}

bool VAWebWikiSearchCommand::ExecuteCommand(const std::string &input)
{
    QString qsInput = input.data();
    QStringList words = qsInput.split(QLatin1Char(' '), Qt::SkipEmptyParts);

    if (words.count() >= m_BaseCmdData.nMinWordCount)
    {
        int sCount = qsInput.length() - (words[0].length() + words[1].length() + 2);
        QString qsSearchedTitle = qsInput.right(sCount);
        QUrl url(m_qsUrl + qsSearchedTitle);

        QString qsResponse = m_pWebClient->GET(url,"");

        QJsonDocument doc = QJsonDocument::fromJson(qsResponse.toUtf8());
        QJsonObject jObj = doc.object();

        QJsonObject query = jObj["query"].toObject();
        QJsonObject pages = query["pages"].toObject();
        QJsonObject page = pages.begin().value().toObject();
        QString extract = page["extract"].toString();

        m_result.clear();
        m_result.push_back(extract.toLocal8Bit().data());

        return true;
    }

    return false;
}

bool VAWebWikiSearchCommand::StopCommand()
{
    return true;
}

E_COMMAND_TYPE VAWebWikiSearchCommand::GetCommandType()
{
    return m_BaseCmdData.cmdType;
}

std::list<std::string> VAWebWikiSearchCommand::GetCommandResult()
{
    return m_result;
}
