#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include "../containers/serializationinfo.h"

namespace PhotoFlyBehaviours {

class ISerializable
{
public:
    virtual void getObjectInfo(PhotoFlyContainers::SerializationInfo &info) = 0;
};

}

#endif // ISERIALIZABLE_H
