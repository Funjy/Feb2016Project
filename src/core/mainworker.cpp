#include "mainworker.h"

MainWorker::MainWorker(QObject *parent) : QObject(parent){

//    connect(&m_imPicker, &ImagePickerAndroid::imageSelected, this, &MainWorker::onImageSelected);
    connect(&m_imPicker, &ImagePickerAndroid::imagesSelected, this, &MainWorker::onImagesSelected);
    emit setMessage("Ready");
}

void MainWorker::selectImageFromGallery()
{
    emit setMessage("Open clicked");

    m_imPicker.openGallery();

}

void MainWorker::openCamera()
{
    m_imPicker.openCamera();
}

void MainWorker::testFunc(RegistrationFormData* data)
{
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
