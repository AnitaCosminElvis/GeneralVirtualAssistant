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
#include "Data/Defines.h"

class ChatModel;

namespace Ui {
class MainWindow;
}

/*
 * Inherits from Qt’s QMainWindow to handle and display the UI elements.
 * Contains and sets the ChatModel class instance to interact with its delegates and/or through the signal/slots mechanism.
 * Captures the Enter key to insert a new message into chat.
 * Initiates a recording of a new message through the local and web buttons.
*/
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

private slots:
    void on_btnSendLocalMessage_toggled(bool checked);
    void on_btnSendWebMessage_toggled(bool checked);

private:
    bool eventFilter(QObject*, QEvent*);
    void WriteMessage(QString);
    void PushMessageFromVA(QString);

private:
    Ui::MainWindow*                 ui = nullptr;
    std::unique_ptr<ChatModel>      m_pChatModel;
    bool                            m_bIsInitialized = false;

};

#endif // MAINWINDOW_H
