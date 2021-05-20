#include "FileUtility.h"

#include <QDirIterator>

std::optional<QString> FileUtility::FindAppPathFromInputLists(QStringList qsWords, QStringList qsPaths)
{
    for (int i = 0; i < qsWords.count(); i++){
        foreach(auto path, qsPaths){
            auto qsFileLocation = GetAppLocationFromPath(qsWords[i],path);
            if (qsFileLocation.has_value() && !qsFileLocation.value().isEmpty()) return qsFileLocation;
        }
    }

    return {};
}

std::optional<QString> FileUtility::GetAppLocationFromPath(QString qsFileName, QString qsPath){
    QDirIterator it(qsPath, QDirIterator::Subdirectories);

    // Iterate through the directory using the QDirIterator
    while (it.hasNext()) {
        QString filename = it.next();
        QFileInfo file(filename);

        if (file.isDir()) { // Check if it's a dir
            continue;
        }

        // If the filename contains target string - put it in the hitlist
        if (file.fileName().contains(qsFileName, Qt::CaseInsensitive)) {
            if (file.isSymLink()) return file.symLinkTarget();
            else return file.absoluteFilePath();
        }
    }

    return {};
}
