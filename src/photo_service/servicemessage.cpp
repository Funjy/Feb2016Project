#include "servicemessage.h"

using namespace PhotoFlyService;

const QString ServiceMessage::TypeId =                  "ServiceMessage";

const QString ServiceMessage::TypeKey =                 "RequestType";
const QString ServiceMessage::LoginTypeString =         "Login";
const QString ServiceMessage::RegisterTypeString =      "Register";
const QString ServiceMessage::SendPhotosTypeString =    "SendPhotos";
const QString ServiceMessage::UndefinedTypeString =     "Undefined";

QMap<const QString*, ServiceMessage::RequestType>  ServiceMessage::m_typeByString;
QMap<ServiceMessage::RequestType, const QString*>  ServiceMessage::m_stringByType;
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

QString ServiceMessage::getTypeString(ServiceRequestType value)
{
    initTypes();
    if(!m_stringByType.contains(value)){
        return UndefinedTypeString;
    }
    return *m_stringByType[value];
}

ServiceRequestType ServiceMessage::getTypeByString(const QString &value)
{
    initTypes();
    for(auto key: m_typeByString.keys())
    {
        if(*key == value)
            return m_typeByString[key];

    }
    return RequestType::Req_Undefined;
}

void ServiceMessage::getObjectInfo(PhotoFlyContainers::SerializationInfo &info) const
{
//    info.addValue(TypeKey, (int)getType());
    info.addValue(TypeKey, getTypeString());
    info.setTypeId(TypeId);
}

void ServiceMessage::addPair(const QString &str, ServiceMessage::RequestType type)
{
    m_stringTypes << str;
    m_typeByString.insert(&m_stringTypes.last(), type);
    m_stringByType.insert(type, &m_stringTypes.last());
}

void ServiceMessage::initTypes()
{
    if(!m_stringTypes.isEmpty())
        return;
    addPair(LoginTypeString,        RequestType::Req_Login);
    addPair(RegisterTypeString,     RequestType::Req_Register);
    addPair(SendPhotosTypeString,   RequestType::Req_SendPhotos);
    addPair(UndefinedTypeString,    RequestType::Req_Undefined);
}
