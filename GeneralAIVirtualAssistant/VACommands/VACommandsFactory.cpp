#include "VACommandsFactory.h"
#include "VADefaultStartAppCommand.h"
#include "VADefaultOpenDocumentCommand.h"
#include "VADefaultPlayAudioCommand.h"
#include "VADefaultPlayVideoCommand.h"
#include "VADefaultViewPictureCommand.h"
#include "VAWebWikiSearchCommand.h"

IVACommand *VACommandsFactory::CreateVACommand(E_COMMAND_TYPE commandType)
{
    switch(commandType){
        case E_COMMAND_TYPE::CUSTOM: return nullptr;
        case E_COMMAND_TYPE::START_APP: return new VADefaultStartAppCommand;
        case E_COMMAND_TYPE::OPEN_DOC: return new VADefaultOpenDocumentCommand;
        case E_COMMAND_TYPE::PLAY_AUD: return new VADefaultPlayAudioCommand;
        case E_COMMAND_TYPE::PLAY_VID: return new VADefaultPlayVideoCommand;
        case E_COMMAND_TYPE::VIEW_PIC: return new VADefaultViewPictureCommand;
        case E_COMMAND_TYPE::FIND_WIKI: return new VAWebWikiSearchCommand;
        default: return nullptr;
    }
}
