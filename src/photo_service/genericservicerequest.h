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

    static const QString TypeId;
public:
    static const QString ResultKey;

    enum class ResultStatus{
        Initialized,
        Ok,
        Fail
    };

    explicit GenericServiceRequest(QObject *parent = nullptr);
//    explicit GenericServiceRequest(ServiceMessageType type, QObject *parent = nullptr);
    using GenericServiceMessage::GenericServiceMessage;
    virtual ~GenericServiceRequest(){}

    // ISerializable interface
    virtual void getObjectInfo(PhotoFlyContainers::SerializationInfo &info) const override;

    ResultStatus getResultStatus() const;
    void setResultStatus(ResultStatus value);

//    QSharedPointer<ServiceMessage> getResult() const;
    const ServiceMessage *getResult() const;
    void setResult(ServiceMessage* result);

private:
    ResultStatus                    m_resultStatus;
    QSharedPointer<ServiceMessage>  m_result;


};

}

#endif // SERVICEREQUEST_H
