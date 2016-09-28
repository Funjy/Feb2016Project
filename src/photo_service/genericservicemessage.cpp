#include "genericservicemessage.h"

#include <QDebug>

using namespace PhotoFlyService;

GenericServiceMessage::GenericServiceMessage(QObject *parent) : QObject(parent)
{    
    m_type = Type::Undefined;
}

GenericServiceMessage::GenericServiceMessage(const GenericServiceMessage &other) :
   QObject(other.parent()), m_type(other.m_type), m_content(other.m_content)
{
    qDebug() << "copy ctor";
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
//    swap(*this, other);

    qDebug() << "equation";

//    std::swap(*this, other);
    return *this;
}

void GenericServiceMessage::swap(GenericServiceMessage &_v) throw()
{
    GenericServiceMessage::swap(*this, _v);
//    std::swap(m_type, _v.m_type);
//    m_content.swap(_v.m_content);
}

void GenericServiceMessage::swap(GenericServiceMessage &first, GenericServiceMessage &second) throw()
{
    qDebug() << "swap 2";
    std::swap(first.m_type, second.m_type);
    first.m_content.swap(second.m_content);
}

void GenericServiceMessage::getObjectInfo(PhotoFlyContainers::SerializationInfo &info)
{
    ServiceMessage::getObjectInfo(info);
    //    foreach(auto key, )
    for( auto key : m_content.keys() )
    {
        info.addValue(key, m_content[key]);
    }

}

ServiceMessageType GenericServiceMessage::getType() const
{
    return m_type;
}

void GenericServiceMessage::setType(ServiceMessageType value)
{
    m_type = value;
}

QVariantMap GenericServiceMessage::getContent() const
{
    return m_content;
}

void GenericServiceMessage::setContent(const QVariantMap &content)
{
    m_content = content;
}
