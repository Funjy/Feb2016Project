#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "registrationformdata.h"
#include "applicationsettings.h"
//#include <QtGui>
//#include <QtQuick>

#include <mainworker.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    app.setOrganizationName("Riftek IT");
    app.setOrganizationDomain("riftekit.ca");
    app.setApplicationName("PhotoFly");

    qmlRegisterType<RegistrationFormData>           ("com.riftekit.Containers", 1, 0, "RegistrationFormData");
    qmlRegisterType<MainWorker>                     ("com.riftekit.Workers",    1, 0, "MainWorker");
    qmlRegisterSingletonType<ApplicationSettings>   ("com.riftekit.Workers",    1, 0, "ApplicationSettings", ApplicationSettings_provider);

    appSettings.init();

//    // It's about iphone 5
//    qreal refDpi = 326.;
//    qreal refHeight = 1136.;
//    qreal refWidth = 640.;
//    QRect rect = app.primaryScreen()->geometry();
//    qreal height = qMax(rect.width(), rect.height());
//    qreal width = qMin(rect.width(), rect.height());
////    qreal dpi = app.primaryScreen()->logicalDotsPerInch();
//    qreal dpi = app.primaryScreen()->physicalDotsPerInch();
//    qreal m_ratio = qMin(height/refHeight, width/refWidth);
//    qreal m_ratioFont = qMin(height*refDpi/(dpi*refHeight), width*refDpi/(dpi*refWidth));

    QScopedPointer<MainWorker> mainWorker(new MainWorker());// *mainWorker(m_ratio, m_ratioFont);
    mainWorker->Init();

    QQmlApplicationEngine engine;
    QPM_INIT(engine)
    engine.rootContext()->setContextProperty("mainWorker", mainWorker.data());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


//    QQuickView view;
//    MainWorker *mainWorker = new MainWorker(&view);

//    view.engine()->rootContext()->setContextProperty(QLatin1String("notificationClient"),
//                                                     mainWorker);
//    view.setResizeMode(QQuickView::SizeRootObjectToView);
//    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
//    view.show();

    return app.exec();
}
