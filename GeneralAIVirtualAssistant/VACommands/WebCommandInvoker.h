#ifndef WEBCOMMANDINVOKER_H
#define WEBCOMMANDINVOKER_H

#include <string>
#include <memory>

#include <map>

#include "IVACommand.h"
#include "ICommandInvoker.h"

class WebCommandInvoker : public ICommandInvoker
{
public:
    WebCommandInvoker();

    ~WebCommandInvoker();

    int Initialize() override;
    int IsCommand(const std::string &input) override;
    bool ExecuteCommand(const std::string& input, int cmdType) override;
    bool StopCommand(int cmdType) override;
    std::list<std::string> GetResult(int cmdType) override;

private:
    std::map<int,std::unique_ptr<IVACommand>>      m_DefaultCommands;
    std::map<int,std::unique_ptr<IVACommand>>      m_CustomCommands;
};

#endif // WEBCOMMANDINVOKER_H