#ifndef IVACOMMANDS_H
#define IVACOMMANDS_H
#include <string>
#include "../Data/Enums.h"

#include <list>

class IVACommand
{
public:
    virtual int                         Initialize(const std::string& filePath = "") = 0;
    virtual bool                        ContainsCommand(const std::string& input) = 0;
    virtual bool                        ExecuteCommand(const std::string& input) = 0;
    virtual bool                        StopCommand() = 0;
    virtual int                         GetCommandType() = 0;
    virtual int                         GetCommandID() = 0;
    virtual std::string                 GetCommandResult() = 0;

    virtual~ IVACommand() = default;
};



#endif // IVACOMMANDS_H
