#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QVariantMap>
#include <QDebug>
#include <QQuickStyle>

#include "models/registrationformdata.h"
#include "core/applicationsettings.h"
#include "photo_service/servicerequestfactory.h"
#include "photo_service/genericservicemessage.h"
#include "controllers/registrationformcontroller.h"
#include "controllers/mainformcontroller.h"
#include "behaviours/iimagegalleryprovider.h"
//#include <QtGui>
//#include <QtQuick>

#include "core/mainworker.h"

//const char* pf_workers_uri = "ca.riftekit.Workers";
//const char* pf_containers_uri = "ca.riftekit.Containers";
//const char* pf_containers_pfServices = "ca.riftekit.PhotoFlyServices";

inline void registerTypes();

int main(int argc, char *argv[])
{
    QGuiApplication::setOrganizationName("Riftek IT");
    QGuiApplication::setOrganizationDomain("riftekit.ca");
    QGuiApplication::setApplicationName("PhotoFly");
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    registerTypes();

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
//    QPM_INIT(engine)

    appSettings.init();

    auto mainWorker = new MainWorker(&engine);
//    QScopedPointer<MainWorker> mainWorker(new MainWorker());
    mainWorker->Init();

    engine.rootContext()->setContextProperty("mainWorker", mainWorker);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));


//    QQuickView view;
//    MainWorker *mainWorker = new MainWorker(&view);

//    view.engine()->rootContext()->setContextProperty(QLatin1String("notificationClient"),
//                                                     mainWorker);
//    view.setResizeMode(QQuickView::SizeRootObjectToView);
//    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
//    view.show();


    return app.exec();
}

inline void registerTypes(){
    //    qRegisterMetaType<ServiceMessageType>();
    // Containers
    qmlRegisterType<RegistrationFormData>
            ("ca.riftekit.Containers", 1, 0, "RegistrationFormData");

    // Workers
    qmlRegisterType<MainWorker>
            ("ca.riftekit.Workers",    1, 0, "MainWorker");
    qmlRegisterSingletonType<PhotoFlySettings::ApplicationSettings>
            ("ca.riftekit.Workers",    1, 0, "ApplicationSettings", PhotoFlySettings::ApplicationSettings_provider);

    // Services
    qmlRegisterSingletonType<PhotoFlyService::ServiceRequestFactory>
            ("ca.riftekit.PhotoFlyServices",    1, 0, "PFServiceRequestFactory", PhotoFlyService::ServiceRequestFactory_provider);
    qmlRegisterType<PhotoFlyService::GenericServiceMessage>
            ("ca.riftekit.PhotoFlyServices",    1, 0, "ServiceMessage");


    qRegisterMetaType<QQmlListProperty<PhotoFlyModels::PhotoContainer>>();
    qRegisterMetaType<GenericServiceRequest *>("GenericServiceRequest *");

    qmlRegisterType<PhotoFlyModels::PhotoContainer>
            ("ca.riftekit.models", 1, 0, "PhotoContainer");

    // Controllers
//    qmlRegisterUncreatableType<PhotoFlyControllers::RegistrationFormController>
//            ("ca.riftekit.Controllers", 1, 0, "RegistrationFormController", "Reg controller creation attempt!");
    qmlRegisterType<RegistrationFormController>
            ("ca.riftekit.Controllers", 1, 0, "RegistrationFormController");

    qmlRegisterUncreatableType<PhotoFlyControllers::MainFormController>
            ("ca.riftekit.Controllers", 1, 0, "MainFormController", "MainFormController");

    // Behaviours
//    qmlRegisterUncreatableType<PhotoFlyBehaviours::IImageGalleryProvider>
//            ("ca.riftekit.Behaviours", 1, 0, "IImageGalleryProvider", "IImageGalleryProvider");

    qmlRegisterInterface<PhotoFlyBehaviours::IImageGalleryProvider>
            ("IImageGalleryProvider");
}
