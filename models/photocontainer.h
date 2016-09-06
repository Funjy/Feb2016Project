#ifndef PHOTOCONTAINER_H
#define PHOTOCONTAINER_H

#include <QObject>
#include <QImage>

#include "behaviours/iserializable.h"

class PhotoContainer : public QObject, public PhotoFlyBehaviours::ISerializable
{
    Q_OBJECT

public:
    explicit PhotoContainer(QObject *parent = 0);

    // ISerializable interface
public:
    void getObjectInfo(PhotoFlyContainers::SerializationInfo &info);

signals:

public slots:

private:
    QImage  m_image;
    QString m_extension;

};

#endif // PHOTOCONTAINER_H
