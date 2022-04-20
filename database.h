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
        DataBase(){}
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
                p_instance->db = QSqlDatabase::addDatabase("QSQLITE");
                p_instance->db.setDatabaseName("DBserver.db");

                db.open();

                if (!p_instance->db.open())
                    qDebug() << p_instance->db.lastError().text();

                QSqlQuery query(p_instance->db);
                query.exec("CREATE TABLE IF NOT EXISTS User("
                           "login VARCHAR(20) NOT NULL UNIQUE, "
                           "password VARCHAR(20) NOT NULL,"
                           "email VARCHAR(30) NOT NULL UNIQUE"
                           ")");

                destroyer.initialize(p_instance);
            }
            return p_instance;
        }

        static QString Add(QString login, QString password, QString email) {
            if (DataBase::Found(login, password) != "Invalid login") return "The user is already registered";
            else {
                QSqlQuery query(p_instance->db);
                query.prepare("INSERT INTO User(login, password, email)"
                                "VALUES (:login, :password, :email)");
                query.bindValue(":login", login);
                query.bindValue(":password", password);
                query.bindValue(":email", email);
                query.exec();
            return "True";
            }
        }

        static QString Found(QString login, QString password) {
            QSqlQuery query(p_instance->db);
            query.prepare("SELECT * FROM User where login = :login");
            query.bindValue(":login", login);
            query.exec();
            QSqlRecord rec = query.record();
            //int PasswordIndex = rec.indexOf("password");
            if (!query.next()) return "Invalid login";
            else
            {
                //QString TruePassword = query.value(rec.indexOf("password")).toString();

                /*if (login == query.value(rec.indexOf("login")).toString())
                {*/
                    if (password == query.value(rec.indexOf("password")).toString()) return "True";
                    else return "Invalid password";
                /*}
                else return "Invalid login";*/
            }
        }

        static QString Check(){
            QSqlQuery query(p_instance->db);
            query.exec("SELECT * FROM User");
            QSqlRecord rec = query.record();
            QString login, password, email;
            bool flag = false;

            while (query.next()) {
               login = query.value(rec.indexOf("login")).toString();
               password = query.value(rec.indexOf("password")).toString();
               email = query.value(rec.indexOf("email")).toString();

               qDebug() << login << ";\t" <<password<<";\t"<<email;
               if (!flag) flag = true;
               //else continue;
            }
            //query.exec("DROP TABLE User");
            if (flag)
                return "Succes";
            else {
                qDebug() << "Fail";
                return "Fail";
            }
        }

        static void closeDB()
        {
            p_instance->db.close(); // Закрыть БД
        }

};


DataBase * DataBase::p_instance = nullptr;
DataBaseDestroyer DataBase::destroyer;
QSqlDatabase DataBase::db;

#endif // DATABASE_H
