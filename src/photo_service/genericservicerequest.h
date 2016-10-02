#ifndef SERVICEREQUEST_H
#define SERVICEREQUEST_H

#include <QSharedPointer>
#include <QObject>

//#include "servicemessage.h"
#include "genericservicemessage.h"

#define RequestResultStatus PhotoFlyService::GenericServiceRequest::ResultStatus

namespace PhotoFlyService {
using namespace PhotoFlyContainers;


class GenericServiceRequest : public GenericServiceMessage
{
    Q_OBJECT
    Q_DISABLE_COPY(GenericServiceRequest)

    static const QString TypeId;
public:
    static const QString ResultKey;
    static const QString ResultStatusKey;

    enum class ResultStatus{
        Initialized,
        Ok,
        Fail
    };
    Q_ENUM(ResultStatus)

    explicit GenericServiceRequest(QObject *parent = nullptr);
//    explicit GenericServiceRequest(ServiceMessageType type, QObject *parent = nullptr);
    using GenericServiceMessage::GenericServiceMessage;
    virtual ~GenericServiceRequest(){}

    // ISerializable interface
    virtual void getObjectInfo(SerializationInfo &info) const override;
    virtual void deserialize(const SerializationInfo &info) Q_DECL_OVERRIDE;

    ResultStatus getResultStatus() const;
    void setResultStatus(ResultStatus value);

//    QSharedPointer<ServiceMessage> getResult() const;
    const ServiceMessage *getResult() const;
    void setResult(ServiceMessage* result);
    void setResult(const QVariantMap& result);

private:
    ResultStatus                    m_resultStatus;
    QSharedPointer<ServiceMessage>  m_result;

};

}

#endif // SERVICEREQUEST_H
