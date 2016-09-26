#include "loginrequest.h"

using namespace PhotoFlyService;

const QString LoginRequest::LoginKey =    "Login";
const QString LoginRequest::PasswordKey = "Password";

LoginRequest::LoginRequest(QObject *parent) : ServiceRequest(parent)
{

}

LoginRequest::LoginRequest(const QString &login, const QString &password):
    m_login(login), m_password(password)
{

}

ServiceRequest::Type LoginRequest::getType() const
{
    return ServiceRequest::Type::Login;
}

void LoginRequest::getObjectInfo(PhotoFlyContainers::SerializationInfo &info)
{
    ServiceMessage::getObjectInfo(info);
    info.addValue(LoginKey, m_login);
    info.addValue(PasswordKey, m_password);
}

QString LoginRequest::login() const
{
    return m_login;
}

void LoginRequest::setLogin(const QString &login)
{
    m_login = login;
}

QString LoginRequest::password() const
{
    return m_password;
}

void LoginRequest::setPassword(const QString &password)
{
    m_password = password;
}
