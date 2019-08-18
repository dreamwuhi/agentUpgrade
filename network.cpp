#include "network.h"
#include "messagequeue.h"

//network *network::getInstance()
//{
//    static network inst;
//    return &inst;
//}

void network::init()
{
    QObject::connect(&m_webSocket,&QWebSocket::connected,this,&network::onConnect);
    QObject::connect(&m_webSocket,&QWebSocket::disconnected,this,&network::onDisConnect);
}

int network::sendTextNessage(const QString& qText)
{
    int iRet = 0;
    return iRet;
}

void network::onConnect()
{
    //网络建立成功
    m_enStatus = connected;
    emit connectedSignal();
}

void network::onDisConnect()
{
    m_enStatus = unconnected;
    emit unconnectedSignal();
}

void netWorkTask::run()
{
    msg qMsg;
    while (true)
    {

         qMsg.clear();
         messageQueue::popMessage(qMsg);
         if(qMsg.isEmpty())
         {
             QThread::msleep(500);
             continue;
         }

         if(qMsg.m_enMsgType == sendMsg)
         {
             //if(0 != network::getInstance()->sendTextNessage(qMsg.m_qContext))
             {
                 //发送失败，重新插入缓存队列
                 messageQueue::pushMessage(qMsg);
             }
         }

         QThread::msleep(500);
    }
}
