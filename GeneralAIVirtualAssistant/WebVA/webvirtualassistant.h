#ifndef WEBVIRTUALASSISTANT_H
#define WEBVIRTUALASSISTANT_H

#include "../ivirtualassistant.h"
#include "../Data/Defines.h"
#include "SpeechTextIO/IBMWatsonSpeechToTextWrapper.h"

class WebVirtualAssistant : public IVirtualAssistant
{
public:
    WebVirtualAssistant();
    ~WebVirtualAssistant();

    bool Initialize() override;
    std::string GetResponse(const std::string&) override;
private:
    IBMWatsonSpeechToTextWrapper*    spToTxt = nullptr;
};

#endif // WEBVIRTUALASSISTANT_H
