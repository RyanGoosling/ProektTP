/*!
 * \file
 * \brief Заголовочный файл с описанием класса DataBase
 */

#ifndef DATABASE_H
#define DATABASE_H
#pragma once

#include <QString>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QTcpSocket>


class DataBase;

class DataBaseDestroyer
{
    private:
        DataBase * p_instance;
    public:
        ~DataBaseDestroyer() { delete p_instance;}
        void initialize(DataBase * p)
        {
            p_instance = p;
        }
};


class DataBase
{

    private:
        static DataBase * p_instance;
        static DataBaseDestroyer destroyer;

        static QSqlDatabase db;
    protected:
        DataBase(){
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("../ProektTP/DBserver.db");
            db.open();

            if (!db.open())
                qDebug() << db.lastError().text();
        }
        DataBase(const DataBase& );
        DataBase& operator = (DataBase &);
        ~DataBase() {}
        friend class DataBaseDestroyer;
    public:
        static DataBase* getInstance(){
            if (!p_instance)
            {
                // создать и открыть БД
                p_instance = new DataBase();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }

        static QString Add(QString login, QString password, QString email) { //регистрация пользователя
            if (DataBase::Found(login, password) != "Invalid login") return "The user is already registered"; //проверка на существование пользователя
            else {
                QSqlQuery query(db);
                query.prepare("INSERT INTO User(login, password, email)"
                                "VALUES (:login, :password, :email)");
                query.bindValue(":login", login);
                query.bindValue(":password", password);
                query.bindValue(":email", email);
                query.exec();
            return "True";
            }
        }

        static QString Found(QString login, QString password) { //вход с проверкой на логи, пароль
            QSqlQuery query(db);
            query.prepare("SELECT * FROM User where login = :login");
            query.bindValue(":login", login);
            query.exec();
            QSqlRecord rec = query.record();
            if (!query.next()) return "Invalid login";
            else
            {
                    if (password == query.value(rec.indexOf("password")).toString())
                    {

                        return "True";
                    }
                    else return "Invalid password";
            }
        }

        static QString Check(){ //дебаг таблицы - вывод данных таблицы в дебаг консоль
            QSqlQuery query(db);
            //query.exec("DROP TABLE User");
            //query.exec("Create table User (login varchar(30) not null, password varchar(30) not null, email varchar(30) not null, task1_all integer default 0, task1_right integer default 0, task2_all integer default 0, task2_right integer default 0, task3_all integer default 0, task3_right integer default 0, socket varchar(30) default '', role varchar(30) default '')");
            query.exec("SELECT * FROM User");
            QSqlRecord rec = query.record();
            QString login, password, email, socket, role;
            int task1_all, task1_right, task2_all, task2_right, task3_all, task3_right;
            bool flag = false;

            while (query.next()) {
               login = query.value(rec.indexOf("login")).toString();
               password = query.value(rec.indexOf("password")).toString();
               email = query.value(rec.indexOf("email")).toString();
               task1_all = query.value(rec.indexOf("task1_all")).toInt();
               task1_right = query.value(rec.indexOf("task1_right")).toInt();
               task2_all = query.value(rec.indexOf("task2_all")).toInt();
               task2_right = query.value(rec.indexOf("task2_right")).toInt();
               task3_all = query.value(rec.indexOf("task3_all")).toInt();
               task3_right = query.value(rec.indexOf("task3_right")).toInt();
               socket = query.value(rec.indexOf("socket")).toString();
               role = query.value(rec.indexOf("role")).toString();

               qDebug() << login << ";\t" << password << ";\t" << email << ";\t" << task1_all << ";\t" << task1_right
                           << ";\t" << task2_all << ";\t" << task2_right << ";\t" << task3_all << ";\t" << task3_right
                           << ";\t" << socket << ";\t" << role;
               if (!flag) flag = true;
            }
            if (flag)
                return "Succes"; //если что-то вывелось, то в сервер выводиться успех, иначе провал
            else {
                qDebug() << "Fail";
                return "Fail";
            }
        }

        static void closeDB()
        {
            db.close(); // Закрыть БД
        }

        static void logout(QString socket)
        {
            QSqlQuery query(db);//при отключении меняем с сокетДескриптор на 0 по дескриптору
            query.prepare("UPDATE User SET socket = '' WHERE socket = :socket");
            query.bindValue(":socket", socket);
            query.exec();
        }

        static void login(QString socket, QString login)
        {
            QSqlQuery query(db);
            query.prepare("UPDATE User SET socket = :socket WHERE login = :login");
            query.bindValue(":socket", socket);
            query.bindValue(":login", login);
            query.exec();
        }

        static void query(QString msg){
            QSqlQuery query(db);
            query.exec(msg);
            //QString result = "user_log_email_task1_task2_task3_status";
            //return result;
        }

};


#endif // DATABASE_H
