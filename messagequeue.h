#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H
#include <QString>
#include <QMutex>
#include <QMutexLocker>
#include <QList>


enum msgType
{
    noneMsg = 0,
    sendMsg ,
    receiveMsg
};

struct msg
{
    msgType m_enMsgType;
    QString m_qContext;
    QString m_qMsgId;
    msg() : m_enMsgType(noneMsg) , m_qContext("") , m_qMsgId("")
    {}
    msg(msgType enMsgType,QString& qMsg) : m_enMsgType(enMsgType) , m_qContext(qMsg) ,m_qMsgId("")
    {
    }

    void clear()
    {
        m_enMsgType = noneMsg;
        m_qContext.clear();
    }

    bool isEmpty()
    {
        if(m_enMsgType == noneMsg || m_qContext.isEmpty())
        {
            return true;
        }
        return false;
    }
};

//消息队列
class messageQueue
{
private:
    messageQueue(){}
    ~messageQueue(){}
public:
    static int pushMessage(const msg& qMsg);
    static int popMessage(msg& qMsg);
private:
    static QMutex* m_pMuxText;
    static QList<msg>* m_pMsgList;
};

#endif // MESSAGEQUEUE_H
