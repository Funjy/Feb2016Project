#ifndef SERVICEMESSAGE_H
#define SERVICEMESSAGE_H

#include <QtGlobal>

#include "../behaviours/iserializable.h"

namespace PhotoFlyService {
using namespace PhotoFlyBehaviours;

class ServiceMessage : public ISerializable
{

    Q_DISABLE_COPY(ServiceMessage)

public:
    enum class Type{
        Login
    };

    virtual ~ServiceMessage(){}

    virtual Type getType() const = 0;

    // ISerializable interface
    virtual void getObjectInfo(PhotoFlyContainers::SerializationInfo &info) override;

protected:
    explicit ServiceMessage(){}

    static const QString TypeKey;


};

}

#endif // SERVICEMESSAGE_H
