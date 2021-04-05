#include "VAAbstractResourceFileCommand.h"
#include <QDir>
#include <QDirIterator>
#include <memory>
#include <QProcess>
#include "../Utils/FileUtility.h"
#include "../Utils/ProcessUtility.h"
#include "../Data/Defines.h"

VAAbstractResourceFileCommand::VAAbstractResourceFileCommand()
{

}

bool VAAbstractResourceFileCommand::ContainsCommand(const std::string &input)
{
    if (input.empty()) return false;

    QString qsInput = input.data();

    if (!qsInput.startsWith(m_BaseCmdData.qsVerbCommand,Qt::CaseInsensitive)) return false;
    if (!qsInput.contains(m_BaseCmdData.qsResourceType,Qt::CaseInsensitive)) return false;

    return true;
}

bool VAAbstractResourceFileCommand::ExecuteCommand(const std::string &input)
{
    QString qsInput = input.data();
    QStringList words = qsInput.split(QLatin1Char(' '), Qt::SkipEmptyParts);

    if (words.count() >= m_BaseCmdData.nMinWordCount){
        if ((words[0].startsWith(m_BaseCmdData.qsVerbCommand)) && (words[1].startsWith(m_BaseCmdData.qsResourceType)))
        {
            auto paths = QStandardPaths::standardLocations(m_StdLocation);

            auto path = FileUtility::FindAppPathFromInputLists(words, paths);

            if (path.has_value() && !path.value().isEmpty()){
                return ProcessUtility::StartApplicationByPath(path.value());
            }
        }
    }

    return false;
}

bool VAAbstractResourceFileCommand::StopCommand()
{
    return true;
}

int VAAbstractResourceFileCommand::GetCommandType()
{
    return m_BaseCmdData.cmdType;
}

int VAAbstractResourceFileCommand::GetCommandID()
{
    return m_BaseCmdData.cmdType;
}

std::string VAAbstractResourceFileCommand::GetCommandResult()
{
    return m_result;
}
