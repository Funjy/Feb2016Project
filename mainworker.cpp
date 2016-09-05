#include "mainworker.h"

MainWorker::MainWorker(QObject *parent) : QObject(parent){
    connect(&m_imPicker, &ImagePickerAndroid::imageSelected, this, &MainWorker::onImageSelected);
    emit setMessage("Ready");
}

void MainWorker::selectImageFromGallery()
{
    emit setMessage("Open clicked");

    m_imPicker.openGallery();

}

void MainWorker::testFunc(RegistrationFormData* data)
{
}

void MainWorker::Init()
{

}

void MainWorker::onImageSelected(QString imagePath)
{
    emit setMessage(imagePath);
}
