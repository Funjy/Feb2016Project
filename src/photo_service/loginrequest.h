#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

#include <QObject>

#include "genericservicerequest.h"

namespace PhotoFlyService {

class LoginRequest : public GenericServiceRequest
{
    Q_OBJECT
    Q_PROPERTY(QString login READ login WRITE setLogin NOTIFY loginChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
public:
    explicit LoginRequest(QObject *parent = nullptr);
    explicit LoginRequest(const QString& login, const QString& password);
    LoginRequest(const LoginRequest& other) : LoginRequest(other.parent()) { Q_UNUSED(other) }
    LoginRequest &operator=(const LoginRequest &other) { Q_UNUSED(other) return *this;}

    // ServiceMessage interface
    virtual MessageType getMessageType() const override;

    // ISerializable interface
    virtual void getObjectInfo(PhotoFlyContainers::SerializationInfo &info) const override;

    QString login() const;
    void setLogin(const QString &login);

    QString password() const;
    void setPassword(const QString &password);

signals:
    void loginChanged();
    void passwordChanged();

private:

    static const QString LoginKey;
    static const QString PasswordKey;

    QString m_login;
    QString m_password;

};

}
Q_DECLARE_METATYPE(PhotoFlyService::LoginRequest)

#endif // LOGINREQUEST_H
