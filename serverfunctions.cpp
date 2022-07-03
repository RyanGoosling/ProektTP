/*!
 * \file
 * \brief Файл, содержащий реализацию методов класса ServerFunctions
 *
 * Данный класс реализует функционал сервера
 */

#include "serverfunctions.h"

/*!
 * \brief parsing обработка входящего сообщения от клиента
 * \param data_from_client строчка, отправленная клиентом
 * \param socket адрес сокета, необходимый для сохранения входа и обновления статистики
 * \return Функцию, к которой обратился клиент, либо ошибку о неверном синтаксисе
 */
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

/*!
     * \brief auth проверка авторизации
     * \param login логин, который ввёл пользователь
     * \param password пароль, который ввёл пользователь
     * \param socket адрес сокета, необходимый для сохранении информации о входе
     * \return 0 или 1 в соответствии с успешностью проверки
     */
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

    /*!
     * \brief reg функция регестрации нового пользователя
     * \param login логин, который ввёл пользователь
     * \param password пароль, который ввёл пользователь
     * \param email почта, которую ввёл пользователь
     * \return результат функции добавления записи в БД: True; The user is already registered.
     */
    QByteArray reg(QString login, QString password, QString email){
        QByteArray result = "";
        DataBase::getInstance();
        result.append(DataBase::Add(login, password, email).toUtf8());
        result.append("\n");
        return result;
    }

    /*!
     * \brief check функция вызова вывода данных таблицы БД в дебаг строку
     * \return результат успешности вывода: Success; Fail.
     */
    QByteArray check(){
        QByteArray result = "";
        DataBase::getInstance();
        result.append(DataBase::Check().toUtf8());
        result.append("\n");
        return result;
    }

    /*!
     * \brief updatestat функция вызова изменения статистики пользователя
     * \param task номер задания
     * \param move успешность выполнения самого задания
     * \param socket адрес сокета - уникальный индефикатор выполнения задания
     * При успешном выполнении задания добавляется 1 к 2 столбцам таблицы: taskN_right, taskN_all.
     * При неправильном выполнении задания добавляется 1 к столбцу таблицы taskN_all.
     */
    void updatestat(QString task, QString move, QString socket){
        if (move == "+")
            DataBase::query("UPDATE User SET task"+task+"_right = task"+task+"_right+1 WHERE socket = '"+socket+"'");
        DataBase::query("UPDATE User SET task"+task+"_all = task"+task+"_all+1 WHERE socket = '"+socket+"'");
    }
