#include "SimonSays.h"
#include <QString>
#define SIMON_SAYS "Simon Says"

std::string response;


int Initialize()
{
    return 1;
}

bool StopCommand()
{
    return true;
}

bool ExecuteCommand(const std::string &input)
{
    response = input;
    return  true;
}

bool ContainsCommand(const std::string &input)
{
    QString response = input.data();
    return (response.contains(SIMON_SAYS, Qt::CaseInsensitive))? true: false;
}

std::string GetCommandResult()
{
    return response;
}
