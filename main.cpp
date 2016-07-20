#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <registrationformdata.h>


//#include <QtGui>
//#include <QtQuick>

#include <mainworker.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<RegistrationFormData>("com.riftekit.RegistrationFormData", 1, 0, "RegistrationFormData");

    MainWorker mainWorker;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("mainWorker", &mainWorker);
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
