#include "photocontainer.h"

PhotoContainer::PhotoContainer(QObject *parent) : QObject(parent)
{

}

PhotoContainer::PhotoContainer(const PhotoContainer &other) : PhotoContainer(other.parent())
{
}

//PhotoContainer &PhotoContainer::operator=(const PhotoContainer &other)
//{
//    this->PhotoContainer::PhotoContainer(other);
//    return *this;
//}

void PhotoContainer::getObjectInfo(PhotoFlyContainers::SerializationInfo &info)
{
    Q_UNUSED(info)
}

QImage PhotoContainer::image() const
{
    return m_image;
}

void PhotoContainer::image(const QImage &image)
{
    m_image = image;
}

QString PhotoContainer::extension() const
{
    return m_extension;
}

void PhotoContainer::extension(const QString &extension)
{
    m_extension = extension;
}

QString PhotoContainer::paperPhotoSize() const
{
    return m_paperPhotoSize;
}

void PhotoContainer::paperPhotoSize(const QString &paperPhotoSize)
{
    m_paperPhotoSize = paperPhotoSize;
}

QString PhotoContainer::message() const
{
    return m_message;
}

void PhotoContainer::message(const QString &message)
{
    m_message = message;
}
