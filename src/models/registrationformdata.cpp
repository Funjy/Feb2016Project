#include "registrationformdata.h"

using namespace PhotoFlyModels;

const QString RegistrationFormData::UserInfoGroup =         "UserInfo";

const QString RegistrationFormData::NameKey =               "UserName";
const QString RegistrationFormData::SurnameKey =            "Surname";
const QString RegistrationFormData::EmailKey =              "Email";
const QString RegistrationFormData::PasswordKey =           "Password";
const QString RegistrationFormData::PostalAddressKey =      "PostalAddress";
const QString RegistrationFormData::PhoneNumberKey =        "PhoneNumber";
const QString RegistrationFormData::CCNListKey =            "CCNList";

RegistrationFormData::RegistrationFormData(QObject *parent) : QObject(parent)
{
    m_isValid = false;
    m_passwordType = PT_Direct;
}

//RegistrationFormData::RegistrationFormData(const RegistrationFormData &other) : QObject()
//{
//    SerializationInfo si;
//    other.getObjectInfo(si);
//    deserialize(si);
//}

void RegistrationFormData::getObjectInfo(SerializationInfo &info) const
{
#if USE_RegistrationFormData_TYPEID == 1
    info.setTypeId(metaObject()->className());
#endif

    info.asMap().insert(NameKey,          getName());
    info.asMap().insert(SurnameKey,       getSurname());
    info.asMap().insert(PostalAddressKey, getPostalAddress());
    info.asMap().insert(EmailKey,         getEmail());
    info.asMap().insert(PasswordKey,      getPassword());
    info.asMap().insert(PhoneNumberKey,   getPhoneNumber());
}

void RegistrationFormData::deserialize(const SerializationInfo &info)
{
#if USE_RegistrationFormData_TYPEID == 1
    if (info.getTypeId() != metaObject()->className())
        return;
#endif

    m_name = info.asMap()[NameKey].toString();
    m_surname = info.asMap()[SurnameKey].toString();
    m_postalAddress = info.asMap()[PostalAddressKey].toString();
    m_email = info.asMap()[EmailKey].toString();
    m_password = info.asMap()[PasswordKey].toString();
    m_phoneNumber = info.asMap()[PhoneNumberKey].toString();

}

bool RegistrationFormData::isValid() const
{
    return !(m_name == m_surname && m_name.isEmpty());
//    return m_isValid;
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

QString RegistrationFormData::getPostalAddress() const
{
    return m_postalAddress;
}

void RegistrationFormData::setPostalAddress(const QString &postalAddress)
{
    m_postalAddress = postalAddress;
}

PasswordStorageType RegistrationFormData::getPasswordType() const
{
    return m_passwordType;
}

void RegistrationFormData::setPasswordType(const PasswordType &passwordType)
{
    m_passwordType = passwordType;
}

QString RegistrationFormData::getPhoneNumber() const
{
    return m_phoneNumber;
}

void RegistrationFormData::setPhoneNumber(const QString &phoneNumber)
{
    m_phoneNumber = phoneNumber;
}

//const QStringList &RegistrationFormData::properties2Serialize()
//{
//    static QStringList toRet;

//    if (toRet.isEmpty()) {
//        toRet << NameKey;
//        toRet << SurnameKey;
//        toRet << PostalAddressKey;
//        toRet << EmailKey;
//        toRet << PasswordKey;
//        toRet << PhoneNumberKey;
//    }

//    return toRet;
//}
