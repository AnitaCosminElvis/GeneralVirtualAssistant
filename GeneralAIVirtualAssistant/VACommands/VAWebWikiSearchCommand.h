#ifndef VAWEBWIKISEARCHCOMMAND_H
#define VAWEBWIKISEARCHCOMMAND_H

#include "IVACommand.h"
#include "../Data/Structs.h"
#include "../Utils/WebClient.h"

#include <QUrl>
#include <memory>

#define FIND_COMMAND    "find"
#define RESOURCE_TYPE   "wiki"
#define MIN_WORD_COUNT  3

class VAWebWikiSearchCommand: public IVACommand
{
public:
    VAWebWikiSearchCommand();

    int                     Initialize(const std::string& = "") override;
    bool                    ContainsCommand(const std::string& input) override;
    bool                    ExecuteCommand(const std::string& input) override;
    bool                    StopCommand() override;
    int                     GetCommandType() override;
    int                     GetCommandID() override;
    std::string             GetCommandResult() override;

private:
    std::unique_ptr<WebClient>          m_pWebClient;
    QString                             m_qsUrl;
    S_BASE_COMMAND_DATA                 m_BaseCmdData;
    std::string                         m_result;
};

#endif // VAWEBWIKISEARCHCOMMAND_H
