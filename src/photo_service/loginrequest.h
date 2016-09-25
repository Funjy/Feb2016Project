#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

#include <QObject>
#include "servicerequest.h"

namespace PhotoFlyService {

class LoginRequest : public ServiceRequest
{
public:
    explicit LoginRequest();
    explicit LoginRequest(const QString& login, const QString& password);

    // ServiceRequest interface
    virtual Type getType() const override;

    QString getLogin() const;
    void setLogin(const QString &login);

    QString getPassword() const;
    void setPassword(const QString &password);

private:

    QString m_login;
    QString m_password;

};

}

#endif // LOGINREQUEST_H
