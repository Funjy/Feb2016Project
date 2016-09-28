#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QVariantMap>
#include <QDebug>

#include "models/registrationformdata.h"
#include "core/applicationsettings.h"
#include "photo_service/servicerequestfactory.h"
#include "photo_service/genericservicemessage.h"
//#include <QtGui>
//#include <QtQuick>

#include "core/mainworker.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    app.setOrganizationName("Riftek IT");
    app.setOrganizationDomain("riftekit.ca");
    app.setApplicationName("PhotoFly");

//    qRegisterMetaType<ServiceMessageType>();
    qmlRegisterType<RegistrationFormData>           ("com.riftekit.Containers", 1, 0, "RegistrationFormData");
    qmlRegisterType<MainWorker>                     ("com.riftekit.Workers",    1, 0, "MainWorker");
    qmlRegisterSingletonType<ApplicationSettings>   ("com.riftekit.Workers",    1, 0, "ApplicationSettings", ApplicationSettings_provider);

    qmlRegisterSingletonType<PhotoFlyService::ServiceRequestFactory>
            ("com.riftekit.PhotoFlyService",    1, 0, "ApplicationSettings", PhotoFlyService::ServiceRequestFactory_provider);

    PhotoFlyService::GenericServiceMessage m1, m2;

    m2.setType(ServiceMessageType::Login);
    QVariantMap map;
    map.insert("key1", "value1");
    map.insert("key2", 0.0350);
    m2.setContent(map);

    qDebug() << "main 1";

    m1 = m2;

    qDebug() << "m1: " << m1.getContent().keys();
    qDebug() << "m2: " << m2.getContent().keys();

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
