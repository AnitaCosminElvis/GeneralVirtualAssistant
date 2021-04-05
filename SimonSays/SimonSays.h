#ifndef SIMONSAYS_H
#define SIMONSAYS_H

#include "SimonSays_global.h"
#include <string>

extern "C++" SIMONSAYS_EXPORT int Initialize();
extern "C++" SIMONSAYS_EXPORT bool StopCommand();
extern "C++" SIMONSAYS_EXPORT bool ExecuteCommand(const std::string &input);
extern "C++" SIMONSAYS_EXPORT bool ContainsCommand(const std::string &input);
extern "C++" SIMONSAYS_EXPORT std::string GetCommandResult();

#endif // SIMONSAYS_H
