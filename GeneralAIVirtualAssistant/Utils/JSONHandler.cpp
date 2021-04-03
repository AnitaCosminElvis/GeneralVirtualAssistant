#include "JSONHandler.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>

JSONHandler::JSONHandler()
{

}

bool JSONHandler::LoadJSONFromSettingsFile(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) return false;

    m_JSONDoc = QJsonDocument::fromJson(file.readAll());

    file.close();

    return !m_JSONDoc.isNull();
}

bool JSONHandler::LoadJSONFromString(QString in)
{
    m_JSONDoc = QJsonDocument::fromJson(in.toUtf8());

    return !m_JSONDoc.isNull();
}

bool JSONHandler::WriteJSONToSettingsFile(QString path)
{
    QFile file(path);

    if (!file.open(QIODevice::ReadWrite)) return false;

    QTextStream outStream(&file);

    outStream << m_JSONDoc.toJson();

    file.close();

    return true;
}

QString JSONHandler::JSONToString()
{
    return m_JSONDoc.toJson();
}

QString JSONHandler::GetValueByJSONPath(QList<QString> jsonPath)
{
    return GetJSONValByPath(jsonPath, m_JSONDoc.object());
}

QStringList JSONHandler::GetArrayValuesByJSONPath(QList<QString> jsonPath)
{
    return GetJSONArrayValsByPath(jsonPath, m_JSONDoc.object());
}

bool JSONHandler::SetValueByJSONPath(QList<QString> jsonPath, QString keyVal)
{
    m_ValToSet = keyVal;

    return SetJSONValByPath(jsonPath, m_JSONDoc.object());
}

QString JSONHandler::GetJSONValByPath(QList<QString> jsonPath, QJsonObject jsonObj)
{
    if (0 == jsonPath.size()) return "";

    QString key = jsonPath.front();

    if ("." != key && !jsonObj.contains(key)) return "";

    jsonPath.removeFirst();

    if (key == "."){
        QJsonObject firstObj = jsonObj.begin().value().toObject();
        return GetJSONValByPath(jsonPath, firstObj);
    }else if (jsonObj[key].isObject()){
        return GetJSONValByPath(jsonPath, jsonObj[key].toObject());
    }else if (jsonObj[key].isArray()){
        return GetJSONValByPath(jsonPath, jsonObj[key].toArray().at(0).toObject());
    }else if (jsonObj[key].isUndefined()){
        return "";
    }else{
        return jsonObj[key].toString("");
    }
}

QStringList JSONHandler::GetJSONArrayValsByPath(QList<QString> jsonPath, QJsonObject jsonObj)
{
    if (0 == jsonPath.size()) return {""};

    QString key = jsonPath.front();

    if ("." != key && !jsonObj.contains(key)) return {""};

    jsonPath.removeFirst();

    if (jsonPath.isEmpty()){
        if (jsonObj[key].isArray()){
            auto arr = jsonObj[key].toArray();
            QStringList list;
            for (auto element: arr){
                list += element.toString();
            }
            return list;
        }else{
            return {""};
        }

    }else if (key == "."){
        QJsonObject firstObj = jsonObj.begin().value().toObject();
        return GetJSONArrayValsByPath(jsonPath, firstObj);
    }else if (jsonObj[key].isObject()){
        return GetJSONArrayValsByPath(jsonPath, jsonObj[key].toObject());
    }else if (jsonObj[key].isArray()){
        return GetJSONArrayValsByPath(jsonPath, jsonObj[key].toArray().at(0).toObject());
    }else{
        return {""};
    }
}

bool JSONHandler::SetJSONValByPath(QList<QString> jsonPath, QJsonObject jsonObj)
{
    if (0 == jsonPath.size()) return "";

    QString key = jsonPath.front();

    if ("." != key && !jsonObj.contains(key)) return "";

    jsonPath.removeFirst();

    if (jsonPath.isEmpty()){
        jsonObj[key] = m_ValToSet;
        m_ValToSet.clear();
    }else if (key == "."){
        QJsonObject firstObj = jsonObj.begin().value().toObject();
        return SetJSONValByPath(jsonPath, firstObj);
    }else if (jsonObj[key].isObject()){
        return SetJSONValByPath(jsonPath, jsonObj[key].toObject());
    }else if (jsonObj[key].isArray()){
        return SetJSONValByPath(jsonPath, jsonObj[key].toArray().at(0).toObject());
    }else{
        return false;
    }

    return false;
}
