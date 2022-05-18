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
    int socket_desc=socket->socketDescriptor();
    Sockets.push_back({socket,socket_desc});
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
    for (auto sock=0;sock<Sockets.size();sock++){
        if (Sockets.at(sock).first->state() == 0){
            Sockets.at(sock).first->close();
            DataBase::logout(Sockets.at(sock).second);
            Sockets.removeAt(sock);
        }
    }
}
