#ifndef FILEUTILITY_H
#define FILEUTILITY_H

#include <QString>
#include <QStringList>

class FileUtility
{
public:
    static std::optional<QString> FindAppPathFromInputLists(QStringList qsWords, QStringList qsPaths);
    static std::optional<QString> GetAppLocationFromPath(QString qsFileName, QString qsPath);
};

#endif // FILEUTILITY_H
