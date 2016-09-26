#ifndef SERVICEREQUEST_H
#define SERVICEREQUEST_H

#include <QSharedPointer>
#include <QObject>

#include "servicemessage.h"

namespace PhotoFlyService {

class ServiceRequest : public QObject, public ServiceMessage
{
    Q_OBJECT
    Q_DISABLE_COPY(ServiceRequest)

public:
    enum class ResultStatus{
        Initialized,
        Ok,
        Fail
    };

    virtual ~ServiceRequest(){}

    ResultStatus getResultStatus() const;
    void setResultStatus(ResultStatus value);

    QSharedPointer<ServiceMessage> getResult() const;

protected:
    explicit ServiceRequest(QObject *parent = nullptr);

private:
    ResultStatus    m_resultStatus;
    QSharedPointer<ServiceMessage>  m_result;

};

}

#endif // SERVICEREQUEST_H
