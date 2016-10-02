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

GenericServiceRequest* ServiceRequestFactory::buildRequest(GenericServiceRequest::MessageType type)
{
    Q_UNUSED(type)
    return nullptr;
//    switch(type){
//    case ServiceRequest::Type::Login:
//        return new LoginRequest();
//        break;
//    }
}

GenericServiceRequest *ServiceRequestFactory::buildRequest(const QString &type, const QVariantMap &content)
{
    Q_UNUSED(type)
    Q_UNUSED(content)
    return nullptr;
//    auto message = new GenericServiceMessage();
//    message->setType();
}

ServiceRequestFactory::ServiceRequestFactory(QObject *parent) : QObject(parent)
{

}
