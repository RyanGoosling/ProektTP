/*!
 * \file
 * \brief Заголовочный файл, определяющий функции сервера для взаимодействия с клиентом
 */

#ifndef SERVERFUNCTIONS_H
#define SERVERFUNCTIONS_H

#include <QString>

QByteArray parsing(QString data_from_client, int descript);

QByteArray auth(QString log, QString pass, int descript);

QByteArray reg(QString log, QString pass, QString email);

QByteArray check();

#endif // SERVERFUNCTIONS_H
