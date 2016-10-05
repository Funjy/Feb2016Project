#ifndef PHOTOCONTAINER_H
#define PHOTOCONTAINER_H

#include <QObject>
#include <QImage>
#include <QUuid>

#include "behaviours/iserializable.h"

namespace PhotoFlyModels{

class PhotoContainer : public QObject, public PhotoFlyBehaviours::ISerializable
{
    Q_OBJECT
//    Q_DISABLE_COPY(PhotoContainer)
    Q_PROPERTY(QImage image READ image WRITE setImage NOTIFY imageChanged)
    Q_PROPERTY(QString imagePath READ imagePath WRITE setImagePath NOTIFY imagePathChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)

public:
    explicit PhotoContainer(QObject *parent = 0);

    // ISerializable interface
    void getObjectInfo(PhotoFlyContainers::SerializationInfo &info) const override;

    QImage image() const;
    void setImage(const QImage &image);

    QString extension() const;
    void setExtension(const QString &extension);

    QString paperPhotoSize() const;
    void setPpaperPhotoSize(const QString &paperPhotoSize);

    QString message() const;
    void setMessage(const QString &message);

    QString imagePath() const;
    void setImagePath(const QString &imagePath);

    QString title() const;
    void setTitle(const QString &title);

signals:
    void imageChanged();
    void imagePathChanged();
    void titleChanged();

public slots:

private:
    QString m_title;
    QImage  m_image;
    QString m_extension;
    QString m_paperPhotoSize;
    QString m_message;

    // Not serializable
    QString m_imagePath;
    QString m_id;

};

typedef QList<PhotoContainer*> PhotosList;
//class PhotosList : public QList<PhotoContainer*> {};

}
Q_DECLARE_METATYPE(PhotoFlyModels::PhotoContainer*)
Q_DECLARE_METATYPE(PhotoFlyModels::PhotosList)

#endif // PHOTOCONTAINER_H
