#include "taskform.h"
#include "ui_taskform.h"

TaskForm::TaskForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskForm)
{
    ui->setupUi(this);
}

TaskForm::~TaskForm()
{
    delete ui;
}

void TaskForm::on_pushButton_Ok_clicked()
{
    check_task(task_num,input,ui->lineEdit_Answer->text());
    ui->lineEdit_Answer->setText("");
    hide();
}

void TaskForm::set_task(int n)
{
    task_num=n;
    QString task="";
    switch(n){
    case 1:
        input=generate_task1();
        task = generate_text_for_task1(input);
        break;
    case 2:
        input=generate_task2();
        task = generate_text_for_task2(input);
        break;
    case 3:
        input=generate_task3();
        task = generate_text_for_task3(input);
        break;
    }
    ui->textBrowser_Task->setText(task);
}
