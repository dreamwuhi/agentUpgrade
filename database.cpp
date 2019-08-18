#include "database.h"



int database::connentToDatabase()
{
    int iRet = 0;
    return iRet;
}

void database::disConnectToDatabase()
{

}

database *database::getInstance()
{
    static database inst;
    return &inst;
}
