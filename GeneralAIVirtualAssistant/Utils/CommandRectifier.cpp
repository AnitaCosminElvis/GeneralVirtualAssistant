#include "CommandRectifier.h"
#include <QRegExp>

QStringList CommandRectifier::GetSanitizedCommand(const S_BASE_COMMAND_DATA &cmdData, const QString& input)
{
    QStringList words = input.split(QLatin1Char(' '), Qt::SkipEmptyParts);
    QStringList bufferList;
    QRegExp regExp("*" + cmdData.qsResourceType + "*");
    regExp.setPatternSyntax(QRegExp::Wildcard);
    regExp.setCaseSensitivity(Qt::CaseInsensitive);

    if (words.size() >= cmdData.nMinWordCount && input.contains(cmdData.qsVerbCommand,Qt::CaseInsensitive)){
        int endOfCmdIndex = words.indexOf(regExp);
        if ((-1 != endOfCmdIndex) && ((words.count() - 1) > endOfCmdIndex)){
            bufferList += cmdData.qsVerbCommand;
            bufferList += cmdData.qsResourceType;
            for (int i = endOfCmdIndex + 1; i < words.count(); ++i) bufferList += words[i];
        }
    }

    return bufferList;
}

QStringList CommandRectifier::GetSanitizedCommandArgs(const S_BASE_COMMAND_DATA &cmdData, const QString &input)
{
    QStringList words = input.split(QLatin1Char(' '), Qt::SkipEmptyParts);
    QStringList bufferList;
    QRegExp regExp("*" + cmdData.qsResourceType + "*");
    regExp.setPatternSyntax(QRegExp::Wildcard);
    regExp.setCaseSensitivity(Qt::CaseInsensitive);

    if (words.size() >= cmdData.nMinWordCount && input.contains(cmdData.qsVerbCommand,Qt::CaseInsensitive)){
        int endOfCmdIndex = words.indexOf(regExp);
        if ((-1 != endOfCmdIndex) && ((words.count() - 1) > endOfCmdIndex)){
            for (int i = endOfCmdIndex + 1; i < words.count(); ++i) bufferList += words[i];
        }
    }

    return bufferList;
}
