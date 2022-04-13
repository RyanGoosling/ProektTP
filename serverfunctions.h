#ifndef SERVERFUNCTIONS_H
#define SERVERFUNCTIONS_H

#include <QString>

QByteArray parsing(QString data_from_client);

QByteArray auth(QString log, QString pass);

QByteArray reg(QString log, QString pass, QString email);

#endif // SERVERFUNCTIONS_H
