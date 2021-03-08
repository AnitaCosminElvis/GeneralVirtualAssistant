#ifndef GENERALSPEECHTOTEXTWRAPPER_H
#define GENERALSPEECHTOTEXTWRAPPER_H

#include "ISpeechToText.h"
#include "IBMWatsonSpeechToText.h"
#include <memory.h>

class SpeechToTextWrapper: public ISpeechToText
{
public:
    SpeechToTextWrapper();

    int Initialize() override;
    std::string ConvertSpeechToText() override;

private:
    std::unique_ptr<IBMWatsonSpeechToText> ibmWatsonSpeechToText;
};

#endif // GENERALSPEECHTOTEXTWRAPPER_H
