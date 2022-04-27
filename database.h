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
                    if (password == query.value(rec.indexOf("password")).toString()) return "True";
                    else return "Invalid password";
            }
        }

        static QString Check(){ //дебаг таблицы - вывод данных таблицы в дебаг консоль
            QSqlQuery query(db);
            query.exec("SELECT * FROM User");
            QSqlRecord rec = query.record();
            QString login, password, email;
            bool flag = false;

            while (query.next()) {
               login = query.value(rec.indexOf("login")).toString();
               password = query.value(rec.indexOf("password")).toString();
               email = query.value(rec.indexOf("email")).toString();

               qDebug() << login << ";\t" << password << ";\t" << email;
               if (!flag) flag = true;
            }
            //query.exec("DROP TABLE User");
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

};


#endif // DATABASE_H
