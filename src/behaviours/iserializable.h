#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include "../containers/serializationinfo.h"

namespace PhotoFlyBehaviours {
using namespace PhotoFlyContainers;

class ISerializable
{
public:    
    virtual void getObjectInfo(SerializationInfo &info) const = 0;
    virtual void deserialize(const SerializationInfo& info) { Q_UNUSED(info) }

//    virtual void deserialize(PhotoFlyContainers::SerializationInfo &info) = 0;
};

}

#endif // ISERIALIZABLE_H
