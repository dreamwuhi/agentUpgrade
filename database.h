#ifndef DATABASE_H
#define DATABASE_H

/*
 *  数据库模块，静态类
*/
class database
{
public:
    int connentToDatabase();
    void disConnectToDatabase();
    static database* getInstance();

private:
    database(){}
    virtual ~database(){}
};

#endif // DATABASE_H
