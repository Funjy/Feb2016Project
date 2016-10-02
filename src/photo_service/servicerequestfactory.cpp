#include "servicerequestfactory.h"

using namespace PhotoFlyService;

ServiceRequestFactory &ServiceRequestFactory::instance()
{
    static ServiceRequestFactory instance;
    return instance;
}

void ServiceRequestFactory::init()
{
    QQmlEngine::setObjectOwnership(&requestFactory, QQmlEngine::CppOwnership);
}

GenericServiceRequest* ServiceRequestFactory::buildRequest(GenericServiceRequest::RequestType type)
{
    return nullptr;
//    switch(type){
//    case ServiceRequest::Type::Login:
//        return new LoginRequest();
//        break;
//    }
}

GenericServiceRequest *ServiceRequestFactory::buildRequest(const QString &type, const QVariantMap &content)
{
    auto message = new GenericServiceMessage();
//    message->setType();
}

ServiceRequestFactory::ServiceRequestFactory(QObject *parent) : QObject(parent)
{

}
