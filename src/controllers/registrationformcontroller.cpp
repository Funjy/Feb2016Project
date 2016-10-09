#include "registrationformcontroller.h"

#include "core/applicationsettings.h"

using namespace PhotoFlyControllers;
using namespace PhotoFlySettings;

RegistrationFormController::RegistrationFormController(QObject *parent) : QObject(parent)
{
    m_status = S_Ready;
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

    handleRequest(req);
}

void RegistrationFormController::processRegistration(RegistrationFormData *data)
{
    SerializationInfo info;
    data->getObjectInfo(info);
    auto map = info.asMap();

    auto req = new GenericServiceRequest(this);
    req->setMessageType(ServiceMessageType::Req_Register);
    req->setContent(map);

    handleRequest(req);
}

RegFormReqStatus RegistrationFormController::status() const
{
    return m_status;
}

void RegistrationFormController::setStatus(const RegFormReqStatus &status)
{
    m_status = status;
}

void RegistrationFormController::handleRequest(GenericServiceRequest *request)
{
    m_status = S_InProgress;
    emit requstStatusChanged();

    QtConcurrent::run( [&, request] {
//        m_service.makeRequest(request);
        QThread::msleep(500);
        handleResponse(request);
    });
}

//        QMetaObject::invokeMethod(this, "handleResponse",
//                                  Qt::QueuedConnection,
//                                  Q_ARG(GenericServiceRequest *, request));
void RegistrationFormController::handleResponse(GenericServiceRequest *request)
{

    auto status = request->getResultStatus();
    // Debug
    status = RequestResultStatus::Ok;

    bool ok = status != RequestResultStatus::Fail;

    request->deleteLater();
    m_status = S_Ready;
    emit requstStatusChanged();
    emit requestResult(ok, "No connection");
}
