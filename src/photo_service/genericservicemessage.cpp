#include "genericservicemessage.h"

#include <QDebug>

using namespace PhotoFlyService;

const QString GenericServiceMessage::TypeId =       "GenericServiceMessage";
const QString GenericServiceMessage::ContentKey =   "Content";

GenericServiceMessage::GenericServiceMessage(QObject *parent) : QObject(parent)
{
    m_type = MessageType::Undefined;
}

GenericServiceMessage::GenericServiceMessage(ServiceMessage::MessageType type, const QVariantMap &content, QObject *parent) :
    GenericServiceMessage(parent)
{
    m_type = type;
    m_content = content;
}

GenericServiceMessage::GenericServiceMessage(const GenericServiceMessage &other) :
//   QObject(other.parent()), m_type(other.m_type), m_content(other.m_content)
    GenericServiceMessage(other.m_type, other.m_content, other.parent())
{
}

//GenericServiceMessage::GenericServiceMessage(GenericServiceMessage &&other) :
//    GenericServiceMessage(other.parent())
//{
//    qDebug() << "move ctor";
//    GenericServiceMessage::swap(*this, other);
//}

GenericServiceMessage &GenericServiceMessage::operator=(const GenericServiceMessage &other)
//GenericServiceMessage &GenericServiceMessage::operator=(GenericServiceMessage other)
{
     if(this != &other)
         GenericServiceMessage(other).swap(*this);
//    using std::swap;
//    std::swap(*this, other);
    return *this;
}

void GenericServiceMessage::swap(GenericServiceMessage &_v) throw()
{
    GenericServiceMessage::swap(*this, _v);
}

void GenericServiceMessage::swap(GenericServiceMessage &first, GenericServiceMessage &second) throw()
{
    std::swap(first.m_type, second.m_type);
    first.m_content.swap(second.m_content);
}

QVariantMap &GenericServiceMessage::contentData()
{
    return m_content;
}

void GenericServiceMessage::getObjectInfo(SerializationInfo &info) const
{
    ServiceMessage::getObjectInfo(info);
    info.insert(ContentKey, QVariant::fromValue(m_content));
    info.insert(MessageTypeKey, QVariant::fromValue(getMessageType()));
#if USE_ServiceMessage_TYPEID == 1
    info.setTypeId(metaObject()->className());
#endif
}

void GenericServiceMessage::deserialize(const SerializationInfo &info)
{
    auto map = info.asMap();
//    setMessageType(map[MessageTypeKey].toString());
    setMessageType(map[MessageTypeKey].value<ServiceMessageType>());
    setContent(map[ContentKey].toMap());
}

ServiceMessageType GenericServiceMessage::getMessageType() const
{
    return m_type;
}

void GenericServiceMessage::setMessageType(ServiceMessageType value)
{
    m_type = value;
}

void GenericServiceMessage::setMessageType(const QString &value)
{
    m_type = getTypeByString(value);
}

const QVariantMap &GenericServiceMessage::getContent() const
{
    return m_content;
}

void GenericServiceMessage::setContent(const QVariantMap &content)
{
    m_content = content;
}
