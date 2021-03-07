#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    installEventFilter(this);

    ui->setupUi(this);


//    output.setFileName("C:/Users/selectuls/Desktop/record.wav");
//    settings.setCodec("audio/wav");
//    settings.setSampleRate(16000);
//    settings.setSampleSize(16);
//    settings.setChannelCount(1);
//    settings.setByteOrder(QAudioFormat::LittleEndian);
//    settings.setSampleType(QAudioFormat::SignedInt);
//    audio = new QAudioInput(settings);


//    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
//      if (!info.isFormatSupported(settings)) {
//          settings = info.nearestFormat(settings);      // This is the magic line
//          settings.setSampleRate(16000);
//          qDebug() << "Raw audio format not supported by backend. Trying the nearest format.";
//      }



    audioRecorder = new QAudioRecorder(this);

    settings.setCodec("audio/pcm");
    settings.setSampleRate(16000);
    settings.setChannelCount(1);
    settings.setBitRate(128000);
    settings.setQuality(QMultimedia::EncodingQuality::VeryHighQuality);
    settings.setEncodingMode( QMultimedia::ConstantBitRateEncoding);
    audioRecorder->setEncodingSettings(settings, QVideoEncoderSettings(), "audio/x-wav");
    audioRecorder->setContainerFormat("wav");
    QString path = QDir::currentPath() + "/record.raw";

    audioRecorder->setOutputLocation(QUrl::fromLocalFile("C:/Users/selectuls/Desktop/record.wav"));

}

MainWindow::~MainWindow()
{
    if (NULL != m_pQStartDialog)
    {
        m_pQStartDialog->close();
        delete m_pQStartDialog;
        m_pQStartDialog = NULL;
    }

    delete ui;
}

void MainWindow::SetupChatBox()
{
    m_pChatModel = new ChatModel(this);
    ui->tbl_chatBox->setFocusPolicy(Qt::NoFocus);
    ui->tbl_chatBox->setModel(m_pChatModel);
    ui->tbl_chatBox->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tbl_chatBox->setSelectionMode(QAbstractItemView::ContiguousSelection);
    ui->tbl_chatBox->setSortingEnabled(false);
    ui->tbl_chatBox->verticalHeader()->hide();
    ui->tbl_chatBox->setWordWrap(false);
    ui->tbl_chatBox->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->tbl_chatBox->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->tbl_chatBox->setShowGrid(false);
    ui->tbl_chatBox->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tbl_chatBox->horizontalHeader()->setHighlightSections(false);
    ui->tbl_chatBox->setAlternatingRowColors(true);  // alternative colors
    ui->tbl_chatBox->setFrameShape(QFrame::NoFrame);

    ui->tbl_chatBox->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tbl_chatBox->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

}

bool MainWindow::Initialize()
{
    bool bIsInitialized = true;

    m_pQStartDialog = new QStartDialog(this);

    if (NULL == m_pQStartDialog)
    {
        bIsInitialized = false;
        return bIsInitialized;
    }

    SetupChatBox();

    //connecting signal to slots and checking if they're connected
    bIsInitialized = connect(ui->btnSendMessage,    SIGNAL(pressed()),
                             this,                  SLOT(OnInsertMessageSlot()),Qt::QueuedConnection);

    if (!bIsInitialized) return bIsInitialized;

    bIsInitialized = connect(m_pQStartDialog,   SIGNAL(FinishedSignal(QString,qint32,QString)),
                             this,              SLOT(OnFinishedGettingDataSlot(QString,qint32,QString)),Qt::QueuedConnection);

    if (!bIsInitialized) return bIsInitialized;

    bIsInitialized = connect(m_pQStartDialog,   SIGNAL(CloseApplication()),
                             this,              SLOT(OnCloseSlot()),Qt::QueuedConnection);

    if (!bIsInitialized) return bIsInitialized;

    m_bIsInitialized = bIsInitialized;

    return bIsInitialized;
}

void MainWindow::showEvent(QShowEvent* pEvent)
{
    QMainWindow::showEvent(pEvent);

//    if (NULL != m_pQStartDialog)
//    {
//        m_pQStartDialog->show();
//    }
}

void MainWindow::closeEvent(QCloseEvent* pEvent)
{
    SaveChatHistory();
    QMainWindow::closeEvent(pEvent);
}

void MainWindow::OnFinishedGettingDataSlot(QString qsName, qint32 nAge, QString qsOccupation)
{
    QString qsAgeDirectory;
    QString qsOccupationDirectory;

    m_qsName = qsName;
    m_nAge = nAge;
    m_qsOccupation = qsOccupation;

    PushMessageFromVA(QString("My Name is ") + m_qsName);

    LoadChatHistory();

    m_bIsInitialized = true;
}

void MainWindow::SaveChatHistory()
{
}

void MainWindow::LoadChatHistory()
{
}

void MainWindow::OnCloseSlot()
{
    this->close();
}

void MainWindow::PushMessageFromVA(QString qsPushInput)
{
    //insert meesage from VA
    QString qsVAResponse = m_pChatModel->GetLocalResponse(qsPushInput);
    m_pChatModel->PushChatMessage(true, qsVAResponse);
}

void MainWindow::OnInsertMessageSlot()
{
    if (false == m_bIsInitialized)
    {
        return;
    }

    if (true == ui->te_userInput->toPlainText().isEmpty())
    {
        return;
    }

    QString qsUserInput =  ui->te_userInput->toPlainText();

    if (true == qsUserInput.trimmed().isEmpty())
    {
        return;
    }

    m_pChatModel->PushChatMessage(false,qsUserInput);

    QString qsVAResponse = m_pChatModel->GetLocalResponse(qsUserInput);

    m_pChatModel->PushChatMessage(true,qsVAResponse);

    ui->te_userInput->clear();

}

bool MainWindow::eventFilter(QObject *obj, QEvent* event){
    if( event->type() == QEvent::ChildAdded ) // install eventfilter on children
    {
        QChildEvent *ce = static_cast<QChildEvent*>(event);
        ce->child()->installEventFilter(this);
    }
    else if( event->type() == QEvent::ChildRemoved ) // remove eventfilter from children
    {
        QChildEvent *ce = static_cast<QChildEvent*>(event);
        ce->child()->removeEventFilter(this);
    }
    else if( (event->type() == QEvent::KeyPress) ) // e.g. filter out Mouse Buttons Relases
    {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
            OnInsertMessageSlot();
        } else {
            return QObject::eventFilter(obj, event);
        }
        return true;
    }

    return QWidget::eventFilter( obj, event ); // apply default filter
}

void MainWindow::on_btnSendMessage_toggled(bool checked)
{
    if (checked && audioRecorder->state() == QMediaRecorder::StoppedState){
        audioRecorder->record();
    }else{
        audioRecorder->stop();
        QString conversion = m_pChatModel->GetWebResponse("");
        ui->te_userInput->clear();
        ui->te_userInput->setText(conversion);
        OnInsertMessageSlot();
    }

//    if (checked){
//        output.open(QIODevice::ReadWrite);
//        audio->start(&output);
//        //QTimer::singleShot(3000, this, SLOT(stopRecording()));

//    }else{
//        audio->stop();
//        output.close();
//        QString conversion = m_pChatModel->GetWebResponse("");
//        ui->te_userInput->clear();
//        ui->te_userInput->setText(conversion);
//    }
}

//void MainWindow::stopRecording()
//{
//    audio->stop();
//    output.close();
//    m_pChatModel->GetWebResponse("");
//}
