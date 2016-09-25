#ifndef SERVICEREQUEST_H
#define SERVICEREQUEST_H

#include <QtGlobal>

namespace PhotoFlyService {

class ServiceRequest{

    Q_DISABLE_COPY(ServiceRequest)

public:
    enum class Type{
        Login
    };
    enum class Result{
        Initialized,
        Ok,
        Fail
    };


    virtual ~ServiceRequest(){}

    virtual Type getType() const = 0;

    Result getResult() const;
    void setResult(Result value);

protected:
    explicit ServiceRequest();

private:
    Result  m_result;

};

}

#endif // SERVICEREQUEST_H
