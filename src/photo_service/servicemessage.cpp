#include "servicemessage.h"

using namespace PhotoFlyService;

const QString ServiceMessage::TypeKey =                 "MessageType";
const QString ServiceMessage::LoginTypeString =         "Login";
const QString ServiceMessage::RegisterTypeString =      "Register";
const QString ServiceMessage::SendPhotosTypeString =    "SendPhotos";
const QString ServiceMessage::UndefinedTypeString =     "Undefined";

QMap<const QString*, ServiceMessage::Type>  ServiceMessage::m_typeByString;
QMap<ServiceMessage::Type, const QString*>  ServiceMessage::m_stringByType;
QList<QString>                              ServiceMessage::m_stringTypes;

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

QString ServiceMessage::getTypeString(ServiceMessageType value)
{
    if(!m_stringByType.contains(value)){
        return UndefinedTypeString;
    }
    return *m_stringByType[value];
}

ServiceMessageType ServiceMessage::getTypeByString(const QString &value)
{
//    if(!m_typeByString.contains(&value)){
//        return Type::Undefined;
//    }
    for(auto key: m_typeByString.keys())
    {
        if(*key == value)
            return m_typeByString[key];

    }
    return Type::Undefined;
}

void ServiceMessage::getObjectInfo(PhotoFlyContainers::SerializationInfo &info) const
{
//    info.addValue(TypeKey, (int)getType());
    info.addValue(TypeKey, getTypeString());
}

ServiceMessage::ServiceMessage()
{
    addPair(LoginTypeString,        Type::Login);
    addPair(RegisterTypeString,     Type::Register);
    addPair(SendPhotosTypeString,   Type::SendPhotos);
}

void ServiceMessage::addPair(const QString &str, ServiceMessage::Type type)
{
    m_stringTypes << str;
    m_typeByString.insert(&m_stringTypes.last(), type);
    m_stringByType.insert(type, &m_stringTypes.last());
}
