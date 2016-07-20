#include "registrationformdata.h"

RegistrationFormData::RegistrationFormData(QObject *parent) : QObject(parent)
{

}

RegistrationFormData::RegistrationFormData(const RegistrationFormData &other) : QObject()
{
    m_name = other.m_name;
    m_ccn = other.m_ccn;
}
