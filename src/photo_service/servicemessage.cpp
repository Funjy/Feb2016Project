#include "servicemessage.h"

using namespace PhotoFlyService;

const QString ServiceMessage::TypeKey =             "MessageType";
const QString ServiceMessage::LoginTypeString =     "Login";
const QString ServiceMessage::UndefinedTypeString = "Undefined";

QMap<QString, ServiceMessage::Type> ServiceMessage::m_typeByString;
QMap<ServiceMessage::Type, QString> ServiceMessage::m_stringByType;

QString ServiceMessage::getTypeString() const
{
    return getTypeString(getType());
//    switch(getType()){
//    case Type::Login:
//        return LoginTypeString;
//    default:
//        return UndefinedTypeString;
    //    }
}

QString ServiceMessage::getTypeString(ServiceMessage::Type value)
{
    if(!m_stringByType.contains(value)){
        return UndefinedTypeString;
    }
    return m_stringByType[value];
}

ServiceMessage::Type ServiceMessage::getTypeByString(const QString &value)
{
    if(!m_typeByString.contains(value)){
        return Type::Undefined;
    }
    return m_typeByString[value];
}

void ServiceMessage::getObjectInfo(PhotoFlyContainers::SerializationInfo &info)
{
//    info.addValue(TypeKey, (int)getType());
    info.addValue(TypeKey, getTypeString());
}

ServiceMessage::ServiceMessage()
{
    addPair(LoginTypeString, Type::Login);
}

void ServiceMessage::addPair(const QString &str, ServiceMessage::Type type)
{
    m_typeByString.insert(str, type);
    m_stringByType.insert(type, str);
}
