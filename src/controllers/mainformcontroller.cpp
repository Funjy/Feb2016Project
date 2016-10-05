#include "mainformcontroller.h"

using namespace PhotoFlyControllers;

MainFormController::MainFormController(QObject *parent) : QObject(parent)
{
    auto pc = new PhotoContainer(this);
    pc->setImagePath("file:/C:/Users/Antony/Pictures/fOq9QNU.jpg");
    pc->setTitle("Halo");
    m_photos << pc;

    pc = new PhotoContainer(this);
    pc->setImagePath("file:/C:/Users/Antony/Pictures/temporal_flux_wallpaper_version_by_magicnaanavi-d671cua.jpg");
    pc->setTitle("file:/C:/Users/Antony/Pictures/temporal_flux_wallpaper_version_by_magicnaanavi-d671cua.jpg");
    m_photos << pc;

    emit photosChanged();
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
