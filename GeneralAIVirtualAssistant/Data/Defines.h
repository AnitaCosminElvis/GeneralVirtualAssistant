#ifndef DEFINES_H
#define DEFINES_H

#include <string>
#include <list>

#define AIML_DIRECTORY              "AIML"
#define LEGAL_AGE                   18
#define VA_UNINIT                   "Uninitialized"
#define VA_RET_UNINIT               -1
#define VA_CMD_SUCCESS              "Command succeeded!"
#define VA_STOP_CMD_SUCCESS         "Stop Command succeeded!"
#define STOP_PATTERN                "stop"
#define VA_CMD_FAIL                 "Unable to execute command!"
#define VA_CMD_PARTIAL              "Command partially executed!"
#define VA_SORRY                    "Sorry, could you repeat?"
#define VA_NOT_FOUND                "I couldn't find any information on "

#define MODELDIR                    "C:/Users/selectuls/Desktop/pocketsphinx/model/"
#define DATA_PATH                   "/Data"
#define CUSTOM_CMDS_PATH            "/CustomCommands/"
#define CUSTOM_WEB_CMDS             "CustomWebCmds/"
#define CUSTOM_LOCAL_CMDS           "CustomLocalCmds/"
#define RECORD_PATH                 "/record.wav"
#define AUDIO_SET_PATH              "/audioRecordSettings.json"
#define SAFE_LIST_PATH              "/safeListSettings.json"

typedef int                         pInitialize();
typedef bool                        pContainsCommand(const std::string &input);
typedef bool                        pExecuteCommand(const std::string &input);
typedef bool                        pStopCommand();
typedef std::string                 pGetCommandResult();

#endif // DEFINES_H
