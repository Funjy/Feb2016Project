#include "serializationinfo.h"

using namespace PhotoFlyContainers;

SerializationInfo::SerializationInfo(QObject *parent) : QObject(parent)
{

}

void SerializationInfo::addValue(QString name, QVariant value)
{
    m_data.insert(name, value);
}

QVariant SerializationInfo::value(QString name)
{
    return m_data.contains(name) ? m_data[name] : QVariant();
}

bool SerializationInfo::equals(const SerializationInfo &other)
{
    if(other.m_data.count() != m_data.count())
        return false;

    foreach(auto key, m_data.keys()){
        if(!other.m_data.contains(key))
            return false;
        if(other.m_data[key] != m_data[key])
            return false;
    }

    return true;
}

QList<QString> SerializationInfo::getKeys() const
{
    return m_data.keys();
}
