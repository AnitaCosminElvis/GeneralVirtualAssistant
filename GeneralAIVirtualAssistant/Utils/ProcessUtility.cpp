#include "ProcessUtility.h"
#include <QProcess>
#include <memory>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>

bool ProcessUtility::StartApplicationByPath(QString qsAppPath)
{
    if (!QFile::exists(qsAppPath)) return false;

    return StartApplication(qsAppPath);
}

bool ProcessUtility::StartApplication(QString qsApp)
{
    return QDesktopServices::openUrl(QUrl::fromUserInput(qsApp));
}

