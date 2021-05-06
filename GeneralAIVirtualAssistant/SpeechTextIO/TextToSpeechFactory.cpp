#include "TextToSpeechFactory.h"
#include "TextToSpeechWrapper.h"

ITextToSpeech *TextToSpeechFactory::CreateTextToSpeechObj(E_TEXT_TO_SPEECH_TYPE type)
{
    switch(type){
        case E_TEXT_TO_SPEECH_TYPE::LOCAL: return new TextToSpeechWrapper;
        default: return nullptr;
    }
}
