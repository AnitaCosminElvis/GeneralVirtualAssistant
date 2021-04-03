#include "generalaivirtualassistant.h"
#include "SpeechTextIO/TextToSpeechWrapper.h"
#include "SpeechTextIO/SpeechToTextWrapper.h"

GeneralAIVirtualAssistant::GeneralAIVirtualAssistant()
{
    m_unqLocalVA.reset(VirtualAssistanFactoryMethod::CreateVirtualAssistant(E_VA_TYPE::LOCAL));
    m_unqWebVA.reset(VirtualAssistanFactoryMethod::CreateVirtualAssistant(E_VA_TYPE::WEB));
    m_unqAudioRecorder.reset(new AudioRecorder);
    m_InputFilter.reset(new InputFilter);

    m_pTextToSpeech.reset(new TextToSpeechWrapper);
    m_pSpeechToText.reset(new SpeechToTextWrapper);
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

bool GeneralAIVirtualAssistant::SetupProfileData(const std::string& name, int age){

    QString qsAgeDirectory;

    if (LEGAL_AGE <= age)
    {
        qsAgeDirectory = QString("ADULT");
    }else{
        qsAgeDirectory = QString("NONADULT");
    }

//    QCryptographicHash md5Gen(QCryptographicHash::Md5);
//    md5Gen.addData(qsUserInput.toLocal8Bit());

//    QCryptographicHash md5Gen1(QCryptographicHash::Md5);
//    md5Gen1.addData(qsBotResponse.toLocal8Bit());

//    m_qChatHistoryMap.insert(QString(md5Gen.result().toHex()),qsUserInput);
//    m_qChatHistoryMap.insert(QString(md5Gen1.result().toHex()),qsBotResponse);


    return true;
}

//void GeneralAIVirtualAssistant::LoadChatHistory()
//{
//    QString qsPathByUserData;
//    qsPathByUserData = qApp->applicationDirPath() + QString("/UserData/") + m_qsName
//            + m_qsOccupation + QString::number(m_nAge);
//    QSettings qSettings(qsPathByUserData,QSettings::IniFormat);

//    QStringList qsList = qSettings.allKeys();

//    foreach (const QString &key, qsList)
//    {
//        m_qChatHistoryMap.insert(key,qSettings.value(key).toString());
//    }
//}

//void GeneralAIVirtualAssistant::SaveChatHistory()
//{
//    QString qsPathByUserData;
//    qsPathByUserData = qApp->applicationDirPath() + QString("/UserData/") + m_qsName
//                        + m_qsOccupation + QString::number(m_nAge);
//    QSettings qSettings(qsPathByUserData,QSettings::IniFormat);

//    QList<QString>qList =  m_qChatHistoryMap.keys();

//    foreach (const QString &key, qList)
//    {
//        qSettings.setValue(key,m_qChatHistoryMap.value(key));
//        qSettings.sync();
//    }
//}
