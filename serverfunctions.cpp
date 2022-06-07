/*!
 * \file
 * \brief Файл, содержащий реализацию методов класса ServerFunctions
 */

#include "serverfunctions.h"

QByteArray parsing (QString data_from_client, QString socket){
    QStringList data_from_client_list=data_from_client.split(QLatin1Char(' '), Qt::SkipEmptyParts);
    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();
    if (nameOfFunc=="auth")
        {
        if (data_from_client_list.length() == 2) return auth(data_from_client_list.at(0), data_from_client_list.at(1), socket);
        else return "Wrong input data - Need 2 parametrs.\n";
        }
    else if (nameOfFunc=="reg")
        {
        if (data_from_client_list.length() == 3) return reg(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2));
        else return "Wrong input data - Need 3 parametrs.\n";
        }
    else if (nameOfFunc=="check")
        {
        return check(); //вводить "check " без кавычек
        }
    else if (nameOfFunc == "updatestat")
        {
        updatestat(data_from_client_list.at(0), data_from_client_list.at(1), socket);
        return "State update.\n";
        }
    else if (nameOfFunc == "stat")
        {
        QByteArray stats = DataBase::stat(socket);
        return stats;
        }
    else return "Wrong syntax.\n";
}

    QByteArray auth(QString login, QString password, QString socket){

        DataBase::getInstance();
        QByteArray result = "";
        result.append(DataBase::Found(login, password).toUtf8());
        if (QString(result)=="True")
        {
            result = "1";
            DataBase::login(socket, login);
        }
        else result = "0";
        qDebug() << result;
        return result;
    }

    QByteArray reg(QString login, QString password, QString email){
        QByteArray result = "";
        DataBase::getInstance();
        result.append(DataBase::Add(login, password, email).toUtf8());
        result.append("\n");
        return result;
    }

    QByteArray check(){
        QByteArray result = "";
        DataBase::getInstance();
        result.append(DataBase::Check().toUtf8());
        result.append("\n");
        return result;
    }

    void updatestat(QString task, QString move, QString socket){
        if (move == "+")
            DataBase::query("UPDATE User SET task"+task+"_right = task"+task+"_right+1 WHERE socket = '"+socket+"'");
        DataBase::query("UPDATE User SET task"+task+"_all = task"+task+"_all+1 WHERE socket = '"+socket+"'");
    }
