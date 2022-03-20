#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class MyTcpServer : public QTcpServer //QObject//Убрано В
{
    Q_OBJECT
public:
    /*explicit*/ MyTcpServer();//(QObject *parent = nullptr);//Убрано В
    QTcpSocket * socket; //В
    ~MyTcpServer();
public slots:

    void incomingConnection(qintptr socketDescriptor); //В
    //void slotReadyRead(); //Убрано В

    //void slotNewConnection(); //Убрано В
    //void slotClientDisconnected(qintptr socketDescriptor);//Убрано В

    void slotServerRead();

private:
    QTcpServer * mTcpServer;
    QVector <QTcpSocket*> Sockets; //В
    QByteArray Data; //В

    //void SendToClient(QString str); //Убрано В
};
#endif // MYTCPSERVER_H







