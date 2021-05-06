#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonDocument>
#include <QString>

#include "../Data/Enums.h"

class JSONHandler
{
public:

    bool LoadJSONFromSettingsFile(QString path);
    bool LoadJSONFromString(QString input);

    bool WriteJSONToSettingsFile(QString path);

    QString JSONToString();
    QString GetValueByJSONPath(QList<QString> jsonPath);
    QStringList GetArrayValuesByJSONPath(QList<QString> jsonPath);
    bool SetValueByJSONPath(QList<QString> jsonPath, QString keyVal);

private:
    QString GetJSONValByPath(QList<QString> jsonPath, QJsonObject jsonObj);
    QStringList GetJSONArrayValsByPath(QList<QString> jsonPath, QJsonObject jsonObj);
    bool SetJSONValByPath(QList<QString> jsonPath, QJsonObject jsonObj);

private:
    QJsonDocument   m_JSONDoc;
    QString         m_ValToSet;
};

#endif // JSONPARSER_H
