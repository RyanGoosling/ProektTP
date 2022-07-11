#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Client.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auth_f = new AuthForm;
    task_f = new TaskForm;
    stat_f = new StatForm;
    auth_f->show();
    connect(Client::getInstance(),&Client::logged_in,this,&MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Task1_clicked()
{
    task_f->set_task(1);
    task_f->show();
}
void MainWindow::on_pushButton_Task2_clicked()
{
    task_f->set_task(2);
    task_f->show();
}
void MainWindow::on_pushButton_Task3_clicked()
{
    task_f->set_task(3);
    task_f->show();
}


void MainWindow::on_actionTask1_triggered()
{
    on_pushButton_Task1_clicked();
}
void MainWindow::on_actionTask2_triggered()
{
    on_pushButton_Task2_clicked();
}

void MainWindow::on_actionTask3_triggered()
{
    on_pushButton_Task3_clicked();
}



void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_pushButton_Exit_clicked()
{
    close();
}


void MainWindow::on_pushButton_Stat_clicked()
{
    Client::getInstance()->Client::SentToServer("stat");
    connect(Client::getInstance(),&Client::stat_in,stat_f,&StatForm::setstat);
}

