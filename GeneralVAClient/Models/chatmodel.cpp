#include "chatmodel.h"
#include "../GeneralAIVirtualAssistant/generalaivirtualassistant.h"

ChatModel::ChatModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    m_pVirtualAssistant = new GeneralAIVirtualAssistant();
}

ChatModel::~ChatModel()
{
    if (m_pVirtualAssistant) delete m_pVirtualAssistant;
}

QString ChatModel::GetLocalResponse(const QString& qsMessage){
    if (m_pVirtualAssistant){
        return m_pVirtualAssistant->GetLocalResponse(qsMessage.toLocal8Bit().data()).data();
    }

    return VA_UNINIT;
}

QString ChatModel::GetWebResponse(const QString& qsMessage){
    if (m_pVirtualAssistant){
        return m_pVirtualAssistant->GetWebResponse(qsMessage.toLocal8Bit().data()).data();
    }

    return VA_UNINIT;
}

int ChatModel::PushChatMessage(const bool isFromVA, const QString& qsMessage){
    QString sender;
    int row = rowCount();

    (isFromVA) ? (sender = CHAT_VA) : (sender = CHAT_USER);

    //set current msg info
    m_CurrentSender = sender;
    m_CurrentMsg = qsMessage;

    insertRows(row, 1);

    return row;
}

bool ChatModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);

    beginInsertRows(QModelIndex(), row, row + count - 1);

    for(int i = 0; i < count; ++i){
        m_data.insert(row, QPair <QString, QString>(m_CurrentSender, m_CurrentMsg));
    }

    endInsertRows();
    return true;
}


bool ChatModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole){
        switch (index.column()) {
        case CHAT_SENDER_ROW:
            m_data[index.row()].first = value.value<QString>();
            break;
        case CHAT_MSG_ROW:
            m_data[index.row()].second = value.value<QString>();
            break;
        default:
            break;
        }
    }

    return true;
}

QVariant ChatModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){
        switch (index.column()) {
            case CHAT_SENDER_ROW: return m_data[index.row()].first;
            case CHAT_MSG_ROW: return m_data[index.row()].second;
            default: return QVariant();
        }
    }

    return QVariant();
}

int ChatModel::rowCount(const QModelIndex & /*parent*/) const
{
   return m_data.count();
}

int ChatModel::columnCount(const QModelIndex & /*parent*/) const
{
    return CHAT_COLUMNS;
}
