#include "clientfunctions.h"

void auth(QString log,QString pass){
    QString res="auth "+log+" "+pass;
    Client::getInstance()->Client::SentToServer(res);
    qDebug() << res;
};
void reg(QString log,QString pass,QString mail){
    QString res="reg "+log+" "+pass+" "+mail;
    Client::getInstance()->Client::SentToServer(res);
    qDebug() << res;
};
void update_stat(int n, QString upd){
    QString res= "updatestat "+QString::number(n)+" "+upd;
    Client::getInstance()->Client::SentToServer(res);
    qDebug() << res;
};

QString solve_task1(QString input){ //FDNF input - task, return - answer скобки вразнобой - проверка на соответсвие
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
QString solve_task2(QString input){//KNF input - task, return - answer скобки вразнобой - проверка на соответсвие
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
            bracket.replace(bracket.length()-4, 5, ")"); //before: (x1' V x2' V x3' V ), after: (x1' V x2' V x3')
            answer += bracket + " & ";
        }
    answer.remove(answer.length()-3, 3);//remove excess " & ";
    qDebug() << answer;
    return answer;
};
QString solve_task3(QString input){
    QStringList data_list=input.split(QRegExp("\\s+"));

    int array[SIZE][SIZE];
    for (int i = 0; i<SIZE; i++)
    {
        for (int j = 0; j<SIZE; j++) {
            array[i][j] = data_list.front().toInt();
            data_list.pop_front();
        }
    }

    //int array[SIZE][SIZE]; // матрица связей
    int d[SIZE]; // минимальное расстояние
    int v[SIZE]; // посещенные вершины
    int temp, minindex, min;
    int begin_index = 0;
    for (int i = 0; i<SIZE; i++)
      {
        d[i] = 10000;
        v[i] = 1;
      }
      d[begin_index] = 0;
      // Шаг алгоритма
      do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i<SIZE; i++)
        { // Если вершину ещё не обошли и вес меньше min
          if ((v[i] == 1) && (d[i]<min))
          { // Переприсваиваем значения
            min = d[i];
            minindex = i;
          }
        }
        // Добавляем найденный минимальный вес
        // к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
        if (minindex != 10000)
        {
          for (int i = 0; i<SIZE; i++)
          {
            if (array[minindex][i] > 0)
            {
              temp = min + array[minindex][i];
              if (temp < d[i])
              {
                d[i] = temp;
              }
            }
          }
          v[minindex] = 0;
        }
      } while (minindex < 10000);
    return QString::number(d[5]);
};

QString generate_text_for_task1(QString input){ //отправляется в интерфейс юзера
    return "Найти ДНФ функции: "+input;
};
QString generate_text_for_task2(QString input){
    return "Найти КНФ функции: "+input;
};
QString generate_text_for_task3(QString input){//вывод двумерного массива в окно задачи
    return "Найти кратчайший путь от вершины 1, к вершине 6 по матрице смежности:\n"+input;
};

QString generate_task12(){
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
QString generate_task3(){ //output двумерный массив - матрица связи
    QTime midnight(0,0,0);
    QRandomGenerator generator(midnight.secsTo(QTime::currentTime()));

    QString res;
    int array[SIZE][SIZE]; // матрица связей
    int temp;
    for (int i = 0; i<SIZE; i++)
    {
        array[i][i] = 0;
        for (int j = i + 1; j<SIZE; j++) {
            temp = generator.bounded(1,10); //[1; 10]
            array[i][j] = temp;
            array[j][i] = temp;
        }
    }
    for (int i = 0; i<SIZE; i++)
    {    for(int j=0;j<SIZE;j++)

          res+= QString::number(array[i][j]) + "\t" ;
        res += "\n";
    }
    return res;
};

void check_task(int task_num, QString input, QString answer){ //input - условие, answer - ответ пользователя
    QString solution = ""; //solution - решение системы
    bool flag = true;
    QStringList answer_list, solution_list;
    qDebug() << answer;
    switch (task_num) {
    case 1:
        solution_list=solve_task1(input).split(QLatin1Char('V'));
        solution_list.replaceInStrings(") ", ")");
        solution_list.replaceInStrings(" (", "(");

        answer_list = answer.split(QLatin1Char('V'));
        answer_list.replaceInStrings(") ", ")");
        answer_list.replaceInStrings(" (", "(");

        if (answer_list.size() == solution_list.size())
        {
            for (int i = 0; i < solution_list.size(); i++)
                if (!(solution_list.contains(answer_list[i])))
                    flag = false;
        }
        else flag = false;
        break;
    case 2:
        solution_list=solve_task2(input).split(QLatin1Char('&'));
        solution_list.replaceInStrings(") ", ")");
        solution_list.replaceInStrings(" (", "(");

        answer_list = answer.split(QLatin1Char('&'));
        answer_list.replaceInStrings(") ", ")");
        answer_list.replaceInStrings(" (", "(");

        if (answer_list.size() == solution_list.size())
        {
            for (int i = 0; i < solution_list.size(); i++)
                if (!(solution_list.contains(answer_list[i])))
                    flag = false;
        }
        else flag = false;
        break;
    case 3:
        solution = solve_task3(input);
        if (solution != answer)
            flag = false;
        break;
    }
    if (flag)
    update_stat(task_num,"+");
    else update_stat(task_num,"-");
};
