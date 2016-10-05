#ifndef MAINFORMCONTROLLER_H
#define MAINFORMCONTROLLER_H

#include <QObject>
#include <QQmlListProperty>

#include "models/photocontainer.h"

namespace PhotoFlyControllers{
using namespace PhotoFlyModels;

class MainFormController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(MainFormController)

    Q_PROPERTY(QQmlListProperty<PhotoFlyModels::PhotoContainer> photos READ photos NOTIFY photosChanged)

public:
    explicit MainFormController(QObject *parent = 0);
    ~MainFormController();

    QQmlListProperty<PhotoContainer> photos();

signals:
    void photosChanged();

public slots:

private:
    PhotosList  m_photos;
    static int photosCount(QQmlListProperty<PhotoContainer> *list);
    static PhotoContainer *photoItem(QQmlListProperty<PhotoContainer> *list, int i);

};

}

Q_DECLARE_METATYPE(PhotoFlyControllers::MainFormController*)
Q_DECLARE_METATYPE(QQmlListProperty<PhotoFlyModels::PhotoContainer>)

#endif // MAINFORMCONTROLLER_H
