#include "webvirtualassistant.h"

WebVirtualAssistant::WebVirtualAssistant()
{

}
WebVirtualAssistant::~WebVirtualAssistant()
{
    delete spToTxt;
}

bool WebVirtualAssistant::Initialize()
{
    spToTxt = new IBMWatsonSpeechToTextWrapper;
    spToTxt->Initialize();
    return true;
}

std::string WebVirtualAssistant::GetResponse(const std::string & )
{
    return spToTxt->ConvertSpeechToText(nullptr);
}
