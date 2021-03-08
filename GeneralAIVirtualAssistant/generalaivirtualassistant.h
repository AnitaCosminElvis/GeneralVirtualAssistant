#ifndef GENERALAIVIRTUALASSISTANT_H
#define GENERALAIVIRTUALASSISTANT_H

#include "GeneralAIVirtualAssistant_global.h"
#include "Data/Defines.h"
#include <QMap>
#include <QString>
#include "virtualassistanfactorymethod.h"
#include "ivirtualassistant.h"
#include "SpeechTextIO/audiorecorder.h"

#include <memory>

class GENERALAIVIRTUALASSISTANT_EXPORT GeneralAIVirtualAssistant
{
public:
    GeneralAIVirtualAssistant();

    std::string GetLocalResponse(std::string& input, bool isRecording = true);

    std::string GetWebResponse(std::string& input, bool isRecording = true);

    int StartRecording();
    void StopRecording();

    bool AddBlackListItem(const std::string&);
    bool RemoveBlackListItem(const std::string&);

    bool ExecuteCommand(const std::string&);

    bool SetupProfileData(const std::string& name, int age);
private:
    QMap<QString,QString>               m_qChatHistoryMap;
    std::unique_ptr<IVirtualAssistant>  m_unqLocalVA;
    std::unique_ptr<IVirtualAssistant>  m_unqWebVA;
    std::unique_ptr<AudioRecorder>      m_unqAudioRecorder;

};

#endif // GENERALAIVIRTUALASSISTANT_H
