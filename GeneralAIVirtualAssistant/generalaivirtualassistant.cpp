#include "generalaivirtualassistant.h"
#include "SpeechTextIO/TextToSpeechWrapper.h"
#include "SpeechTextIO/SpeechToTextWrapper.h"
#include "SpeechTextIO/TextToSpeechFactory.h"
#include "SpeechTextIO/SpeechToTextFactory.h"
#include "Data/Enums.h"

GeneralAIVirtualAssistant::GeneralAIVirtualAssistant()
{
    m_unqLocalVA.reset(VirtualAssistantFactoryMethod::CreateVirtualAssistant(E_VA_TYPE::LOCAL));
    m_unqWebVA.reset(VirtualAssistantFactoryMethod::CreateVirtualAssistant(E_VA_TYPE::WEB));
    m_unqAudioRecorder.reset(new AudioRecorderWrapper);
    m_InputFilter.reset(new InputFilter);

    m_pTextToSpeech.reset(TextToSpeechFactory::CreateTextToSpeechObj(E_TEXT_TO_SPEECH_TYPE::LOCAL));
    m_pSpeechToText.reset(SpeechToTextFactory::CreateSpeechToTextObj(E_SPEECH_TO_TEXT_TYPE::IBM_WATSON));
}

bool GeneralAIVirtualAssistant::Initialize()
{
    if(!m_unqLocalVA->Initialize()) return false;
    if(!m_unqWebVA->Initialize()) return false;
    if(!m_unqAudioRecorder->Initialize()) return false;
    if(!m_InputFilter->Initialize()) return false;
    if(!m_pTextToSpeech->Initialize()) return false;
    if(!m_pSpeechToText->Initialize()) return false;

    return true;
}

std::string GeneralAIVirtualAssistant::GetLocalResponse(std::string& input, bool isRecording)
{
    if (isRecording){
        input = m_pSpeechToText->ConvertSpeechToText();
    }

    std::string response = "Invalid Input!";

    if (m_InputFilter->CanContinue(input.data())) response =  m_unqLocalVA->GetResponse(input);

    if (response == VA_STOP_CMD_SUCCESS || response == VA_CMD_PARTIAL){
        m_pTextToSpeech->Stop();
        m_pTextToSpeech->ConvertTextToSpeech(response);
    }else m_pTextToSpeech->ConvertTextToSpeech(response);

    return response;
}

std::string GeneralAIVirtualAssistant::GetWebResponse(std::string& input, bool isRecording)
{
    if (isRecording){
        input = m_pSpeechToText->ConvertSpeechToText();
    }

    std::string response = "Invalid Input!";

    if (m_InputFilter->CanContinue(input.data())) response =  m_unqWebVA->GetResponse(input);

    if (response == VA_STOP_CMD_SUCCESS || response == VA_CMD_PARTIAL){
        m_pTextToSpeech->Stop();
        m_pTextToSpeech->ConvertTextToSpeech(response);
    }else m_pTextToSpeech->ConvertTextToSpeech(response);

    return response;
}

int GeneralAIVirtualAssistant::StartRecording()
{
    return m_unqAudioRecorder->StartRecording();
}

void GeneralAIVirtualAssistant::StopRecording()
{
    m_unqAudioRecorder->StopRecording();
}

