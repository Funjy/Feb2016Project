#include "registrationformcontroller.h"

#include "core/applicationsettings.h"

using namespace PhotoFlyControllers;
using namespace PhotoFlySettings;

RegistrationFormController::RegistrationFormController(QObject *parent) : QObject(parent)
{

}

//RegistrationFormController::RegistrationFormController(const RegistrationFormController &other) : QObject(other.parent())
//{

//}

void RegistrationFormController::processLogin(RegistrationFormData *data)
{

    QVariantMap map;
    map.insert(RegistrationFormData::NameKey, data->getName());
    map.insert(RegistrationFormData::PasswordKey, data->getPassword());

    auto req = new GenericServiceRequest(this);
    req->setMessageType(ServiceMessageType::Req_Login);
    req->setContent(map);

    m_service.makeRequest(req);
    req->deleteLater();
}

void RegistrationFormController::processRegistration(RegistrationFormData *data)
{
    SerializationInfo info;
    data->getObjectInfo(info);
    auto map = info.toMap();

    auto req = new GenericServiceRequest(this);
    req->setMessageType(ServiceMessageType::Req_Register);
    req->setContent(map);

    m_service.makeRequest(req);
    req->deleteLater();

}
