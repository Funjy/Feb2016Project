#ifndef SERVICEREQUEST_H
#define SERVICEREQUEST_H

#include <QSharedPointer>
#include <QObject>

//#include "servicemessage.h"
#include "genericservicemessage.h"

namespace PhotoFlyService {

class ServiceRequest : public GenericServiceMessage
{
    Q_OBJECT
    Q_DISABLE_COPY(ServiceRequest)

public:
    enum class ResultStatus{
        Initialized,
        Ok,
        Fail
    };

    explicit ServiceRequest(QObject *parent = nullptr);
    explicit ServiceRequest(ServiceMessageType type, QObject *parent = nullptr);
    virtual ~ServiceRequest(){}

    ResultStatus getResultStatus() const;
    void setResultStatus(ResultStatus value);

//    QSharedPointer<ServiceMessage> getResult() const;
    const ServiceMessage * const getResult();

private:
    ResultStatus                    m_resultStatus;
    QSharedPointer<ServiceMessage>  m_result;

};

}

#endif // SERVICEREQUEST_H
