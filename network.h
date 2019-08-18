#ifndef NETWORK_H
#define NETWORK_H
#include <QAbstractSocket>
#include <QWebSocket>
#include <QObject>
#include <QThread>
#include <QRunnable>


enum networkStatus
{
    connected,
    unconnected
};

//网络模块，实现为静态类
class network : public QObject
{
    Q_OBJECT
public:
    //static network* getInstance();
    void init();
    int connect();
    void disconect();
    int reconnect();
    int sendTextNessage(const QString& qText);
    int receiveTextMessage();
public Q_SLOTS:
    void onConnect();
    void onDisConnect();
    Q_SIGNALS:
    void connectedSignal();
    void unconnectedSignal();
public:
    network() : m_enStatus(unconnected){}
    ~network(){}
private:
    QWebSocket m_webSocket;
    networkStatus m_enStatus;
};


class netWorkTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    netWorkTask(){}
    ~netWorkTask(){}
public:
    void run();
};
#endif // NETWORK_H
