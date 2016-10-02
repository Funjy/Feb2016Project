#include "servicemessage.h"

using namespace PhotoFlyService;

const QString ServiceMessage::TypeId =                  "ServiceMessage";

const QString ServiceMessage::MessageTypeKey =          "MessageType";
const QString ServiceMessage::LoginTypeString =         "Login";
const QString ServiceMessage::RegisterTypeString =      "Register";
const QString ServiceMessage::SendPhotosTypeString =    "SendPhotos";
const QString ServiceMessage::UndefinedTypeString =     "Undefined";

QMap<const QString*, ServiceMessage::MessageType>  ServiceMessage::m_typeByString;
QMap<ServiceMessage::MessageType, const QString*>  ServiceMessage::m_stringByType;
QList<QString>                              ServiceMessage::m_stringTypes;

QString ServiceMessage::getTypeString() const
{
    return getTypeString(getMessageType());
//    switch(getType()){
//    case Type::Login:
//        return LoginTypeString;
//    default:
//        return UndefinedTypeString;
    //    }
}

QString ServiceMessage::getTypeString(ServiceMessageType value)
{
    initTypes();
    if(!m_stringByType.contains(value)){
        return UndefinedTypeString;
    }
    return *m_stringByType[value];
}

ServiceMessageType ServiceMessage::getTypeByString(const QString &value)
{
    initTypes();
    for(auto key: m_typeByString.keys())
    {
        if(*key == value)
            return m_typeByString[key];

    }
    return MessageType::Undefined;
}

void ServiceMessage::getObjectInfo(PhotoFlyContainers::SerializationInfo &info) const
{
//    info.addValue(TypeKey, (int)getType());
    info.addValue(MessageTypeKey, getTypeString());
#if USE_ServiceMessage_TYPEID == 1
    info.setTypeId(TypeId);
#endif
}

void ServiceMessage::addPair(const QString &str, ServiceMessage::MessageType type)
{
    m_stringTypes << str;
    m_typeByString.insert(&m_stringTypes.last(), type);
    m_stringByType.insert(type, &m_stringTypes.last());
}

void ServiceMessage::initTypes()
{
    if(!m_stringTypes.isEmpty())
        return;
    addPair(LoginTypeString,        MessageType::Req_Login);
    addPair(RegisterTypeString,     MessageType::Req_Register);
    addPair(SendPhotosTypeString,   MessageType::Req_SendPhotos);
    addPair(UndefinedTypeString,    MessageType::Undefined);
}
