#ifndef CLIENTFUNCTIONS_H
#define CLIENTFUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS
#include <QString>
#include <QDebug>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <QTime>
#include "Client.h"
#define SIZE 6
void auth(QString log,QString pass);
void reg(QString log,QString pass,QString mail);
void update_stat(int n, QString upd);
QString solve_task1(QString input);
QString solve_task2(QString input);
QString solve_task3(QString input);
QString generate_text_for_task1(QString input);
QString generate_text_for_task2(QString input);
QString generate_text_for_task3(QString input);
QString generate_task12();
QString generate_task3();
void check_task(int task_num,QString input,QString answer);
#endif // CLIENTFUNCTIONS_H
