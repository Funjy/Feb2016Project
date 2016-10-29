#ifndef SERVICEPROVIDER_H
#define SERVICEPROVIDER_H

#include <QObject>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QEventLoop>
#include <QThread>
#include <QMutex>

#include "behaviours/iserviceprovider.h"

namespace PhotoFlyService {

class ServiceProvider : public PhotoFlyBehaviours::IServiceProvider
{
    Q_OBJECT
    Q_DISABLE_COPY(ServiceProvider)

public:
    explicit ServiceProvider(QObject *parent = 0);

    // IServiceProvider interface
    virtual void connectToHost(const QString &hostName, quint16 port) Q_DECL_OVERRIDE;
    virtual void makeRequest(GenericServiceRequest *request, int timeout = 10000) Q_DECL_OVERRIDE;
    virtual void beginMakeRequest(GenericServiceRequest *request) Q_DECL_OVERRIDE;
    virtual QUrl getHostUrl() Q_DECL_OVERRIDE;

    void testRequest();

public slots:

private slots:
//    void onReplyFinished(QNetworkReply* reply);
    void onReplyFinished();

private:
//    const QUrl       m_seriveUrl = QUrl("http://91.149.189.150:5000/photofly/api");
    const QString       m_serviceUrlString =     QString("http://91.149.189.150:5000/photofly/api/");
    const QString       m_serviceUrlversion =    QString("0.1");
    const QString       m_serviceUrl =           QString("%1v%2/").arg(m_serviceUrlString).arg(m_serviceUrlversion);

    static const QString       RespKeyStatus;
    static const QString       RespStatusError;
    static const QString       RespKeyMessage;

    QString getServiceUrl() const;

    QNetworkAccessManager   *m_service;

    QHash<QNetworkReply*, GenericServiceRequest *>  m_requests;

    static QJsonDocument reqToJson(const GenericServiceRequest &request);
    static QJsonDocument nmReplyToJson(QNetworkReply *reply);

    static QJsonDocument jsonFromBytes(const QByteArray &data);
    static QByteArray bytesFromJson(const QJsonDocument &data);

    Q_INVOKABLE QNetworkReply *prepareRequest(GenericServiceRequest *request);
    Q_INVOKABLE void prepareRequest(const GenericServiceRequest &request, QUrl *url, QByteArray *content);

    QNetworkReply *initOperation(GenericServiceRequest *request, int timeout);

    static void handleReply(GenericServiceRequest *request, QNetworkReply *reply);

    QMutex  m_busyLock;
    bool    m_isBusy;


};

}

#endif // SERVICEPROVIDER_H
