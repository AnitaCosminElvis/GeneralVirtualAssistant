#ifndef WEBCUSTOMCOMMANDINVOKER_H
#define WEBCUSTOMCOMMANDINVOKER_H

#include <string>
#include <memory>

#include <map>

#include "IVACommand.h"
#include "ICommandInvoker.h"

class WebCustomCommandInvoker : public ICommandInvoker
{
public:
    int Initialize() override;
    int IsCommand(const std::string &input) override;
    bool ExecuteCommand(const std::string& input, int cmdType) override;
    bool StopCommand(int cmdType) override;
    std::string GetResult(int cmdID) override;

private:
    std::map<int,std::shared_ptr<IVACommand>>      m_CustomCommands;
};

#endif // WEBCUSTOMCOMMANDINVOKER_H
