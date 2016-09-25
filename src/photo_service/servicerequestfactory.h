#ifndef SERVICEREQUESTFACTORY_H
#define SERVICEREQUESTFACTORY_H

#include <QObject>

#include "servicerequest.h"
#include "loginrequest.h"

namespace PhotoFlyService {

class ServiceRequestFactory : public QObject
{
    Q_OBJECT

public:

    static ServiceRequestFactory *Get();

    ServiceRequest* buildRequest(ServiceRequest::Type type);

signals:

public slots:
private:
    explicit ServiceRequestFactory(QObject *parent = 0);
    ServiceRequestFactory(const ServiceRequestFactory &) { }
    ServiceRequestFactory &operator=(const ServiceRequestFactory &) { return *this; }
};

}

#endif // SERVICEREQUESTFACTORY_H
