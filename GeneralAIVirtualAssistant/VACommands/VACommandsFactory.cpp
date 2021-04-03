#include "VACommandsFactory.h"
#include "VADefaultStartAppCommand.h"
#include "VADefaultOpenDocumentCommand.h"
#include "VADefaultPlayAudioCommand.h"
#include "VADefaultPlayVideoCommand.h"
#include "VADefaultViewPictureCommand.h"
#include "VAWebWikiSearchCommand.h"
#include "VADuckDuckGoSearchCommand.h"

IVACommand *VACommandsFactory::CreateVACommand(E_COMMAND_INVOKER_TYPE invokerType, int commandType)
{
    switch (invokerType) {
        case E_COMMAND_INVOKER_TYPE::LOCAL:
            U_LOCAL_COMMAND_TYPE localCmdType;
            localCmdType.nVal = commandType;
            switch(localCmdType.command_type){
                case E_LOCAL_COMMAND_TYPE::CUSTOM: return nullptr;
                case E_LOCAL_COMMAND_TYPE::START_APP: return new VADefaultStartAppCommand;
                case E_LOCAL_COMMAND_TYPE::OPEN_DOC: return new VADefaultOpenDocumentCommand;
                case E_LOCAL_COMMAND_TYPE::PLAY_AUD: return new VADefaultPlayAudioCommand;
                case E_LOCAL_COMMAND_TYPE::PLAY_VID: return new VADefaultPlayVideoCommand;
                case E_LOCAL_COMMAND_TYPE::VIEW_PIC: return new VADefaultViewPictureCommand;
                default: return nullptr;
            }
            break;
        case E_COMMAND_INVOKER_TYPE::WEB:
            U_WEB_COMMAND_TYPE webCmdType;
            webCmdType.nVal = commandType;
            switch(webCmdType.command_type){
                case E_WEB_COMMAND_TYPE::CUSTOM: return nullptr;
                case E_WEB_COMMAND_TYPE::FIND_WIKI: return new VAWebWikiSearchCommand;
                case E_WEB_COMMAND_TYPE::DUCK_DUCK_GO: return new VADuckDuckGoSearchCommand;
                default: return nullptr;
            }
            break;
        default: return nullptr;

    }

}
