#ifndef REGISTRATIONFORMCONTROLLER_H
#define REGISTRATIONFORMCONTROLLER_H

#include <QObject>
#include <QtConcurrent/QtConcurrent>

#include "models/registrationformdata.h"
#include "photo_service/serviceprovider.h"
#include "core/applicationsettings.h"

#define RegFormReqStatus  PhotoFlyControllers::RegistrationFormController::Status

namespace PhotoFlyControllers{
using namespace PhotoFlyModels;
using namespace PhotoFlyService;
using namespace PhotoFlySettings;

class RegistrationFormController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(RegistrationFormController)

    Q_PROPERTY(Status requstStatus READ status NOTIFY requstStatusChanged)

public:
    explicit RegistrationFormController(QObject *parent = 0);
//    explicit RegistrationFormController(const RegistrationFormController& other);

    enum Status{
        S_InProgress,
        S_Ready
    };
    Q_ENUM(Status)

    Q_INVOKABLE void processLogin(RegistrationFormData* data);
    Q_INVOKABLE void processRegistration(RegistrationFormData* data);

    RegFormReqStatus status() const;
//    int status() const;
    void setStatus(const RegFormReqStatus &status);
    void setStatus(int status);

signals:
    void requstStatusChanged();
    void requestResult(bool status, QString message);

public slots:

private:
    ServiceProvider *m_service;
    RegFormReqStatus m_status;

    void handleRequest(GenericServiceRequest *request);
    void handleResponse(GenericServiceRequest *request);

    bool handleLoginResponse(GenericServiceRequest *request, QString *errorString);

};

}

Q_DECLARE_METATYPE(PhotoFlyControllers::RegistrationFormController*)

#endif // REGISTRATIONFORMCONTROLLER_H
