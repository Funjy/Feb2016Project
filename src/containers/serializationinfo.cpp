#include "serializationinfo.h"

using namespace PhotoFlyContainers;

const QString SerializationInfo::TypeIdKey =            "TypeId";
const QString SerializationInfo::UndefinedTypeIdStr =   "Undefined";

SerializationInfo::SerializationInfo(QObject *parent) : QObject(parent)
{

}

SerializationInfo::SerializationInfo(QVariantMap map, QObject *parent) : SerializationInfo(parent)
{
    m_data = map;
}

SerializationInfo::SerializationInfo(const SerializationInfo &other) : QObject(other.parent())
{
    m_data = other.m_data;
}

SerializationInfo &SerializationInfo::operator=(const SerializationInfo &other)
{
    if(this != &other){
        SerializationInfo(other).swap(*this);
    }
    return *this;
}

void SerializationInfo::addValue(QString name, QVariant value)
{
    m_data.insert(name, value);
}

void SerializationInfo::addValue(QString name, const SerializationInfo &value)
{
    m_data.insert(name, value.m_data);
}

QVariant SerializationInfo::value(QString name)
{
    return m_data.contains(name) ? m_data[name] : QVariant();
}

bool SerializationInfo::equals(const SerializationInfo &other)
{
    return m_data == other.m_data;
}

QString SerializationInfo::getTypeId() const
{
    if(!m_data.contains(TypeIdKey))
        return UndefinedTypeIdStr;
    return m_data[TypeIdKey].toString();
}

void SerializationInfo::setTypeId(const QString &typeId)
{
    m_data[TypeIdKey] = typeId;
}

QList<QString> SerializationInfo::getKeys() const
{
    return m_data.keys();
}

void SerializationInfo::swap(SerializationInfo &_v) throw()
{
    m_data.swap(_v.m_data);
}
