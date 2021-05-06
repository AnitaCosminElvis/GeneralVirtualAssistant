#include "SpeechToTextFactory.h"
#include "SpeechToTextWrapper.h"
#include "IBMWatsonSpeechToText.h"

ISpeechToText *SpeechToTextFactory::CreateSpeechToTextObj(E_SPEECH_TO_TEXT_TYPE type)
{
    switch(type){
        case E_SPEECH_TO_TEXT_TYPE::LOCAL: return new SpeechToTextWrapper;
        case E_SPEECH_TO_TEXT_TYPE::IBM_WATSON: return new IBMWatsonSpeechToText;
        default: return nullptr;
    }
}
