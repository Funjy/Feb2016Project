#include "photocontainer.h"

using namespace PhotoFlyModels;

PhotoContainer::PhotoContainer(QObject *parent) : QObject(parent)
{

}

void PhotoContainer::getObjectInfo(PhotoFlyContainers::SerializationInfo &info) const
{
    Q_UNUSED(info)
}

QImage PhotoContainer::image() const
{
    return m_image;
}

void PhotoContainer::setImage(const QImage &image)
{
    m_image = image;
}

QString PhotoContainer::extension() const
{
    return m_extension;
}

void PhotoContainer::setExtension(const QString &extension)
{
    m_extension = extension;
}

QString PhotoContainer::paperPhotoSize() const
{
    return m_paperPhotoSize;
}

void PhotoContainer::setPpaperPhotoSize(const QString &paperPhotoSize)
{
    m_paperPhotoSize = paperPhotoSize;
}

QString PhotoContainer::message() const
{
    return m_message;
}

void PhotoContainer::setMessage(const QString &message)
{
    m_message = message;
}

QString PhotoContainer::imagePath() const
{
    return m_imagePath;
}

void PhotoContainer::setImagePath(const QString &imagePath)
{
    m_imagePath = imagePath;
    emit imagePathChanged();
}

QString PhotoContainer::title() const
{
    return m_title;
}

void PhotoContainer::setTitle(const QString &title)
{
    m_title = title;
    emit titleChanged();
}
