#ifndef SERVICEREQUEST_H
#define SERVICEREQUEST_H

#include <QSharedPointer>
#include <QObject>

//#include "servicemessage.h"
#include "genericservicemessage.h"

namespace PhotoFlyService {

class GenericServiceRequest : public GenericServiceMessage
{
    Q_OBJECT
    Q_DISABLE_COPY(GenericServiceRequest)

public:
    enum class ResultStatus{
        Initialized,
        Ok,
        Fail
    };

    explicit GenericServiceRequest(QObject *parent = nullptr);
    explicit GenericServiceRequest(ServiceMessageType type, QObject *parent = nullptr);
    virtual ~GenericServiceRequest(){}

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
