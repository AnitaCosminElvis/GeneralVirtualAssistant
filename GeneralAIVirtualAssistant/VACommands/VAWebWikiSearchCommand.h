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

    int                     Initialize() override;
    bool                    ContainsCommand(const std::string& input) override;
    bool                    ExecuteCommand(const std::string& input) override;
    bool                    StopCommand() override;
    E_COMMAND_TYPE          GetCommandType() override;
    std::list<std::string>  GetCommandResult() override;

private:
    std::unique_ptr<WebClient>          m_pWebClient;
    QString                             m_qsUrl;
    S_BASE_COMMAND_DATA                 m_BaseCmdData;
    std::list<std::string>              m_result;
};

#endif // VAWEBWIKISEARCHCOMMAND_H
