#ifndef GENERALSPEECHTOTEXTWRAPPER_H
#define GENERALSPEECHTOTEXTWRAPPER_H

#include "ISpeechToText.h"

class SpeechToTextWrapper: public ISpeechToText
{
public:
    SpeechToTextWrapper();

    int Initialize() override;
    std::string ConvertSpeechToText() override;
};

#endif // GENERALSPEECHTOTEXTWRAPPER_H
