#include "SpeechToTextWrapper.h"

SpeechToTextWrapper::SpeechToTextWrapper()
{
    ibmWatsonSpeechToText.reset(new IBMWatsonSpeechToText);
}

int SpeechToTextWrapper::Initialize()
{
    return ibmWatsonSpeechToText->Initialize();
}

std::string SpeechToTextWrapper::ConvertSpeechToText()
{
    return ibmWatsonSpeechToText->ConvertSpeechToText();
}
