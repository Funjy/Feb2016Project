#include "genericservicerequest.h"

using namespace PhotoFlyService;

const QString GenericServiceRequest::TypeId =           "GenericServiceRequest";
const QString GenericServiceRequest::ResultKey =        "Result";
const QString GenericServiceRequest::ResultStatusKey =  "ResultStatus";

GenericServiceRequest::GenericServiceRequest(QObject *parent) : GenericServiceMessage(parent)
{
    m_resultStatus = ResultStatus::Initialized;
}

//GenericServiceRequest::GenericServiceRequest(ServiceMessage::Type type, QObject *parent) :
//    GenericServiceRequest(parent)
//{
//    setType(type);
//}

void GenericServiceRequest::getObjectInfo(SerializationInfo &info) const
{
    GenericServiceMessage::getObjectInfo(info);

    SerializationInfo si;
    m_result->getObjectInfo(si);
    info.addValue(ResultKey, si);
    info.addValue(ResultStatusKey, QVariant::fromValue(m_resultStatus));

//    info.setTypeId(metaObject()->className());
}

void GenericServiceRequest::deserialize(const SerializationInfo &info)
{
    GenericServiceMessage::deserialize(info);
    auto map = info.toMap();
    setResult(map);
    setResultStatus(map[ResultStatusKey].value<ResultStatus>());
}

RequestResultStatus GenericServiceRequest::getResultStatus() const
{
    return m_resultStatus;
}

void GenericServiceRequest::setResultStatus(RequestResultStatus value)
{
    m_resultStatus = value;
    if(m_resultStatus != RequestResultStatus::Fail)
        m_errorString = QString();
}

//QSharedPointer<ServiceMessage> ServiceRequest::getResult() const
//{
//    return m_result;
//}

const ServiceMessage *GenericServiceRequest::getResult() const
{
    return m_result.data();
}

void GenericServiceRequest::setResult(ServiceMessage *result)
{
    m_result = QSharedPointer<ServiceMessage>(result);
}

void GenericServiceRequest::setResult(const QVariantMap &result)
{
    auto message = new GenericServiceMessage();
    message->deserialize(SerializationInfo(result));
    setResult(message);
}

QString GenericServiceRequest::getErrorString() const
{
    return m_errorString;
}

void GenericServiceRequest::setErrorString(const QString &errorString)
{
    m_errorString = errorString;
}

