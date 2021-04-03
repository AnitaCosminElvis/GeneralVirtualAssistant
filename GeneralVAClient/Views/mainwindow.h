#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QSettings>
#include <QStringList>
#include <QMap>
#include <QTime>
#include <QCryptographicHash>
#include <QChar>
#include <QDebug>
#include <QThread>
#include <QAbstractItemDelegate>
#include <QKeyEvent>
#include "qstartdialog.h"
#include "Data/Defines.h"

class ChatModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool Initialize();

    void SetupChatBox();

protected:
    void showEvent(QShowEvent* pEvent);
    void closeEvent(QCloseEvent* pEvent);
public slots:
    void OnCloseSlot();
    void OnInsertMessageSlot();
    void OnInsertAudioMsgSlot(std::string input, std::string response);
    void OnFinishedGettingDataSlot(QString qsName, qint32 nAge, QString qsOccupation);

private slots:
    void on_btnSendLocalMessage_toggled(bool checked);
    //void stopRecording();
    void on_btnSendWebMessage_toggled(bool checked);

private:
    bool eventFilter(QObject*, QEvent*);
    void WriteMessage(QString);
    void PushMessageFromVA(QString);
    void SaveChatHistory();
    void LoadChatHistory();

private:
    Ui::MainWindow *                ui = nullptr;
    QStartDialog*                   m_pQStartDialog = nullptr;
    std::unique_ptr<ChatModel>      m_pChatModel;
    QString                         m_qsName = "Cosmin";
    QString                         m_qsOccupation = "Programmer";
    qint32                          m_nAge = 18;
    bool                            m_bIsInitialized = false;

};

#endif // MAINWINDOW_H
