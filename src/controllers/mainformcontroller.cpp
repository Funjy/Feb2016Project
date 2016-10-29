#include "mainformcontroller.h"

using namespace PhotoFlyControllers;

MainFormController::MainFormController(QObject *parent) : QObject(parent)
{
#ifndef __ANDROID__
    auto pc = new PhotoContainer(this);
    pc->setImagePath("file:/C:/Users/Antony/Pictures/fOq9QNU.jpg");
    pc->setTitle("Halo");
    m_photos << pc;

    pc = new PhotoContainer(this);
    pc->setImagePath("file:/C:/Users/Antony/Pictures/temporal_flux_wallpaper_version_by_magicnaanavi-d671cua.jpg");
//    pc->setTitle("file:/C:/Users/Antony/Pictures/temporal_flux_wallpaper_version_by_magicnaanavi-d671cua.jpg");

    QFileInfo f(pc->imagePath());
    pc->setTitle(f.baseName());

    m_photos << pc;

    emit photosChanged();
#endif

    m_galleryProvider = nullptr;
    m_serviceProvider = nullptr;
    imagePickerFactory(m_galleryProvider);

}

MainFormController::~MainFormController()
{
    for(auto photoCont : m_photos)
        photoCont->deleteLater();
}

QQmlListProperty<PhotoContainer> MainFormController::photos()
{
    return QQmlListProperty<PhotoContainer>(
                this,
                &m_photos,
                &MainFormController::photosCount,
                &MainFormController::photoItem);
}

void MainFormController::openCamera() const
{
    if (!m_galleryProvider)
        return;

    m_galleryProvider->openCamera();

}

void MainFormController::morePhotos()
{
    if (!m_galleryProvider)
        return;
    m_galleryProvider->openGallery();
}

void MainFormController::removePhoto(int idx)
{
    if (idx >= m_photos.count())
        return;
    m_photos.takeAt(idx)->deleteLater();
    emit photosChanged();
}

void MainFormController::sendRequested(QVariant data2send)
{
    if (!m_serviceProvider)
        m_serviceProvider = new ServiceProvider(this);
    connect(m_serviceProvider, &IServiceProvider::requestComplete, this, &MainFormController::onRequestComplete);

    auto req = new GenericServiceRequest(this);
    req->setMessageType(ServiceMessageType::Req_SendPhotos);
    req->setContent(data2send.toMap());
    m_serviceProvider->beginMakeRequest(req);

    m_requestedPhotos << req;

}

void MainFormController::onNewImagesSelected(QStringList imagesList)
{
    for (auto imPath : imagesList) {
        qDebug() << "imPath: " << imPath;
        QFileInfo f(imPath);
        auto pc = new PhotoContainer(this);
        pc->setImagePath("file:/" + imPath);
        pc->setTitle(f.baseName());
        m_photos << pc;
    }
    emit photosChanged();
}

void MainFormController::onRequestComplete(GenericServiceRequest *request)
{
    qDebug() << "req res: " << request->getResultStatus() << " | " << request->getErrorString();
}

int MainFormController::photosCount(QQmlListProperty<PhotoContainer> *list)
{
    auto photos = static_cast<PhotosList*>(list->data);
    return photos->count();
}

PhotoContainer *MainFormController::photoItem(QQmlListProperty<PhotoContainer> *list, int i)
{
    auto photos = static_cast<PhotosList*>(list->data);
    return photos->at(i);
}

void MainFormController::imagePickerFactory(IImageGalleryProvider *&picker)
{
#ifdef __ANDROID__
    picker = new ImagePickerAndroid(this);
#elif __WIN32__
    picker = nullptr;
    return;
#endif

    connect(picker, &IImageGalleryProvider::imagesSelected, this, &MainFormController::onNewImagesSelected);
}
