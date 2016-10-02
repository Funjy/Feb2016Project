#ifndef SERVICEMESSAGE_H
#define SERVICEMESSAGE_H

#include <QtGlobal>

#include "../behaviours/iserializable.h"
#define ServiceRequestType  PhotoFlyService::ServiceMessage::RequestType
#define ServiceResponseType PhotoFlyService::ServiceMessage::ResponseType

namespace PhotoFlyService {
using namespace PhotoFlyBehaviours;

class ServiceMessage : public ISerializable
{

    Q_DISABLE_COPY(ServiceMessage)
    Q_GADGET

public:
    static const QString TypeKey;

    static const QString LoginTypeString;
    static const QString RegisterTypeString;
    static const QString SendPhotosTypeString;
    static const QString UndefinedTypeString;

    enum RequestType{
        Req_Undefined,
        Req_Login,
        Req_Register,
        Req_SendPhotos
    };
    Q_ENUM(ServiceRequestType)

    enum ResponseType{
        Resp_Undefined
    };
    Q_ENUM(ServiceResponseType)

    virtual ~ServiceMessage(){}

    virtual RequestType getType() const = 0;
    QString getTypeString() const;

    static QString getTypeString(ServiceRequestType value);
    static ServiceRequestType getTypeByString(const QString& value);

    // ISerializable interface
    virtual void getObjectInfo(PhotoFlyContainers::SerializationInfo &info) const override;

protected:
    explicit ServiceMessage() {}

private:
    static QMap<const QString*, RequestType> m_typeByString;
    static QMap<RequestType, const QString*> m_stringByType;
    static void addPair(const QString& str, RequestType type);

    static QList<QString>   m_stringTypes;

    static const QString TypeId;

    static void initTypes();

};

}

#endif // SERVICEMESSAGE_H
