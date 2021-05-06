#ifndef TEXTTOSPEECHFACTORY_H
#define TEXTTOSPEECHFACTORY_H

#include "ITextToSpeech.h"
#include "Data/Enums.h"

class TextToSpeechFactory{
public:
    static ITextToSpeech *CreateTextToSpeechObj(E_TEXT_TO_SPEECH_TYPE type);
};

#endif // TEXTTOSPEECHFACTORY_H
