/*!
 * \file
 * \brief Файл, содержащий реализацию методов класса ServerFunctions
 */

#include "serverfunctions.h"
#include "database.h"
#include <QStringList>

QByteArray parsing (QString data_from_client){
    QStringList data_from_client_list=data_from_client.split(QLatin1Char(' '));
    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();
    if (nameOfFunc=="auth")
        {
        if (data_from_client_list.length() == 2) return auth(data_from_client_list.at(0), data_from_client_list.at(1));
        else return "Wrong input data - Need 2 parametrs.\n";
        }
    else if (nameOfFunc=="reg")
        {
        if (data_from_client_list.length() == 3) return reg(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2));
        else return "Wrong input data - Need 3 parametrs.\n";
        }
    else return "Wrong syntax.\n";
}

    QByteArray auth(QString log, QString pass){
        QByteArray result = "";
        DataBase::getInstance();
        result.append(DataBase::TestLogAndPas(log, pass).toUtf8());
        result.append("\n");
        return result;
    }
    QByteArray reg(QString log, QString pass, QString email){
        QByteArray result = "";
        DataBase::getInstance();
        result.append(DataBase::AddLogAndPas(log, pass, email).toUtf8());
        result.append("\n");
        return result;
    }
