#ifndef VAGOOGLESEARCHCOMMAND_H
#define VAGOOGLESEARCHCOMMAND_H

#include "IVACommand.h"
#include "../Data/Structs.h"
#include "../Utils/WebClient.h"
#include "VAWebWikiSearchCommand.h"

#include <QUrl>
#include <memory>
#include <QRegularExpression>

class VADuckDuckGoSearchCommand: public IVACommand
{
public:
    VADuckDuckGoSearchCommand();

    int                     Initialize() override;
    bool                    ContainsCommand(const std::string& input) override;
    bool                    ExecuteCommand(const std::string& input) override;
    bool                    StopCommand() override;
    int                     GetCommandType() override;
    std::list<std::string>  GetCommandResult() override;

private:
    std::unique_ptr<WebClient>          m_pWebClient;
    QString                             m_qsUrl;
    QString                             m_qsParams;
    S_BASE_COMMAND_DATA                 m_BaseCmdData;
    std::list<std::string>              m_result;
    QRegularExpression                  m_hrefRegExp;
    VAWebWikiSearchCommand              m_wikiApi;
};

#endif // VAGOOGLESEARCHCOMMAND_H
