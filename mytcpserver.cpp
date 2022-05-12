/*!
 * \file
 * \brief Файл, содержащий реализацию методов класса MyTcpServer
 */

#include "mytcpserver.h"


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
    QTcpSocket* socket = mTcpServer->nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(socket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
    //connect(socket, SIGNAL(QTcpSocket::stateChanged(QTcpSocket::ClosingState)), this, SLOT(MyTcpServer::slotClientDisconnected));

    Sockets.push_back(socket);
    qDebug() << "Client connection"<<socket->socketDescriptor();
}

void MyTcpServer::slotServerRead(){
    QString res= "";
    QTcpSocket* socket = (QTcpSocket*)sender();
    while(socket->bytesAvailable()>0)
    {
        QByteArray array = socket->readAll();
        res.append(array);
        socket->write(parsing(res.toUtf8(), socket->socketDescriptor()));
    }

}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* socket = (QTcpSocket*)sender();
    //Sockets.remove(Sockets.indexOf(socket));
    DataBase::logout(socket->socketDescriptor());
    qDebug() << "Client disconnected"<<socket->socketDescriptor();
    socket->close();
    //socket->deleteLater();
    qDebug()<<socket->state();
}
