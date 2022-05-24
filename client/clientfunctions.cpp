#include "clientfunctions.h"
void auth(QString log,QString pass){
    QString res="auth "+log+" "+pass;
    Client::getInstance()->Client::SentToServer(res);
};
void reg(QString log,QString pass,QString mail){
    QString res="reg "+log+" "+pass+" "+mail;
    Client::getInstance()->Client::SentToServer(res);
};
void update_stat(int n, QString upd){
    QString res= "updatestat "+QString::number(n)+" "+upd;
    Client::getInstance()->Client::SentToServer(res);
    qDebug() << res;
};
QString solve_task1(QString input){ //FDNF input - task, return - answer
    qDebug() << input;
    QString answer = "";
    for (int i = 0; i < 8; ++i) //boolean function bypass
        if(input[i] == '1')
        {
            std::bitset<3> vars(i); // 000 -> 001 -> ... -> 111
            QString bracket = "(";
            int n = 1;
            for (int j = 2; j >= 0; j--)
            {
                if (vars[j] == 1)
                    bracket += "x" + QString::number(n) + " & ";
                else bracket += "x" + QString::number(n) + "' & ";
                n++;
            }
            bracket += ")";
            bracket.replace(bracket.length()-4, 5, ")"); //before: (x1' & x2' & x3' & ), after: (x1' & x2' & x3')
            answer += bracket + " V ";
        }
    answer.remove(answer.length()-3, 3);//remove excess " V ";
    qDebug() << answer;
    return answer;
};
QString solve_task2(QString input){//KNF input - task, return - answer
    qDebug() << input;
    QString answer = "";
    for (int i = 0; i < 8; ++i) //boolean function bypass
        if(input[i] == '0')
        {
            std::bitset<3> vars(i); // 000 -> 001 -> ... -> 111
            QString bracket = "(";
            int n = 1;
            for (int j = 2; j >= 0; j--)
            {
                if (vars[j] == 1)
                    bracket += "x" + QString::number(n) + "' V ";
                else bracket += "x" + QString::number(n) + " V ";
                n++;
            }
            bracket += ")";
            //bracket.replace(bracket.length()-4, 5, ")"); //before: (x1' V x2' V x3' V ), after: (x1' V x2' V x3')
            answer += bracket + " & ";
        }
    answer.remove(answer.length()-3, 3);//remove excess " & ";
    qDebug() << answer;
    return answer;
};
QString solve_task3(QString input){
    return "placeholder3";
};
QString generate_text_for_task1(QString input){ //отправляется в интерфейс юзера
    return "Найти ДНФ функции: "+input;
};
QString generate_text_for_task2(QString input){
    return "Найти КНФ функции: "+input;
};
QString generate_text_for_task3(QString input){
    return "task3 "+input;
};
QString generate_task1(){
    const QString possibleCharacters("01");
    const int BooleanLength = 8;

       QString BooleanFunction;
       for(int i=0; i < BooleanLength; ++i)
       {
           int index = qrand() % possibleCharacters.length();
           QChar nextChar = possibleCharacters.at(index);
           BooleanFunction.append(nextChar);
       }
       return BooleanFunction;
};
QString generate_task2(){
    const QString possibleCharacters("01");
    const int BooleanLength = 8;

       QString BooleanFunction;
       for(int i=0; i < BooleanLength; ++i)
       {
           int index = qrand() % possibleCharacters.length();
           QChar nextChar = possibleCharacters.at(index);
           BooleanFunction.append(nextChar);
       }
       return BooleanFunction;
};
QString generate_task3(){
    return "task3";
};
void check_task(int task_num, QString input, QString answer){ //input - решение (ответ) системы, answer - ответ пользователя
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
