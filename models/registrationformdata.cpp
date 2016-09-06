#include "registrationformdata.h"

RegistrationFormData::RegistrationFormData(QObject *parent) : QObject(parent)
{
    m_isValid = false;
}

RegistrationFormData::RegistrationFormData(const RegistrationFormData &other) : QObject()
{
    m_name = other.m_name;
    m_surname = other.m_surname;
}

bool RegistrationFormData::isValid() const
{
    return m_isValid;
}

QVariant RegistrationFormData::ccnList() const
{
    return QVariant::fromValue(m_ccnList.values());
}
