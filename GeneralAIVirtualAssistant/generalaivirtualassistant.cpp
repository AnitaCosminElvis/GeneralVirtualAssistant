#include "generalaivirtualassistant.h"


GeneralAIVirtualAssistant::GeneralAIVirtualAssistant()
{
    unqLocalVA.reset(VirtualAssistanFactoryMethod::CreateVirtualAssistant(E_VA_TYPE::LOCAL));
    unqLocalVA->Initialize();

    unqWebVA.reset(VirtualAssistanFactoryMethod::CreateVirtualAssistant(E_VA_TYPE::WEB));
    unqWebVA->Initialize();
}

std::string GeneralAIVirtualAssistant::GetLocalResponse(const std::string& input)
{
    return unqLocalVA->GetResponse(input);
}

std::string GeneralAIVirtualAssistant::GetWebResponse(const std::string&)
{
    return unqWebVA->GetResponse("");
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
