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

#define TEST_REQ 2      // 1 - get
                        // 2 - post

#include <QElapsedTimer>

void ServiceProvider::testRequest()
{
    QElapsedTimer elTim;
    elTim.start();

    m_service->connectToHost("http://91.149.189.150:5000");

    qDebug() << "Connect timeout: " << elTim.elapsed();

    elTim.restart();

    QString resStr;
    bool isValid;

    QNetworkRequest req(QUrl("http://91.149.189.150:5000/photofly/api/v0.1/letters"));


#if TEST_REQ == 1

    auto reply = m_service->get(req);
    QEventLoop loop;
    loop.connect(reply, SIGNAL(finished()), SLOT(quit()));
    loop.exec();

//    reply->waitForReadyRead(-1);

    if( reply->error() != QNetworkReply::NoError ){
        qDebug() << "Reply error: " << reply->errorString();
    } else {

        auto data = reply->readAll();
        resStr = data;

        auto json = jsonFromBytes(data);

        isValid = !json.isNull();

    }

#elif TEST_REQ == 2

    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QVariantMap map2send;

    map2send.insert("rec_fname",    "1");
    map2send.insert("rec_lname",    "2");
    map2send.insert("rec_address",  "3");
    map2send.insert("rec_postindex", "4");
    map2send.insert("sender_name",  "5");
    map2send.insert("photo_size",   "6");

    QJsonDocument doc(QJsonObject::fromVariantMap(map2send));

    auto reply = m_service->post(req, bytesFromJson(doc));
    QEventLoop loop;
    loop.connect(reply, SIGNAL(finished()), SLOT(quit()));
    loop.exec();

    if( reply->error() != QNetworkReply::NoError ){
        qDebug() << "Reply error: " << reply->errorString();
    } else {

        auto data = reply->readAll();

        resStr = data;

        auto json = jsonFromBytes(data);

        isValid = !json.isNull();

    }

#endif

    qDebug() << "isValidResponse: " << isValid;
//    qDebug() << "Response: " << resStr;
    qDebug() << "Operation time: " << elTim.elapsed();

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
    QJsonParseError error;
    auto ret = QJsonDocument::fromJson(data, &error);
    if(error.error != QJsonParseError::NoError)
        qDebug() << "Parse error: " << error.errorString();
    return ret;
//    return QJsonDocument::fromBinaryData(data);
}

QByteArray ServiceProvider::bytesFromJson(const QJsonDocument &data)
{
    return data.toJson();
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
        request->setErrorString(reply->errorString());
    }

    reply->deleteLater();
}
