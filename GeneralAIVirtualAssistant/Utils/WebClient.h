#ifndef WEBCLIENT_H
#define WEBCLIENT_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QAuthenticator>
#include <QObject>
#include <QEventLoop>

class WebClient : public QObject
{
    Q_OBJECT
public:
    WebClient();
    int Initialize();
    QString GET(const QUrl& url, const QString& headerContent);
    QString POST(const QUrl& url, const QString& headerContent, const QByteArray& data);

    void SetCredentials(QString user, QString pass);

public slots:
    void finishedReq();
    void authRequired(QNetworkReply *reply, QAuthenticator *ator);
#ifndef QT_NO_SSL
    void sslErrors(QNetworkReply *, const QList<QSslError> &errors);
#endif

private:
    QNetworkAccessManager   m_manager;
    QNetworkReply*          m_pReply = nullptr;
    QUrl                    m_url;
    QString                 m_user;
    QString                 m_pass;
    QString                 m_headerContent;
    QString                 m_response;
};

#endif // WEBCLIENT_H
