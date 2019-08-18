#include "client.h"

client::client()
{

}

client::~client()
{

}

int client::init()
{
    m_net.init();
    QObject::connect(&m_net,&network::connectedSignal,this,&client::onConnect);
    return 0;
}

void client::onConnect()
{

}
