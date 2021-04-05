#ifndef COMMANDINVOKER_H
#define COMMANDINVOKER_H

#include <string>
#include <memory>

#include <map>

#include "IVACommand.h"
#include "ICommandInvoker.h"

class LocalDefaultCommandInvoker: public ICommandInvoker
{
public:

    int Initialize() override;
    int IsCommand(const std::string &input) override;
    bool ExecuteCommand(const std::string& input, int cmdType) override;
    bool StopCommand(int cmdType) override;
    std::string GetResult(int cmdType) override;

private:
    std::map<int,std::shared_ptr<IVACommand>>      m_DefaultCommands;
};

#endif // COMMANDINVOKER_H
