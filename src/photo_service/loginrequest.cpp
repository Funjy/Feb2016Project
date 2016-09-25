#include "loginrequest.h"

using namespace PhotoFlyService;

LoginRequest::LoginRequest()
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

QString LoginRequest::getLogin() const
{
    return m_login;
}

void LoginRequest::setLogin(const QString &login)
{
    m_login = login;
}

QString LoginRequest::getPassword() const
{
    return m_password;
}

void LoginRequest::setPassword(const QString &password)
{
    m_password = password;
}
