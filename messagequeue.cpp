#include "messagequeue.h"

QMutex* messageQueue::m_pMuxText = new (std::nothrow)QMutex;
QList<msg>* messageQueue::m_pMsgList = new (std::nothrow)QList<msg>;

int messageQueue::pushMessage(const msg &qMsg)
{
    QMutexLocker locker(m_pMuxText);
    m_pMsgList->push_back(qMsg);
    return 0;
}

int messageQueue::popMessage(msg& qMsg)
{
    QMutexLocker locker(m_pMuxText);
    if(!m_pMsgList->isEmpty())
    {
        qMsg = m_pMsgList->front();
        m_pMsgList->pop_front();
    }
    else
    {
        qMsg = msg();
    }

    return 0;
}
