#include "statform.h"
#include "ui_statform.h"

StatForm::StatForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatForm)
{
    ui->setupUi(this);
}

StatForm::~StatForm()
{
    delete ui;
}
void StatForm::setstat(){
    ui->textBrowser_task1->setText(QString::number(Client::getInstance()->stats.at(0))+" правильных ответов из "+QString::number(Client::getInstance()->stats.at(1)));
    ui->textBrowser_task2->setText(QString::number(Client::getInstance()->stats.at(2))+" правильных ответов из "+QString::number(Client::getInstance()->stats.at(3)));
    ui->textBrowser_task3->setText(QString::number(Client::getInstance()->stats.at(4))+" правильных ответов из "+QString::number(Client::getInstance()->stats.at(5)));
    this->show();
}
