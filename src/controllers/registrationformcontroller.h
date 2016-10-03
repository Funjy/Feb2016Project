#ifndef REGISTRATIONFORMCONTROLLER_H
#define REGISTRATIONFORMCONTROLLER_H

#include <QObject>

#include "models/registrationformdata.h"
#include "photo_service/serviceprovider.h"

namespace PhotoFlyControllers{
using namespace PhotoFlyModels;
using namespace PhotoFlyService;

class RegistrationFormController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(RegistrationFormController)

public:
    explicit RegistrationFormController(QObject *parent = 0);
//    explicit RegistrationFormController(const RegistrationFormController& other);

    Q_INVOKABLE void processLogin(RegistrationFormData* data);
    Q_INVOKABLE void processRegistration(RegistrationFormData* data);

signals:

public slots:

private:
    ServiceProvider m_service;

};

}

Q_DECLARE_METATYPE(PhotoFlyControllers::RegistrationFormController*)

#endif // REGISTRATIONFORMCONTROLLER_H
