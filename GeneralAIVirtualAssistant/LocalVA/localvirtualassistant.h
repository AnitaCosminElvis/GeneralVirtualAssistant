#ifndef LOCALVIRTUALASSISTANT_H
#define LOCALVIRTUALASSISTANT_H

#include "ivirtualassistant.h"
#include "aimlparser.h"
#include "SpeechTextIO/ITextToSpeech.h"
#include "SpeechTextIO/generaltexttospeechwrapper.h"
#include "../Data/Defines.h"

class LocalVirtualAssistant : public IVirtualAssistant
{
public:
    LocalVirtualAssistant();
    ~LocalVirtualAssistant();

    bool Initialize() override;
    std::string GetResponse(const std::string&) override;

private:
    AIMLParser*     m_pAimlParser = nullptr;
    ITextToSpeech*  m_pTextToSpeech = nullptr;
};

#endif // LOCALVIRTUALASSISTANT_H
