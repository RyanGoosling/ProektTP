//Улучшенная реализация
#ifndef CLIENT_H
#define CLIENT_H
#pragma once

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QObject>
#include <QTcpSocket>
#include "clientfunctions.h"
class Client;

class ClientDestroyer
{
	private:
		Client * p_instance;
	public:
		~ClientDestroyer() { delete p_instance;}
        void initialize(Client * p){p_instance = p;}
};


class Client: public QObject
{
	Q_OBJECT
	private:
		static Client * p_instance;
		static ClientDestroyer destroyer;
        static QTcpSocket * mTcpSocket;
	protected:
         Client(QObject *parent = nullptr)
		{
			mTcpSocket = new QTcpSocket(this);
    		mTcpSocket->connectToHost("127.0.0.1", 12345);
    		connect(mTcpSocket, &QTcpSocket::readyRead,
            	this, &Client::slotServerRead);
/*
    		if(mTcpSocket->state()==3 || mTcpSocket->state()==2){
        		qDebug() << "client connected";
    		} else {
        		qDebug() << "client not connected";
    		}
    */	}
		~Client() {mTcpSocket->close();}

		Client(const Client& );
		Client& operator = (Client &);
		friend class ClientDestroyer;

    public:
        int test=0;
        int get_test(){
            return test;
        }
		static Client* getInstance(){
			if (!p_instance)
			{
				p_instance = new Client();
				destroyer.initialize(p_instance);
			}
			return p_instance;
		}
    //explicit MyTcpServer(QObject *parent = nullptr);
    void SentToServer(QString request)
	{
		mTcpSocket->write(request.toUtf8());
	}

	public slots:
    void slotServerRead()
	{
		while(mTcpSocket->bytesAvailable()>0)
    	{
        	QByteArray array = mTcpSocket->readAll();
            if (array=="1"){
                test=1;
            }
    	}
	}
};

#endif // CLIENT_H
