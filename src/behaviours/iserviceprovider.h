#ifndef ISERVICEPROVIDER_H
#define ISERVICEPROVIDER_H

#include <QObject>

#include "photo_service/genericservicerequest.h"

namespace PhotoFlyBehaviours {

using namespace PhotoFlyService;

class IServiceProvider : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(IServiceProvider)

public:

    virtual void connectToHost(const QString &hostName, quint16 port) = 0;
    virtual void makeRequest(GenericServiceRequest *request, int timeout = 10000) = 0;
    virtual void beginMakeRequest(GenericServiceRequest *request) = 0;

    virtual QUrl getHostUrl() = 0;

protected:
    IServiceProvider(QObject *parent = nullptr) : QObject(parent) {}

signals:
    void requestComplete(GenericServiceRequest *request);

};

}

#endif // ISERVICEPROVIDER_H
