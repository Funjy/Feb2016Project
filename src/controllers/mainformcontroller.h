#ifndef MAINFORMCONTROLLER_H
#define MAINFORMCONTROLLER_H

#include <QObject>
#include <QQmlListProperty>
#include <QDebug>
#include <QFileInfo>

#include "models/photocontainer.h"
#include "behaviours/iimagegalleryprovider.h"
#include "photo_service/serviceprovider.h"
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

public:
    explicit MainFormController(QObject *parent = 0);
    ~MainFormController();

    QQmlListProperty<PhotoContainer> photos();

    // Photo selection
    Q_INVOKABLE void openCamera() const;
    Q_INVOKABLE void morePhotos();
    Q_INVOKABLE void removePhoto(int idx);

    // Message options
    Q_INVOKABLE void sendRequested(QVariant data2send);

signals:
    void photosChanged();

public slots:

private slots:
    void onNewImagesSelected(QStringList imagesList);
    void onRequestComplete(GenericServiceRequest *request);

private:
    IImageGalleryProvider   *m_galleryProvider;
    IServiceProvider        *m_serviceProvider;
    QList<GenericServiceRequest*>   m_requestedPhotos;

    PhotosList  m_photos;
    static int photosCount(QQmlListProperty<PhotoContainer> *list);
    static PhotoContainer *photoItem(QQmlListProperty<PhotoContainer> *list, int i);

    void imagePickerFactory(IImageGalleryProvider *&picker);

};

}

Q_DECLARE_METATYPE(PhotoFlyControllers::MainFormController*)
Q_DECLARE_METATYPE(QQmlListProperty<PhotoFlyModels::PhotoContainer>)

#endif // MAINFORMCONTROLLER_H
