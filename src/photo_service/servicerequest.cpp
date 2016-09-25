#include "servicerequest.h"

using namespace PhotoFlyService;

ServiceRequest::ServiceRequest() {
    m_result = Result::Initialized;
}

ServiceRequest::Result PhotoFlyService::ServiceRequest::getResult() const
{
    return m_result;
}

void ServiceRequest::setResult(ServiceRequest::Result value)
{
    m_result = value;
}
