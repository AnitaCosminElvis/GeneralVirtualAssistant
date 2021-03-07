#ifndef CHATMODEL_H
#define CHATMODEL_H

#include <QAbstractTableModel>
#include <QFont>
#include "Data/Defines.h"

class GeneralAIVirtualAssistant;
class ChatModel: public QAbstractTableModel
{
    Q_OBJECT

public:
    ChatModel(QObject *parent = nullptr);
    ~ChatModel();

    QString GetLocalResponse(const QString& qsMessage);
    QString GetWebResponse(const QString& audioMsg);

    int PushChatMessage(const bool isFromBot, const QString& qsMessage);
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QList <QPair<QString, QString>>     m_data;
    QString                             m_CurrentSender;
    QString                             m_CurrentMsg;
    GeneralAIVirtualAssistant*          m_pVirtualAssistant = nullptr;
};

#endif // CHATMODEL_H