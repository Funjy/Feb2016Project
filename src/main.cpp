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
//#include <QtGui>
//#include <QtQuick>

#include "core/mainworker.h"

const char* pf_workers_uri = "ca.riftekit.Workers";
const char* pf_containers_uri = "ca.riftekit.Containers";
const char* pf_containers_pfServices = "ca.riftekit.PhotoFlyServices";

int main(int argc, char *argv[])
{
    QGuiApplication::setOrganizationName("Riftek IT");
    QGuiApplication::setOrganizationDomain("riftekit.ca");
    QGuiApplication::setApplicationName("PhotoFly");
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

//    qRegisterMetaType<ServiceMessageType>();
    qmlRegisterType<RegistrationFormData>           (pf_containers_uri, 1, 0, "RegistrationFormData");
    qmlRegisterType<MainWorker>                     (pf_workers_uri,    1, 0, "MainWorker");
    qmlRegisterSingletonType<PhotoFlySettings::ApplicationSettings>
            (pf_workers_uri,    1, 0, "ApplicationSettings", PhotoFlySettings::ApplicationSettings_provider);

    qmlRegisterSingletonType<PhotoFlyService::ServiceRequestFactory>
            (pf_containers_pfServices,    1, 0, "PFServiceRequestFactory", PhotoFlyService::ServiceRequestFactory_provider);
    qmlRegisterType<PhotoFlyService::GenericServiceMessage>(pf_containers_pfServices,    1, 0, "ServiceMessage");

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    QPM_INIT(engine)

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
