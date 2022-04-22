/*!
 * \file
 */

#include <QCoreApplication>
#include "mytcpserver.h"
#include "database.h"

DataBase * DataBase::p_instance = 0;
DataBaseDestroyer DataBase::destroyer;

QSqlDatabase DataBase::db;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer myserv;
    return a.exec();
}
