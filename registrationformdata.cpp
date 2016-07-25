#include "registrationformdata.h"

RegistrationFormData::RegistrationFormData(QObject *parent) : QObject(parent)
{

}

RegistrationFormData::RegistrationFormData(const RegistrationFormData &other) : QObject()
{
    m_name = other.m_name;
    m_surname = other.m_surname;
}

QVariant RegistrationFormData::ccnList() const
{
    return QVariant::fromValue(m_ccnList.values());
}
