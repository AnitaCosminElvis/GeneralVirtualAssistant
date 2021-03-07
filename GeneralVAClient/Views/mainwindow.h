#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QAudioRecorder>
#include <QAudioFormat>
#include <QAudioInput>

#include <QMainWindow>
#include <QString>
#include <Qtimer>
#include <QSettings>
#include <QStringList>
#include <Qlist>
#include <QMap>
#include <QTime>
#include <QCryptographicHash>
#include <QChar>
#include <QDebug>
#include <QThread>
#include <QAbstractItemDelegate>
#include <QKeyEvent>
#include "qstartdialog.h"
#include "Models/chatmodel.h"
#include "Data/Defines.h"

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
    void OnFinishedGettingDataSlot(QString qsName, qint32 nAge, QString qsOccupation);

private slots:
    void on_btnSendMessage_toggled(bool checked);
    //void stopRecording();
private:
    bool eventFilter(QObject*, QEvent*);
    void WriteMessage(QString);
    void PushMessageFromVA(QString);
    void SaveChatHistory();
    void LoadChatHistory();

private:
    Ui::MainWindow *        ui = nullptr;
    QStartDialog*           m_pQStartDialog = nullptr;
    ChatModel*              m_pChatModel = nullptr;
    QString                 m_qsName = "Cosmin";
    QString                 m_qsOccupation = "Programmer";
    qint32                  m_nAge = 18;
    bool                    m_bIsInitialized = false;

    QAudioRecorder*         audioRecorder = nullptr;
    QAudioEncoderSettings   settings;
//    QAudioFormat settings;
//    QAudioInput *audio = nullptr;
//    QFile output;

};

#endif // MAINWINDOW_H
