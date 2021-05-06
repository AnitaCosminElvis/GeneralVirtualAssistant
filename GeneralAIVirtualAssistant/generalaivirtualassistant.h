#ifndef GENERALAIVIRTUALASSISTANT_H
#define GENERALAIVIRTUALASSISTANT_H

#include "GeneralAIVirtualAssistant_global.h"
#include "Data/Defines.h"
#include <QMap>
#include <QString>
#include "virtualassistantfactorymethod.h"
#include "ivirtualassistant.h"
#include "SpeechTextIO/AudioRecorderWrapper.h"
#include "InputFilter.h"
#include "SpeechTextIO/ITextToSpeech.h"
#include "SpeechTextIO/ISpeechToText.h"

#include <memory>

class GENERALAIVIRTUALASSISTANT_EXPORT GeneralAIVirtualAssistant
{
public:
    GeneralAIVirtualAssistant();

    bool Initialize();

    std::string GetLocalResponse(std::string& input, bool isRecording = true);

    std::string GetWebResponse(std::string& input, bool isRecording = true);

    int StartRecording();
    void StopRecording();

private:
    std::unique_ptr<IVirtualAssistant>      m_unqLocalVA;
    std::unique_ptr<IVirtualAssistant>      m_unqWebVA;
    std::unique_ptr<AudioRecorderWrapper>   m_unqAudioRecorder;
    std::unique_ptr<InputFilter>            m_InputFilter;
    std::unique_ptr<ITextToSpeech>          m_pTextToSpeech;
    std::unique_ptr<ISpeechToText>          m_pSpeechToText;

};

#endif // GENERALAIVIRTUALASSISTANT_H
