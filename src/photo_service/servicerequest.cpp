#include "servicerequest.h"

using namespace PhotoFlyService;

ServiceRequest::ServiceRequest(QObject *parent) : GenericServiceMessage(parent)
{
    m_resultStatus = ResultStatus::Initialized;
}

ServiceRequest::ServiceRequest(ServiceMessage::Type type, QObject *parent) :
    ServiceRequest(parent)
{
    setType(type);
}

ServiceRequest::ResultStatus PhotoFlyService::ServiceRequest::getResultStatus() const
{
    return m_resultStatus;
}

void ServiceRequest::setResultStatus(ServiceRequest::ResultStatus value)
{
    m_resultStatus = value;
}

//QSharedPointer<ServiceMessage> ServiceRequest::getResult() const
//{
//    return m_result;
//}

const ServiceMessage * const ServiceRequest::getResult()
{
    return m_result.data();
}
