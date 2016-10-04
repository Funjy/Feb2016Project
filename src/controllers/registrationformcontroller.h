#ifndef REGISTRATIONFORMCONTROLLER_H
#define REGISTRATIONFORMCONTROLLER_H

#include <QObject>
#include <QtConcurrent/QtConcurrent>

#include "models/registrationformdata.h"
#include "photo_service/serviceprovider.h"

#define RegFormReqStatus  PhotoFlyControllers::RegistrationFormController::Status

namespace PhotoFlyControllers{
using namespace PhotoFlyModels;
using namespace PhotoFlyService;

class RegistrationFormController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(RegistrationFormController)

    Q_PROPERTY(RegFormReqStatus requstStatus READ status WRITE setStatus NOTIFY requstStatusChanged)

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
    void setStatus(const RegFormReqStatus &status);

signals:
    void requstStatusChanged();
    void requestResult(bool status, QString message);

public slots:

private:
    ServiceProvider m_service;
    RegFormReqStatus m_status;

    void handleRequest(GenericServiceRequest *request);
    Q_INVOKABLE void handleResponse(GenericServiceRequest *request);

};

}

Q_DECLARE_METATYPE(PhotoFlyControllers::RegistrationFormController*)

#endif // REGISTRATIONFORMCONTROLLER_H
