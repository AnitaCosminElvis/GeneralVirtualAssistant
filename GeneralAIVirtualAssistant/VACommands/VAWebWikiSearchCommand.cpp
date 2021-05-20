#include "VAWebWikiSearchCommand.h"
#include "../Utils/WebClient.h"
#include "../Utils/CommandRectifier.h"
#include "../Utils/JSONHandler.h"

VAWebWikiSearchCommand::VAWebWikiSearchCommand()
{
    U_COMMAND_TYPE cmdType;
    cmdType.webCmdType = E_WEB_COMMAND_TYPE::FIND_WIKI;
    m_BaseCmdData.cmdType = cmdType.nVal;

    m_qsUrl = "https://en.wikipedia.org/w/api.php?format=json&action=query&prop=extracts&exlimit=max&explaintext&exintro&redirects=&titles=";
    m_BaseCmdData.qsVerbCommand = FIND_COMMAND;
    m_BaseCmdData.qsResourceType = RESOURCE_TYPE;
    m_BaseCmdData.nMinWordCount = MIN_WORD_COUNT;
}

int VAWebWikiSearchCommand::Initialize(const std::string &)
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
    QStringList words = CommandRectifier::GetSanitizedCommandArgs(m_BaseCmdData,qsInput);

    if (!words.empty())
    {
        QString qsSearchedTitle = words.join(" ");
        QUrl url(m_qsUrl + qsSearchedTitle);

        QString qsResponse = m_pWebClient->GET(url,"");

        JSONHandler jsonParser;
        m_result.clear();

        if (jsonParser.LoadJSONFromString(qsResponse)){
            QList<QString> jsonPath = {"query","pages",".","extract"};
            QString extract = jsonParser.GetValueByJSONPath(jsonPath);
            m_result = extract.toLocal8Bit().data();
        }

        return (m_result.empty())? false : true;
    }

    return false;
}

bool VAWebWikiSearchCommand::StopCommand()
{
    return true;
}
