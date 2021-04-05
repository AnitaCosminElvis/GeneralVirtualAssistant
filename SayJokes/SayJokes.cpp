#include "SayJokes.h"
#include "libnative_api.h"

libnative_ExportedSymbols* lib = libnative_symbols();

int Initialize()
{
    return lib->kotlin.root.kotlinExample.Initialize();
}

bool StopCommand()
{
    return lib->kotlin.root.kotlinExample.StopCommand();
}

bool ExecuteCommand(const std::string &input)
{
    return  lib->kotlin.root.kotlinExample.ExecuteCommand(input.data());
}

bool ContainsCommand(const std::string &input)
{
    return lib->kotlin.root.kotlinExample.ContainsCommand(input.data());
}

std::string GetCommandResult()
{
    return lib->kotlin.root.kotlinExample.GetCommandResult();
}
