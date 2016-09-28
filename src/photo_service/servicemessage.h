#ifndef SERVICEMESSAGE_H
#define SERVICEMESSAGE_H

#include <QtGlobal>

#include "../behaviours/iserializable.h"

namespace PhotoFlyService {
using namespace PhotoFlyBehaviours;

class ServiceMessage : public ISerializable
{

//    Q_DISABLE_COPY(ServiceMessage)
    Q_GADGET

public:
    static const QString LoginTypeString;
    static const QString UndefinedTypeString;

    enum class Type{
        Undefined,
        Login
    };
    Q_ENUM(Type)

    virtual ~ServiceMessage(){}

    virtual Type getType() const = 0;
    QString getTypeString() const;

    static QString getTypeString(Type value);
    static Type getTypeByString(const QString& value);


    // ISerializable interface
    virtual void getObjectInfo(PhotoFlyContainers::SerializationInfo &info) override;

protected:
    explicit ServiceMessage();

    static const QString TypeKey;

private:
    static QMap<QString, Type> m_typeByString;
    static QMap<Type, QString> m_stringByType;
    static void addPair(const QString& str, Type type);



};

}

#endif // SERVICEMESSAGE_H
