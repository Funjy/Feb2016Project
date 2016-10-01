#ifndef ISERVICEPROVIDER_H
#define ISERVICEPROVIDER_H

#include "../photo_service/genericservicerequest.h"

namespace PhotoFlyBehaviours {

using namespace PhotoFlyService;

class IServiceProvider{
public:

    virtual void makeRequest(const ServiceRequest *request) = 0;

};

}

#endif // ISERVICEPROVIDER_H
