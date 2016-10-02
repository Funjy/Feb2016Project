#ifndef SERVICEPROVIDER_H
#define SERVICEPROVIDER_H

#include <QObject>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>

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

public slots:

private slots:
//    void onReplyFinished(QNetworkReply* reply);
    void onReplyFinished();

private:
    const QUrl       m_seriveUrl = QUrl("");
    QNetworkAccessManager   *m_service;

    QHash<QNetworkReply*, GenericServiceRequest *>  m_requests;

    static QJsonDocument reqToJson(GenericServiceRequest *request);
    static QJsonDocument nmReplyToJson(QNetworkReply *reply);

    static QJsonDocument jsonFromBytes(const QByteArray &data);
    static QByteArray bytesFromJson(const QJsonDocument &data);

    QNetworkReply *prepareRequest(GenericServiceRequest *request);

    static void handleReply(GenericServiceRequest *request, QNetworkReply *reply);

};

}

#endif // SERVICEPROVIDER_H
