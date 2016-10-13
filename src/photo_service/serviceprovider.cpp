#include "serviceprovider.h"

using namespace PhotoFlyService;

using namespace PhotoFlyContainers;

const QString ServiceProvider::RespKeyStatus = QString("status");
const QString ServiceProvider::RespStatusError = QString("ERR");
const QString ServiceProvider::RespKeyMessage = QString("message");

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
//    auto reply = prepareRequest(request);
//    if(!reply) return;

    QNetworkReply *reply = nullptr;

    QUrl url;
    QByteArray content;
    prepareRequest(*request, &url, &content);
    QNetworkRequest req(url);

    if (content.isEmpty() || content.isNull()) {
        reply = m_service->get(req);
    } else {
        qDebug() << "req content: " << reqToJson(*request);
        req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        reply = m_service->post(req, content);
    }
    QEventLoop loop;
    loop.connect(reply, SIGNAL(finished()), SLOT(quit()));
    loop.exec();

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
    return m_serviceUrlString;
}

#define TEST_REQ 1      // 1 - get
                        // 2 - post

#include <QElapsedTimer>

void ServiceProvider::testRequest()
{
    QElapsedTimer elTim;
    elTim.start();

//    m_service->connectToHost("http://91.149.189.150:5000");

//    qDebug() << "Connect timeout: " << elTim.elapsed();

//    elTim.restart();

    QString resStr;
    bool isValid;

    QNetworkRequest req(QUrl("http://91.149.189.150:5000/photofly/api/v0.1/users/user"));


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

QString ServiceProvider::getServiceUrl() const
{
    return m_serviceUrl;
}

//void ServiceProvider::onReplyFinished(QNetworkReply *reply)
//{
//    m_requests.take(reply);
//    reply->deleteLater();
//}

QJsonDocument ServiceProvider::reqToJson(const GenericServiceRequest &request)
{
//    SerializationInfo info;
//    request.getObjectInfo(info);
//    request.getContent()
//    QJsonDocument json(info.toJson());
//    return json;

    return QJsonDocument( QJsonObject::fromVariantMap(request.getContent()) );

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
//    if (QThread::currentThread() != this->thread()) {
//        QMetaObject::invokeMethod(this, "prepareRequest",
//                                  Qt::QueuedConnection,
//                                  Q_ARG(GenericServiceRequest *, request));
//    }

//    QNetworkRequest req(m_seriveUrl);

    QString urlString = m_serviceUrlString;

    auto content = bytesFromJson( reqToJson(*request) );

    QNetworkReply *reply = nullptr;

    switch (request->getMessageType()) {
    case ServiceMessageType::Req_Login:
        urlString += "users/" + request->urlParameters().first();
        reply = m_service->get(QNetworkRequest(QUrl(urlString.toLatin1())));
        break;
    case ServiceMessageType::Req_Register:
    case ServiceMessageType::Req_SendPhotos:
//        reply = m_service->post(req, content);
        break;
    default:
        break;
        qDebug() << "Unknown request type";
    }
    return reply;
}

void ServiceProvider::prepareRequest(const GenericServiceRequest &request, QUrl *url, QByteArray *content)
{
    QString urlString = getServiceUrl();

    *url = QUrl();
    content->clear();

    switch (request.getMessageType()) {
    case ServiceMessageType::Req_Login:
        urlString += "users/" + request.urlParameters().first();
        *url = QUrl(urlString);
//        *url = QUrl(urlString + "users/" + request.urlParameters().first());
        break;
    case ServiceMessageType::Req_Register:
        urlString += "users";
//        *url = QUrl(urlString + "users");
        *url = QUrl(urlString);
        *content = bytesFromJson( reqToJson(request) );
        break;
    case ServiceMessageType::Req_SendPhotos:
//        reply = m_service->post(req, content);
    default:
        qDebug() << "Unknown request type";
        break;
    }
}

void ServiceProvider::handleReply(GenericServiceRequest *request, QNetworkReply *reply)
{

    if (!reply) {
        request->setResultStatus(RequestResultStatus::Fail);
        request->setErrorString("Reply object wasn't created");
        return;
    }

    if(reply->error() == QNetworkReply::NoError){
        auto json = nmReplyToJson(reply);
        auto respMap = json.toVariant().toMap();
        if (respMap[RespKeyStatus].toString() == RespStatusError)
            request->setResultStatus(RequestResultStatus::Fail);
        else
            request->setResultStatus(RequestResultStatus::Ok);
        request->setErrorString(respMap[RespKeyMessage].toString());
        request->setResult(respMap);
    } else {        
        request->setResultStatus(RequestResultStatus::Fail);
        request->setErrorString(reply->errorString());
    }

    reply->deleteLater();
}
