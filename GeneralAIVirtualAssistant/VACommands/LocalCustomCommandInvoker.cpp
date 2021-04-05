#include "LocalCustomCommandInvoker.h"
#include "../Data/Enums.h"
#include "../Data/Defines.h"
#include "VACommandsFactory.h"

#include <QDir>

int LocalCustomCommandInvoker::Initialize()
{
    U_COMMAND_TYPE uCmdType;

    QString currentPath = QDir::currentPath();
    QString customLocalCmdsPath = currentPath + CUSTOM_CMDS_PATH + CUSTOM_LOCAL_CMDS;

    QDir cmdsDir(customLocalCmdsPath);

    if (cmdsDir.exists()){
        QDir::setCurrent(customLocalCmdsPath);
        QStringList customCmdsFiles = cmdsDir.entryList(QStringList() << "*.json" << "*.JSON", QDir::Files);
        uCmdType.localCmdType = E_LOCAL_COMMAND_TYPE::CUSTOM;

        for (QString filename: customCmdsFiles) {
            std::shared_ptr<IVACommand> customCmd;
            customCmd.reset(VACommandsFactory::CreateVACommand(E_VA_TYPE::LOCAL, uCmdType.nVal));

            if (!customCmd || !customCmd->Initialize(filename.toLocal8Bit().data())) continue;
            m_CustomCommands[customCmd->GetCommandID()] = customCmd;
        }
        QDir::setCurrent(currentPath);
    }

    return 1;
}

int LocalCustomCommandInvoker::IsCommand(const std::string &input)
{
    U_COMMAND_TYPE uCmdType;
    uCmdType.localCmdType = E_LOCAL_COMMAND_TYPE::UNDEFINED;

    for(auto& command: m_CustomCommands)
    {
        if (command.second->ContainsCommand(input)){
            return command.second->GetCommandID();
        }
    }

    return uCmdType.nVal;
}

bool LocalCustomCommandInvoker::ExecuteCommand(const std::string &input, int cmdType)
{
    U_COMMAND_TYPE uCmdType;
    uCmdType.nVal = cmdType;

    if (E_LOCAL_COMMAND_TYPE::UNDEFINED == uCmdType.localCmdType) return false;

    return m_CustomCommands[uCmdType.nVal]->ExecuteCommand(input);
}

bool LocalCustomCommandInvoker::StopCommand(int cmdType)
{
    U_COMMAND_TYPE uCmdType;
    uCmdType.nVal = cmdType;

    if (E_LOCAL_COMMAND_TYPE::UNDEFINED == uCmdType.localCmdType) return false;

    return m_CustomCommands[uCmdType.nVal]->StopCommand();
}

std::string LocalCustomCommandInvoker::GetResult(int cmdID)
{
    return m_CustomCommands[cmdID]->GetCommandResult();
}
