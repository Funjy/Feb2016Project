#ifndef SERVICEMESSAGE_H
#define SERVICEMESSAGE_H

#include <QtGlobal>

#include "../behaviours/iserializable.h"
#define ServiceMessageType  PhotoFlyService::ServiceMessage::MessageType

#define USE_ServiceMessage_TYPEID 0

namespace PhotoFlyService {
using namespace PhotoFlyBehaviours;

class ServiceMessage : public ISerializable
{

    Q_DISABLE_COPY(ServiceMessage)
    Q_GADGET

public:
    static const QString MessageTypeKey;

    static const QString LoginTypeString;
    static const QString RegisterTypeString;
    static const QString SendPhotosTypeString;
    static const QString UndefinedTypeString;

    enum MessageType{
        Undefined,
        Get_generic,
        Req_Login,
        Req_Register,
        Req_SendPhotos
    };
    Q_ENUM(ServiceMessageType)

    virtual ~ServiceMessage(){}

    virtual MessageType getMessageType() const = 0;
    QString getTypeString() const;

    static QString getTypeString(ServiceMessageType value);
    static ServiceMessageType getTypeByString(const QString& value);

    // ISerializable interface
    virtual void getObjectInfo(PhotoFlyContainers::SerializationInfo &info) const override;

protected:
    explicit ServiceMessage() {}

private:
    static QMap<const QString*, MessageType> m_typeByString;
    static QMap<MessageType, const QString*> m_stringByType;
    static void addPair(const QString& str, MessageType type);

    static QList<QString>   m_stringTypes;

    static const QString TypeId;

    static void initTypes();

};

}

#endif // SERVICEMESSAGE_H
