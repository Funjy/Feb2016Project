#ifndef PHOTOCONTAINER_H
#define PHOTOCONTAINER_H

#include <QObject>
#include <QImage>
#include <QUuid>

#include "behaviours/iserializable.h"

class PhotoContainer : public QObject, public PhotoFlyBehaviours::ISerializable
{
    Q_OBJECT

public:
    explicit PhotoContainer(QObject *parent = 0);
    PhotoContainer(const PhotoContainer& other);
//    PhotoContainer &operator= (const PhotoContainer& other);

    // ISerializable interface
public:
    void getObjectInfo(PhotoFlyContainers::SerializationInfo &info) override;

    QImage image() const;
    void image(const QImage &image);

    QString extension() const;
    void extension(const QString &extension);

    QString paperPhotoSize() const;
    void paperPhotoSize(const QString &paperPhotoSize);

    QString message() const;
    void message(const QString &message);

signals:

public slots:

private:
    QImage  m_image;
    QString m_extension;
    QString m_paperPhotoSize;
    QString m_message;

    // Not serializable
    QString m_imagePath;
    QString m_id;

};

#endif // PHOTOCONTAINER_H
