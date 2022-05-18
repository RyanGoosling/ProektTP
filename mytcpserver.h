/*!
 * \file
 * \brief Заголовочный файл с описанием класса MyTcpServer
 */

#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

#include <QCoreApplication>
#include "serverfunctions.h"
#include "database.h"

class MyTcpServer : public  QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
     //QTcpSocket * socket;
    ~MyTcpServer();
public slots:

    void incomingConnection();

    void slotClientDisconnected();

    void slotServerRead();

private:
    QTcpServer * mTcpServer;

    QVector <QPair<QTcpSocket*,int>> Sockets;
};
#endif // MYTCPSERVER_H







