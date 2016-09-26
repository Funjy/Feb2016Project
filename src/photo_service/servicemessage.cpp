#include "servicemessage.h"

using namespace PhotoFlyService;

const QString ServiceMessage::TypeKey = "MessageType";

void ServiceMessage::getObjectInfo(PhotoFlyContainers::SerializationInfo &info)
{
    info.addValue(TypeKey, (int)getType());
}
