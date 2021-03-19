#ifndef COMMANDINVOKER_H
#define COMMANDINVOKER_H

#include <string>
#include <memory>

#include <map>

#include "IVACommand.h"

class CommandInvoker
{
public:
    CommandInvoker();

    int Initialize();
    E_COMMAND_TYPE IsCommand(const std::string &input);
    bool ExecuteCommand(const std::string& input, E_COMMAND_TYPE cmdType);
    bool StopCommand(E_COMMAND_TYPE cmdType);
    std::list<std::string> GetResult(E_COMMAND_TYPE cmdType);

private:
    std::map<int,std::unique_ptr<IVACommand>>      m_DefaultCommands;
    std::map<int,std::unique_ptr<IVACommand>>      m_CustomCommands;
};

#endif // COMMANDINVOKER_H
