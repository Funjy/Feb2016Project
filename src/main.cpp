#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "models/registrationformdata.h"
#include "core/applicationsettings.h"
#include "photo_service/servicerequestfactory.h"
//#include <QtGui>
//#include <QtQuick>

#include "core/mainworker.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    app.setOrganizationName("Riftek IT");
    app.setOrganizationDomain("riftekit.ca");
    app.setApplicationName("PhotoFly");

    qmlRegisterType<RegistrationFormData>           ("com.riftekit.Containers", 1, 0, "RegistrationFormData");
    qmlRegisterType<MainWorker>                     ("com.riftekit.Workers",    1, 0, "MainWorker");
    qmlRegisterSingletonType<ApplicationSettings>   ("com.riftekit.Workers",    1, 0, "ApplicationSettings", ApplicationSettings_provider);

    qmlRegisterSingletonType<PhotoFlyService::ServiceRequestFactory>
            ("com.riftekit.PhotoFlyService",    1, 0, "ApplicationSettings", PhotoFlyService::ServiceRequestFactory_provider);

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
