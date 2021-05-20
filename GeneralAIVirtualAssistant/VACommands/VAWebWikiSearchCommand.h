#ifndef VAWEBWIKISEARCHCOMMAND_H
#define VAWEBWIKISEARCHCOMMAND_H

#include "VAWebAbstractCommand.h"
#include <memory>

#define FIND_COMMAND    "search"
#define RESOURCE_TYPE   "wiki"
#define MIN_WORD_COUNT  2

class VAWebWikiSearchCommand: public VAWebAbstractCommand
{
public:
    VAWebWikiSearchCommand();

    int                     Initialize(const std::string& = "") override;
    bool                    ContainsCommand(const std::string& input) override;
    bool                    ExecuteCommand(const std::string& input) override;
    bool                    StopCommand() override;

};

#endif // VAWEBWIKISEARCHCOMMAND_H
