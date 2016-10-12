#include "registrationformcontroller.h"

#include "core/applicationsettings.h"

using namespace PhotoFlyControllers;
using namespace PhotoFlySettings;

RegistrationFormController::RegistrationFormController(QObject *parent) : QObject(parent)
{
    m_status = S_Ready;
    emit requstStatusChanged();
    m_service = new ServiceProvider();
}

//RegistrationFormController::RegistrationFormController(const RegistrationFormController &other) : QObject(other.parent())
//{

//}

void RegistrationFormController::processLogin(RegistrationFormData *data)
{

    QVariantMap map;
    map.insert(RegistrationFormData::EmailKey, data->getEmail());
    map.insert(RegistrationFormData::PasswordKey, data->getPassword());

    auto req = new GenericServiceRequest(this);
    req->setMessageType(ServiceMessageType::Req_Login);
    req->setContent(map);

    // tmp
    req->urlParameters().insert("user", data->getEmail());

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

//int RegistrationFormController::status() const
//{
//    return static_cast<int>(m_status);
//}

void RegistrationFormController::setStatus(int status)
{
    m_status = static_cast<RegFormReqStatus>(status);
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
        m_service->makeRequest(request);
//        QThread::msleep(500);
        handleResponse(request);
    });

}

//        QMetaObject::invokeMethod(this, "handleResponse",
//                                  Qt::QueuedConnection,
//                                 Q_ARG(GenericServiceRequest *, request));
void RegistrationFormController::handleResponse(GenericServiceRequest *request)
{

    auto status = request->getResultStatus();

    bool ok = status != RequestResultStatus::Fail;
    QString errorMessage = request->getErrorString();// tr("No connection");

    if (ok) {
        if (request->getMessageType() == ServiceMessageType::Req_Login) {
            ok = handleLoginResponse(request, &errorMessage);
        } else {
            ok = false;
            errorMessage = tr("Unknown request type");
        }
    }

    request->deleteLater();
    m_status = S_Ready;
    emit requstStatusChanged();
//    ok = true;
    emit requestResult(ok, errorMessage);
}

bool RegistrationFormController::handleLoginResponse(GenericServiceRequest *request, QString *errorString)
{
    if (!request) {
        *errorString = "inner error: handleLoginResponse";
        return false;
    }
    SerializationInfo si;
    request->getObjectInfo(si);

    auto reqCont =  si[GenericServiceRequest::ContentKey].toMap();
    auto respCont = si[GenericServiceRequest::ResultKey].toMap()[GenericServiceRequest::ContentKey].toMap();

    bool correctUser =
            respCont[RegistrationFormData::EmailKey].toString() ==
                reqCont[RegistrationFormData::EmailKey].toString() &&
            respCont[RegistrationFormData::PasswordKey].toString() ==
                reqCont[RegistrationFormData::PasswordKey].toString();

    if (correctUser) {
        RegistrationFormData userData;
        userData.deserialize(respCont);
//        appSettings.saveUserInfo(userData);
        return true;
    }

    *errorString = tr("Wrong user credentials");
    return false;

}
