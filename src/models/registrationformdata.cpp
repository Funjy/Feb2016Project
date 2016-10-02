#include "registrationformdata.h"

using namespace PhotoFlyModels;

const QString RegistrationFormData::NameKey =               "UserName";
const QString RegistrationFormData::SurnameKey =            "Surname";
const QString RegistrationFormData::EmailKey =              "Email";
const QString RegistrationFormData::PasswordKey =           "Password";
const QString RegistrationFormData::PostalAddressKey =      "PostalAddress";
const QString RegistrationFormData::CCNListKey =            "CCNList";

RegistrationFormData::RegistrationFormData(QObject *parent) : QObject(parent)
{
    m_isValid = false;
    m_passwordType = PT_Direct;
}

RegistrationFormData::RegistrationFormData(const RegistrationFormData &other) : QObject()
{
    m_name = other.m_name;
    m_surname = other.m_surname;
    m_email = other.m_email;
    m_password = other.m_password;
}

void RegistrationFormData::getObjectInfo(PhotoFlyContainers::SerializationInfo &info) const
{
    info.setTypeId(metaObject()->className());

    info.addValue(NameKey, m_name);
    info.addValue(EmailKey, m_email);
    info.addValue(PasswordKey, m_password);
}

bool RegistrationFormData::isValid() const
{
    return m_isValid;
}

QVariant RegistrationFormData::ccnList() const
{
    return QVariant::fromValue(m_ccnList.values());
}

QString RegistrationFormData::getName() const
{
    return m_name;
}

void RegistrationFormData::setName(const QString &name)
{
    m_name = name;
}

QString RegistrationFormData::getSurname() const
{
    return m_surname;
}

void RegistrationFormData::setSurname(const QString &surname)
{
    m_surname = surname;
}

QString RegistrationFormData::getEmail() const
{
    return m_email;
}

void RegistrationFormData::setEmail(const QString &email)
{
    m_email = email;
}

QString RegistrationFormData::getPassword() const
{
    return m_password;
}

void RegistrationFormData::setPassword(const QString &password)
{
    m_password = password;
}

QMap<uint, QString> RegistrationFormData::getCcnList() const
{
    return m_ccnList;
}

void RegistrationFormData::setCcnList(const QMap<uint, QString> &ccnList)
{
    m_ccnList = ccnList;
}

QString RegistrationFormData::getPoastalAddress() const
{
    return m_poastalAddress;
}

void RegistrationFormData::setPoastalAddress(const QString &poastalAddress)
{
    m_poastalAddress = poastalAddress;
}

PasswordStorageType RegistrationFormData::getPasswordType() const
{
    return m_passwordType;
}

void RegistrationFormData::setPasswordType(const PasswordType &passwordType)
{
    m_passwordType = passwordType;
}
