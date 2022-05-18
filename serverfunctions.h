/*!
 * \file
 * \brief Заголовочный файл, определяющий функции сервера для взаимодействия с клиентом
 */

#ifndef SERVERFUNCTIONS_H
#define SERVERFUNCTIONS_H

#include "database.h"
#include <QString>
#include <QTcpSocket>
#include <QStringList>
#include <qdebug.h>

QByteArray parsing(QString data_from_client, QString socket);

QByteArray auth(QString log, QString pass, QString socket);

QByteArray reg(QString log, QString pass, QString email);

QByteArray check();

#endif // SERVERFUNCTIONS_H
