#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreen>

#include <registrationformdata.h>


//#include <QtGui>
//#include <QtQuick>

#include <mainworker.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qreal refDpi = 326.; // this comment
    qreal refHeight = 1136.;
    qreal refWidth = 640.;
    QRect rect = app.primaryScreen()->geometry();
    qreal height = qMax(rect.width(), rect.height());
    qreal width = qMin(rect.width(), rect.height());
//    qreal dpi = app.primaryScreen()->logicalDotsPerInch();
    qreal dpi = app.primaryScreen()->physicalDotsPerInch();
    qreal m_ratio = qMin(height/refHeight, width/refWidth);
    qreal m_ratioFont = qMin(height*refDpi/(dpi*refHeight), width*refDpi/(dpi*refWidth));

    qmlRegisterType<RegistrationFormData>   ("com.riftekit.Containers", 1, 0, "RegistrationFormData");
    qmlRegisterType<MainWorker>             ("com.riftekit.Workers",    1, 0, "MainWorker");

    MainWorker mainWorker(m_ratio, m_ratioFont);
//    MainWorker mainWorker;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("mainWorker", &mainWorker);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    mainWorker.Init();

//    QQuickView view;
//    MainWorker *mainWorker = new MainWorker(&view);

//    view.engine()->rootContext()->setContextProperty(QLatin1String("notificationClient"),
//                                                     mainWorker);
//    view.setResizeMode(QQuickView::SizeRootObjectToView);
//    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
//    view.show();

    return app.exec();
}
