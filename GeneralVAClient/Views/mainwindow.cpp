#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Models/chatmodel.h"

#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    installEventFilter(this);
    ui->setupUi(this);

    m_pChatModel.reset(new ChatModel(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetupChatBox()
{
    ui->tbl_chatBox->setFocusPolicy(Qt::NoFocus);
    ui->tbl_chatBox->setModel(m_pChatModel.get());
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

    SetupChatBox();

    //connecting signal to slots and checking if they're connected
    bIsInitialized = connect(ui->btnSendLocalMessage,    SIGNAL(pressed()),
                             this,                  SLOT(OnInsertMessageSlot()),Qt::QueuedConnection);

    if (!bIsInitialized) return bIsInitialized;

    if (!m_pChatModel->Initialize()) return false;

    m_bIsInitialized = bIsInitialized;

    return bIsInitialized;
}

void MainWindow::showEvent(QShowEvent* pEvent)
{
    QMainWindow::showEvent(pEvent);
}

void MainWindow::closeEvent(QCloseEvent* pEvent)
{
    QMainWindow::closeEvent(pEvent);
}

void MainWindow::OnCloseSlot()
{
    this->close();
}

void MainWindow::PushMessageFromVA(QString qsPushInput)
{
    //insert meesage from VA
    std::string input = qsPushInput.toLocal8Bit().data();
    QString qsVAResponse = m_pChatModel->GetLocalResponse(input);
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

    std::string input = qsUserInput.toLocal8Bit().data();
    QString qsVAResponse = m_pChatModel->GetLocalResponse(input,false);

    m_pChatModel->PushChatMessage(true,qsVAResponse);

    ui->te_userInput->clear();
}

void MainWindow::OnInsertAudioMsgSlot(std::string input, std::string response)
{
    if (false == m_bIsInitialized) return;

    if (input.empty()){
        m_pChatModel->PushChatMessage(true,response.data());
    }else{
        m_pChatModel->PushChatMessage(false,input.data());
        m_pChatModel->PushChatMessage(true,response.data());
    }

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

void MainWindow::on_btnSendLocalMessage_toggled(bool checked)
{
    if (checked){
        if (!m_pChatModel->StartRecording()) {
            ui->btnSendLocalMessage->setChecked(false);
        }
    }else{
        std::string input;
        m_pChatModel->StopRecording();
        QString conversion = m_pChatModel->GetLocalResponse(input);

        OnInsertAudioMsgSlot(input,conversion.toLocal8Bit().data());
    }
}

void MainWindow::on_btnSendWebMessage_toggled(bool checked)
{
    if (checked){
        if (!m_pChatModel->StartRecording()) {
            ui->btnSendWebMessage->setChecked(false);
        }
    }else{
        std::string input;
        m_pChatModel->StopRecording();
        QString conversion = m_pChatModel->GetWebResponse(input);

        OnInsertAudioMsgSlot(input,conversion.toLocal8Bit().data());
    }
}
