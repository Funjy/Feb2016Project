#include "serviceprovider.h"

using namespace PhotoFlyService;

using namespace PhotoFlyContainers;

ServiceProvider::ServiceProvider(QObject *parent) : IServiceProvider(parent)
{
    m_service = new QNetworkAccessManager(this);
//    connect(m_service, &QNetworkAccessManager::finished, this, &ServiceProvider::onReplyFinished);
}

void ServiceProvider::connectToHost(const QString &hostName, quint16 port)
{
    m_service->connectToHost(hostName, port);
}

void ServiceProvider::makeRequest(GenericServiceRequest *request, int timeout)
{
    auto reply = prepareRequest(request);
    if(!reply) return;

    reply->waitForReadyRead(timeout);

    handleReply(request, reply);

}

void ServiceProvider::beginMakeRequest(GenericServiceRequest *request)
{
    auto reply = prepareRequest(request);
    if(!reply) return;
    connect(reply, &QNetworkReply::finished, this, &ServiceProvider::onReplyFinished);

    m_requests.insert(reply, request);
}

QUrl ServiceProvider::getHostUrl()
{
    return m_seriveUrl;
}

void ServiceProvider::onReplyFinished()
{
    auto reply = qobject_cast<QNetworkReply *>(sender());
    auto request = m_requests.take(reply);
    handleReply(request, reply);
    emit requestComplete(request);
}

//void ServiceProvider::onReplyFinished(QNetworkReply *reply)
//{
//    m_requests.take(reply);
//    reply->deleteLater();
//}

QJsonDocument ServiceProvider::reqToJson(GenericServiceRequest *request)
{
    SerializationInfo info;
    request->getObjectInfo(info);

    QJsonDocument json(QJsonObject::fromVariantMap(info.toMap()));
    return json;
}

QJsonDocument ServiceProvider::nmReplyToJson(QNetworkReply *reply)
{
    return jsonFromBytes(reply->readAll());
}

QJsonDocument ServiceProvider::jsonFromBytes(const QByteArray& data)
{
    return QJsonDocument::fromBinaryData(data);
}

QByteArray ServiceProvider::bytesFromJson(const QJsonDocument &data)
{
    return data.toBinaryData();
}

QNetworkReply *ServiceProvider::prepareRequest(GenericServiceRequest *request)
{
    QNetworkRequest req(m_seriveUrl);

    auto content = bytesFromJson(reqToJson(request));

    QNetworkReply *reply = nullptr;

    switch (request->getMessageType()) {
    case ServiceMessageType::Req_Login:
    case ServiceMessageType::Req_Register:
    case ServiceMessageType::Req_SendPhotos:
        reply = m_service->post(req, content);
        break;
    default:
        break;
        qDebug() << "Unknown request type";
    }
    return reply;
}

void ServiceProvider::handleReply(GenericServiceRequest *request, QNetworkReply *reply)
{

    if(reply->error() == QNetworkReply::NoError){
        request->setResultStatus(RequestResultStatus::Ok);
        auto json = nmReplyToJson(reply);
        request->setResult(json.toVariant().toMap());
    } else {
        request->setResultStatus(RequestResultStatus::Fail);
    }

    reply->deleteLater();
}
