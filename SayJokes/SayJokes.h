#ifndef SAYJOKES_H
#define SAYJOKES_H

#include "SayJokes_global.h"
#include <string>

extern "C" SAYJOKES_EXPORT int Initialize();
extern "C" SAYJOKES_EXPORT bool StopCommand();
extern "C" SAYJOKES_EXPORT bool ExecuteCommand(const std::string &input);
extern "C" SAYJOKES_EXPORT bool ContainsCommand(const std::string &input);
extern "C" SAYJOKES_EXPORT std::string GetCommandResult();
#endif // SAYJOKES_H
