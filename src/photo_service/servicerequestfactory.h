#ifndef SERVICEREQUESTFACTORY_H
#define SERVICEREQUESTFACTORY_H

#include <QObject>
#include <QQmlEngine>

#include "genericservicerequest.h"
#include "loginrequest.h"
#include "genericservicemessage.h"\

#define requestFactory ServiceRequestFactory::instance()

namespace PhotoFlyService {

class ServiceRequestFactory : public QObject
{
    Q_OBJECT

public:

    static ServiceRequestFactory &instance();
    void init();

    GenericServiceRequest* buildRequest(GenericServiceRequest::RequestType type);

    Q_INVOKABLE GenericServiceRequest* buildRequest(const QString& type, const QVariantMap& content);

signals:

public slots:

private:
    explicit ServiceRequestFactory(QObject *parent = 0);
    ServiceRequestFactory(const ServiceRequestFactory &) { }
    ServiceRequestFactory &operator=(const ServiceRequestFactory &) { return *this; }
};

static QObject *ServiceRequestFactory_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return &requestFactory;
}

}

#endif // SERVICEREQUESTFACTORY_H
