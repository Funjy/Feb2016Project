#include "photocontainer.h"

PhotoContainer::PhotoContainer(QObject *parent) : QObject(parent)
{

}

void PhotoContainer::getObjectInfo(PhotoFlyContainers::SerializationInfo &info)
{
    Q_UNUSED(info)
}
