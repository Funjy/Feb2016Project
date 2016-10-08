#ifndef MAINFORMCONTROLLER_H
#define MAINFORMCONTROLLER_H

#include <QObject>
#include <QQmlListProperty>
#include <QDebug>

#include "models/photocontainer.h"
#include "behaviours/iimagegalleryprovider.h"
#ifdef __ANDROID__
//#include <QtAndroidExtras>
#include <QAndroidJniObject>
#include <QtAndroid>
#include "core/imagepickerandroid.h"
//#include "paymentandroid.h"
#endif

namespace PhotoFlyControllers{
using namespace PhotoFlyModels;
using namespace PhotoFlyBehaviours;

class MainFormController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(MainFormController)

    Q_PROPERTY(QQmlListProperty<PhotoFlyModels::PhotoContainer> photos READ photos NOTIFY photosChanged)
    Q_PROPERTY(IImageGalleryProvider* imagesProvider READ imagesProvider CONSTANT)

public:
    explicit MainFormController(QObject *parent = 0);
    ~MainFormController();

    QQmlListProperty<PhotoContainer> photos();
    IImageGalleryProvider *imagesProvider() const;

    Q_INVOKABLE void morePhotos();

signals:
    void photosChanged();

public slots:

private slots:
    void onNewImagesSelected(QStringList imagesList);

private:
    IImageGalleryProvider *m_galleryProvider;

    PhotosList  m_photos;
    static int photosCount(QQmlListProperty<PhotoContainer> *list);
    static PhotoContainer *photoItem(QQmlListProperty<PhotoContainer> *list, int i);

    void imagePickerFactory(IImageGalleryProvider *&picker);

};

}

Q_DECLARE_METATYPE(PhotoFlyControllers::MainFormController*)
Q_DECLARE_METATYPE(QQmlListProperty<PhotoFlyModels::PhotoContainer>)

#endif // MAINFORMCONTROLLER_H
