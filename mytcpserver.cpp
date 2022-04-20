/*!
 * \file
 * \brief Файл, содержащий реализацию методов класса MyTcpServer
 */

#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include "serverfunctions.h"

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::incomingConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 12345))
    {
        qDebug() << "server is not started";
    }
    else
    {
        qDebug() << "server is started";
    }
}

void MyTcpServer::incomingConnection()
{
    socket = mTcpServer->nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(socket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);

    Sockets.push_back(socket);
    qDebug() << "Client connection";
}

void MyTcpServer::slotServerRead(){
    QString res= "";
    socket = (QTcpSocket*)sender();
    while(socket->bytesAvailable()>0)
    {
        QByteArray array = socket->readAll();
        res.append(array);
        socket->write(parsing(res.toUtf8()));
    }

}

void MyTcpServer::slotClientDisconnected(){
    socket->close();
    qDebug() << "Client disconnected";
}
