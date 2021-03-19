#include "WebClient.h"



WebClient::WebClient()
{

}

int WebClient::Initialize()
{
    connect(&m_manager,    SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)),
            this,       SLOT(authRequired(QNetworkReply*,QAuthenticator*)));

#ifndef QT_NO_SSL
    connect(&m_manager,      &QNetworkAccessManager::sslErrors,
            this,       &WebClient::sslErrors);
#endif

    return 1;
}

QString WebClient::GET(const QUrl& url, const QString& headerContent)
{
    QEventLoop loop;
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, headerContent);
    request.setUrl(url);

    m_pReply = m_manager.get(request);

    connect(m_pReply, &QNetworkReply::finished, this, &WebClient::finishedReq);
    connect(m_pReply , &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    return m_response;
}

QString WebClient::POST(const QUrl& url, const QString &headerContent, const QByteArray &data)
{
    QEventLoop loop;
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, headerContent);
    request.setUrl(url);

    m_pReply = m_manager.post(request, data);

    connect(m_pReply, &QNetworkReply::finished, this, &WebClient::finishedReq);
    connect(m_pReply , &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    return m_response;
}

void WebClient::SetCredentials(QString user, QString pass)
{
    m_user = user;
    m_pass = pass;
}

void WebClient::finishedReq() {
    if (m_pReply->error()) {
        m_response = m_pReply->errorString();
        return;
    }

    m_response = m_pReply->readAll();
}

void WebClient::authRequired(QNetworkReply* /*reply*/, QAuthenticator *ator)
{
    ator->setUser(m_user);
    ator->setPassword(m_pass);
}

#ifndef QT_NO_SSL
void WebClient::sslErrors(QNetworkReply *, const QList<QSslError> &errors)
{
    QString errorString;
    for (const QSslError &error : errors) {
        if (!errorString.isEmpty())
            errorString += '\n';
        errorString += error.errorString();
    }

    qDebug() << errorString;

    m_pReply->ignoreSslErrors();

}
#endif
