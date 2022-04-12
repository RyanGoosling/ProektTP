#include "clientfunctions.h"

void auth(QString log,QString pass){
    QString res="auth&"+log+"&"+pass;
    qDebug()<< res;
};
void reg(QString log,QString pass,QString mail){
    QString res="auth&"+log+"&"+pass+"&"+mail;
    qDebug()<< res;
};
void update_stat(int n, QString upd){
    QString res= "updatestat&"+QString::number(n)+"&"+upd;
    qDebug()<< res;
};
QString solve_task1(QString input){
    return "placeholder1";
};
QString solve_task2(QString input){
    return "placeholder2";
};
QString solve_task3(QString input){
    return "placeholder3";
};
QString generate_text_for_task1(QString input){
    return "task1 "+input;
};
QString generate_text_for_task2(QString input){
    return "task2 "+input;
};
QString generate_text_for_task3(QString input){
    return "task3 "+input;
};
QString generate_task1(){
    return "task1";
};
QString generate_task2(){
    return "task2";
};
QString generate_task3(){
    return "task3";
};
void check_task(int task_num,QString input,QString answer){
    QString solution = "";
    switch (task_num) {
    case 1:
        solution = solve_task1(input);
        break;
    case 2:
        solution = solve_task2(input);
        break;
    case 3:
        solution = solve_task3(input);
        break;
    }
    if (answer==solution)
    update_stat(task_num,"+");
    else update_stat(task_num,"-");
};
