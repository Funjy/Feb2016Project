#include "servicerequestfactory.h"

using namespace PhotoFlyService;

ServiceRequestFactory *ServiceRequestFactory::Get()
{
    static ServiceRequestFactory instance;
    return &instance;
}

ServiceRequest* ServiceRequestFactory::buildRequest(ServiceRequest::Type type)
{
    switch(type){
    case ServiceRequest::Type::Login:
        return new LoginRequest();
        break;
    }
}

ServiceRequestFactory::ServiceRequestFactory(QObject *parent) : QObject(parent)
{

}
