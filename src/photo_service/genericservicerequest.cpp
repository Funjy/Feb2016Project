#include "genericservicerequest.h"

using namespace PhotoFlyService;

const QString GenericServiceRequest::TypeId =       "GenericServiceRequest";
const QString GenericServiceRequest::ResultKey =    "Result";

GenericServiceRequest::GenericServiceRequest(QObject *parent) : GenericServiceMessage(parent)
{
    m_resultStatus = ResultStatus::Initialized;
}

//GenericServiceRequest::GenericServiceRequest(ServiceMessage::Type type, QObject *parent) :
//    GenericServiceRequest(parent)
//{
//    setType(type);
//}

void GenericServiceRequest::getObjectInfo(PhotoFlyContainers::SerializationInfo &info) const
{
    GenericServiceMessage::getObjectInfo(info);

    PhotoFlyContainers::SerializationInfo si;
    m_result->getObjectInfo(si);
    info.addValue(ResultKey, si);

    info.setTypeId(metaObject()->className());
}

GenericServiceRequest::ResultStatus PhotoFlyService::GenericServiceRequest::getResultStatus() const
{
    return m_resultStatus;
}

void GenericServiceRequest::setResultStatus(GenericServiceRequest::ResultStatus value)
{
    m_resultStatus = value;
}

//QSharedPointer<ServiceMessage> ServiceRequest::getResult() const
//{
//    return m_result;
//}

const ServiceMessage * const GenericServiceRequest::getResult()
{
    return m_result.data();
}

void GenericServiceRequest::setResult(ServiceMessage *result)
{
    m_result = QSharedPointer<ServiceMessage>(result);
}
