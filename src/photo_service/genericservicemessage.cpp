#include "genericservicemessage.h"

using namespace PhotoFlyService;

GenericServiceMessage::GenericServiceMessage(QObject *parent) : QObject(parent)
{

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

ServiceMessage::Type GenericServiceMessage::getType() const
{
    return m_type;
}

void GenericServiceMessage::setType(ServiceMessage::Type value)
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
