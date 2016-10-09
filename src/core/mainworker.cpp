#include "mainworker.h"

MainWorker::MainWorker(QObject *parent) : QObject(parent){

    m_userInfo = new RegistrationFormData(this);
    updateUserInfo();

//    m_imPicker = nullptr;
//    connect(m_imPicker, &IImageGalleryProvider::imagesSelected, this, &MainWorker::onImagesSelected);
//    emit setMessage("Ready");

//    m_regFormController = new RegistrationFormController(this);
//    emit regFormControllerChanged();

    m_mainFormController = new MainFormController(this);

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

bool MainWorker::isRegistered() const
{
    return m_userInfo->isValid();
}

void MainWorker::updateUserInfo()
{
    appSettings.readUserInfo(m_userInfo);
    emit isRegisteredChanged();
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
