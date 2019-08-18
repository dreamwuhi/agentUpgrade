#ifndef CLIENT_H
#define CLIENT_H
#include "network.h"

class client : public QObject
{
    Q_OBJECT
public:
    client();
    ~client();
public:
    int init();
public Q_SLOTS:
    void onConnect();
private:
    network m_net;
};

#endif // CLIENT_H
