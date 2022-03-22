#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include "serverfunctions.h"
MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
}

MyTcpServer::MyTcpServer(){//(QObject *parent) : QObject(parent){ //Убрано Вадим
//    mTcpServer = new QTcpServer(this);
//    connect(mTcpServer, &QTcpServer::newConnection,
//            this, &MyTcpServer::slotNewConnection);

    if(!this->listen(QHostAddress::Any, 12345))
    {
        qDebug() << "server is not started";
    }
    else
    {
        qDebug() << "server is started";
    }
}

void MyTcpServer::incomingConnection(qintptr socketDescriptor) //Вадим
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    qDebug() << "Client connection" << socketDescriptor;
}

//void MyTcpServer::slotReadyRead() //Вадим
//{
//    socket = (QTcpSocket*)sender();
//    QDataStream in(socket);
//    in.setVersion(QDataStream::Qt_5_9);
//    if(in.status() == QDataStream::Ok)
//    {
//        qDebug() << "read...";
//        QString str;
//        in >> str;
//        qDebug() << str;
//    }
//    else
//    {
//        qDebug() << "DataStream error";
//    }
//}

//void MyTcpServer::SendToClient(QString str) //Вадим
//{
//    Data.clear();
//    QDataStream out(&Data, QIODevice::WriteOnly);
//    out.setVersion(QDataStream::Qt_5_9);
//    out << str;
//    socket->write(Data);
//}

//void MyTcpServer::slotNewConnection(){ //Убрано Вадим
// //   if(server_status==1){
//        socket = mTcpServer->nextPendingConnection();
//        socket->write("Hello, World!!! I am echo server!\r\n");
//        connect(socket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
//        connect(socket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
//   // }
//}

void MyTcpServer::slotServerRead(){
    QString res= "";
    socket = (QTcpSocket*)sender(); //Добавлено Вадим
    while(socket->bytesAvailable()>0)
    {
        QByteArray array = socket->readAll();
        res.append(array);
    }
    socket->write(parsing(res));
}

//void MyTcpServer::slotClientDisconnected(){
//    socket->close();
//}
