#ifndef GENERALAIVIRTUALASSISTANT_H
#define GENERALAIVIRTUALASSISTANT_H

#include "GeneralAIVirtualAssistant_global.h"
#include "Data/Defines.h"
#include <QMap>
#include <QString>
#include "virtualassistanfactorymethod.h"
#include "ivirtualassistant.h"
#include <memory>

class GENERALAIVIRTUALASSISTANT_EXPORT GeneralAIVirtualAssistant
{
public:
    GeneralAIVirtualAssistant();

    std::string GetLocalResponse(const std::string&);

    std::string GetWebResponse(const std::string&);

    std::string ConvertSpeechToText(void*, int size);

    void ConvertTextToSpeech(const std::string&);

    bool AddBlackListItem(const std::string&);
    bool RemoveBlackListItem(const std::string&);

    bool ExecuteCommand(const std::string&);

    bool SetupProfileData(const std::string& name, int age);
private:
    QMap<QString,QString>   m_qChatHistoryMap;
    std::unique_ptr<IVirtualAssistant> unqLocalVA;
    std::unique_ptr<IVirtualAssistant> unqWebVA;

};

#endif // GENERALAIVIRTUALASSISTANT_H
