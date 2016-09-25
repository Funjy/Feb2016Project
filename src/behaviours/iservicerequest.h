#ifndef ISERVICEREQUEST_H
#define ISERVICEREQUEST_H

namespace PhotoFlyBehaviours {

class IServiceRequest{
public:
    enum class Type{
        Login
    };
    enum class Result{
        Ok,
        Fail
    };

    explicit IServiceRequest() {}
    ~IServiceRequest(){}

};

}

#endif // ISERVICEREQUEST_H