#ifndef PHOTOCONTAINER_H
#define PHOTOCONTAINER_H

#include <QObject>
#include <QImage>

class PhotoContainer : public QObject
{
    Q_OBJECT

public:
    explicit PhotoContainer(QObject *parent = 0);

signals:

public slots:

private:
    QImage  m_image;
    QString m_extension;
};

#endif // PHOTOCONTAINER_H
