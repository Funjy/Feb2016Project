#ifndef SERVICEMESSAGE_H
#define SERVICEMESSAGE_H

#include <QtGlobal>

#include "../behaviours/iserializable.h"
#define ServiceMessageType PhotoFlyService::ServiceMessage::Type

namespace PhotoFlyService {
using namespace PhotoFlyBehaviours;

class ServiceMessage : public ISerializable
{

    Q_DISABLE_COPY(ServiceMessage)
    Q_GADGET

public:
    static const QString LoginTypeString;
    static const QString RegisterTypeString;
    static const QString SendPhotosTypeString;
    static const QString UndefinedTypeString;

    enum Type{
        Undefined,
        Login,
        Register,
        SendPhotos
    };
    Q_ENUM(ServiceMessageType)

    virtual ~ServiceMessage(){}

    virtual Type getType() const = 0;
    QString getTypeString() const;

    static QString getTypeString(ServiceMessageType value);
    static ServiceMessageType getTypeByString(const QString& value);


    // ISerializable interface
    virtual void getObjectInfo(PhotoFlyContainers::SerializationInfo &info) const override;

protected:
    explicit ServiceMessage();

    static const QString TypeKey;

private:
    static QMap<const QString*, Type> m_typeByString;
    static QMap<Type, const QString*> m_stringByType;
    static void addPair(const QString& str, Type type);

    static QList<QString>   m_stringTypes;



};

}

#endif // SERVICEMESSAGE_H
