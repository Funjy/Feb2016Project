#include "servicerequest.h"

using namespace PhotoFlyService;

ServiceRequest::ServiceRequest(QObject *parent) : QObject(parent)
{
    m_resultStatus = ResultStatus::Initialized;
}

ServiceRequest::ResultStatus PhotoFlyService::ServiceRequest::getResultStatus() const
{
    return m_resultStatus;
}

void ServiceRequest::setResultStatus(ServiceRequest::ResultStatus value)
{
    m_resultStatus = value;
}

QSharedPointer<ServiceMessage> ServiceRequest::getResult() const
{
    return m_result;
}
