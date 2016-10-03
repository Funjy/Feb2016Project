#include "mainworker.h"

MainWorker::MainWorker(QObject *parent) : QObject(parent){

    m_imPicker = nullptr;
    connect(m_imPicker, &IImageGalleryProvider::imagesSelected, this, &MainWorker::onImagesSelected);
//    emit setMessage("Ready");

    m_regFormController = new RegistrationFormController(this);
//    emit regFormControllerChanged();

}

void MainWorker::selectImageFromGallery()
{
    emit setMessage("Open clicked");

    m_imPicker->openGallery();

}

void MainWorker::openCamera()
{
//    m_imPicker.openCamera();
}

void MainWorker::testFunc(RegistrationFormData* data)
{

    auto provider = new ServiceProvider(this);

    provider->testRequest();

    provider->deleteLater();

}

void MainWorker::Init()
{

}

void MainWorker::onImagesSelected(QStringList imagePaths)
{
    qDebug() << "images: ";
    foreach(QString path, imagePaths){
        qDebug() << "path: " << path;
    }
}

//void MainWorker::onImageSelected(QString imagePath)
//{
//    emit setMessage(imagePath);
//}
