#include "VAAbstractCustomCommand.h"
#include "../Utils/JSONHandler.h"
#include "../Data/Defines.h"

#include <QDir>

VAAbstractCustomCommand::VAAbstractCustomCommand(): m_cmdID(0)
{
}

VAAbstractCustomCommand::~VAAbstractCustomCommand()
{
    if (m_CmdLib) m_CmdLib->unload();
}

int VAAbstractCustomCommand::Initialize(const std::string & filename)
{
    JSONHandler jsonHandler;
    jsonHandler.LoadJSONFromSettingsFile(QDir::currentPath() + "/" +filename.data());

    m_LibData.libFilename = jsonHandler.GetValueByJSONPath({"DynamicLibraryName"});
    m_LibData.libAbsoluteFilePath = QDir::currentPath() + "/" + m_LibData.libFilename;

    std::string initializeLibFuncName = jsonHandler.GetValueByJSONPath({"Interface","Initialize"}).toLocal8Bit().data();
    std::string stopCommandLibFuncName = jsonHandler.GetValueByJSONPath({"Interface","StopCommand"}).toLocal8Bit().data();
    std::string executeCommandLibFuncName = jsonHandler.GetValueByJSONPath({"Interface","ExecuteCommand"}).toLocal8Bit().data();
    std::string containsCommandLibFuncName = jsonHandler.GetValueByJSONPath({"Interface","ContainsCommand"}).toLocal8Bit().data();
    std::string getCommandResultLibFuncName = jsonHandler.GetValueByJSONPath({"Interface","GetCommandResult"}).toLocal8Bit().data();

    m_cmdID = jsonHandler.GetValueByJSONPath({"CustomCommandID"}).toInt();
    m_CmdLib.reset(new QLibrary(m_LibData.libFilename));
    m_CmdLib->load();

    if (m_CmdLib->isLoaded()){
        m_LibData.customCmdPFunctions.Initialize = reinterpret_cast<pInitialize*>(m_CmdLib->resolve(initializeLibFuncName.data()));
        m_LibData.customCmdPFunctions.StopCommand = reinterpret_cast<pStopCommand*>(m_CmdLib->resolve(stopCommandLibFuncName.data()));
        m_LibData.customCmdPFunctions.ExecuteCommand = reinterpret_cast<pExecuteCommand*>(m_CmdLib->resolve(executeCommandLibFuncName.data()));
        m_LibData.customCmdPFunctions.ContainsCommand = reinterpret_cast<pContainsCommand*>(m_CmdLib->resolve(containsCommandLibFuncName.data()));
        m_LibData.customCmdPFunctions.GetCommandResult = reinterpret_cast<pGetCommandResult*>(m_CmdLib->resolve(getCommandResultLibFuncName.data()));

        if (!m_LibData.customCmdPFunctions.Initialize || !m_LibData.customCmdPFunctions.StopCommand ||
            !m_LibData.customCmdPFunctions.ExecuteCommand || !m_LibData.customCmdPFunctions.ContainsCommand ||
            !m_LibData.customCmdPFunctions.GetCommandResult){
            return 0;
        }
    }else return 0;

    return m_LibData.customCmdPFunctions.Initialize();
}

bool VAAbstractCustomCommand::ContainsCommand(const std::string &input)
{
    if (input.empty()) return false;

    return m_LibData.customCmdPFunctions.ContainsCommand(input);
}

bool VAAbstractCustomCommand::ExecuteCommand(const std::string &input)
{
    if (input.empty()) return false;

    return m_LibData.customCmdPFunctions.ExecuteCommand(input);
}

bool VAAbstractCustomCommand::StopCommand()
{
    return m_LibData.customCmdPFunctions.StopCommand();
}

int VAAbstractCustomCommand::GetCommandType()
{
    return m_CmdType.nVal;
}

int VAAbstractCustomCommand::GetCommandID()
{
    return m_cmdID;
}

std::string VAAbstractCustomCommand::GetCommandResult()
{
    return m_LibData.customCmdPFunctions.GetCommandResult();
}
