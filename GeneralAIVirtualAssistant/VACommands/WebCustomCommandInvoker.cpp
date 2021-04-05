#include "WebCustomCommandInvoker.h"

#include "../Data/Enums.h"
#include "../Data/Defines.h"
#include "VACommandsFactory.h"

#include <QDir>

int WebCustomCommandInvoker::Initialize()
{
    U_COMMAND_TYPE uCmdType;

    QString currentPath = QDir::currentPath();
    QString customLocalCmdsPath = currentPath + CUSTOM_CMDS_PATH + CUSTOM_WEB_CMDS;

    QDir cmdsDir(customLocalCmdsPath);

    if (cmdsDir.exists()){
        QDir::setCurrent(customLocalCmdsPath);
        QStringList customCmdsFiles = cmdsDir.entryList(QStringList() << "*.json" << "*.JSON", QDir::Files);
        uCmdType.webCmdType = E_WEB_COMMAND_TYPE::CUSTOM;

        for (QString filename: customCmdsFiles) {
            std::shared_ptr<IVACommand> customCmd;
            customCmd.reset(VACommandsFactory::CreateVACommand(E_VA_TYPE::WEB, uCmdType.nVal));

            if (!customCmd || !customCmd->Initialize(filename.toLocal8Bit().data())) continue;
            m_CustomCommands[customCmd->GetCommandID()] = customCmd;
        }
        QDir::setCurrent(currentPath);
    }

    return 1;
}

int WebCustomCommandInvoker::IsCommand(const std::string &input)
{
    U_COMMAND_TYPE uCmdType;
    uCmdType.webCmdType = E_WEB_COMMAND_TYPE::UNDEFINED;

    for(auto command: m_CustomCommands)
    {
        if (command.second->ContainsCommand(input)){
            return command.second->GetCommandID();
        }
    }

    return uCmdType.nVal;
}

bool WebCustomCommandInvoker::ExecuteCommand(const std::string &input, int cmdType)
{
    U_COMMAND_TYPE uCmdType;
    uCmdType.nVal = cmdType;

    if (E_WEB_COMMAND_TYPE::UNDEFINED == uCmdType.webCmdType) return false;

    return m_CustomCommands[uCmdType.nVal]->ExecuteCommand(input);
}

bool WebCustomCommandInvoker::StopCommand(int cmdType)
{
    U_COMMAND_TYPE uCmdType;
    uCmdType.nVal = cmdType;

    if (E_WEB_COMMAND_TYPE::UNDEFINED == uCmdType.webCmdType) return false;

    return m_CustomCommands[uCmdType.nVal]->StopCommand();
}

std::string WebCustomCommandInvoker::GetResult(int cmdID)
{
    return m_CustomCommands[cmdID]->GetCommandResult();
}
