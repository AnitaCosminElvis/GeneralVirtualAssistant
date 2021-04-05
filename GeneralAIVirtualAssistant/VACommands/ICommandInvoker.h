#ifndef ICOMMANDINVOKER_H
#define ICOMMANDINVOKER_H

#include <string>
#include <list>

class ICommandInvoker
{
public:
    virtual int Initialize() = 0;
    virtual int IsCommand(const std::string &input) = 0;
    virtual bool ExecuteCommand(const std::string& input, int cmdType) = 0;
    virtual bool StopCommand(int cmdType) = 0;
    virtual std::string GetResult(int cmdType) = 0;

    virtual~ ICommandInvoker() = default;
};

#endif // ICOMMANDINVOKER_H
