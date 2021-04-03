#include "VADuckDuckGoSearchCommand.h"
#include "../Utils/JSONHandler.h"
#include "../Data/Enums.h"

VADuckDuckGoSearchCommand::VADuckDuckGoSearchCommand()
{
    U_WEB_COMMAND_TYPE cmdType;
    cmdType.command_type = E_WEB_COMMAND_TYPE::DUCK_DUCK_GO;
    m_qsUrl = "https://api.duckduckgo.com/?q=";
    m_qsParams = "&format=json";
    m_BaseCmdData.cmdType = cmdType.nVal;
    m_BaseCmdData.qsVerbCommand = "";
    m_BaseCmdData.qsResourceType = "";
    m_BaseCmdData.nMinWordCount = 1;
    m_pWebClient.reset(new WebClient);
}

int VADuckDuckGoSearchCommand::Initialize()
{
    m_hrefRegExp.setPattern(R"(href="([^"]*))");
    m_wikiApi.Initialize();
    return m_pWebClient->Initialize();
}

bool VADuckDuckGoSearchCommand::ContainsCommand(const std::string &input)
{
    return (!input.empty())? true : false;
}

bool VADuckDuckGoSearchCommand::ExecuteCommand(const std::string &input)
{
    QString qsInput = input.data();
    QString words = qsInput.replace(QLatin1Char(' '), QLatin1Char('+'));

    if (!words.isEmpty())
    {
        QUrl url(m_qsUrl + words + m_qsParams);

        QString qsResponse = m_pWebClient->GET(url,"");

        JSONHandler jsonParser;
        m_result.clear();

        if (jsonParser.LoadJSONFromString(qsResponse)){
            QList<QString> jsonPath = {"AbstractText"};
            QString extract = jsonParser.GetValueByJSONPath(jsonPath);
            if (extract.isEmpty()){
                jsonPath = {"AbstractURL"};
                extract = jsonParser.GetValueByJSONPath(jsonPath);
                if (extract.contains("wikipedia")){
                   if (m_wikiApi.ExecuteCommand(input)){
                       extract = m_wikiApi.GetCommandResult().front().data();
                   }else return false;
                }else return false;
            }
            m_result.push_back(extract.toLocal8Bit().data());
        }else return false;

        return true;
    }

    return false;
}

bool VADuckDuckGoSearchCommand::StopCommand()
{
    return true;
}

int VADuckDuckGoSearchCommand::GetCommandType()
{
    return m_BaseCmdData.cmdType;
}

std::list<std::string> VADuckDuckGoSearchCommand::GetCommandResult()
{
    return m_result;
}
