#ifndef SPEECHTOTEXTFACTORY_H
#define SPEECHTOTEXTFACTORY_H

#include "ISpeechToText.h"
#include "Data/Enums.h"

class SpeechToTextFactory
{
public:
    static ISpeechToText* CreateSpeechToTextObj(E_SPEECH_TO_TEXT_TYPE type);
};

#endif // SPEECHTOTEXTFACTORY_H
