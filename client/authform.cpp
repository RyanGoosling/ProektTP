#include "authform.h"
#include "ui_authform.h"

AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm)
{
    ui->setupUi(this);
    ui->lineEdit_Email->setVisible(false);
}

AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::on_pushButton_Reg_clicked()
{
    ui->lineEdit_Login->setText("");
    ui->lineEdit_Password->setText("");
    ui->lineEdit_Email->setText("");
    ui->lineEdit_Email->setVisible(true);
    ui->pushButton_Reg->setVisible(false);
}


void AuthForm::on_pushButton_Ok_clicked()
{
    QString login = ui->lineEdit_Login->text();
    QString pass = ui->lineEdit_Password->text();
    if (ui->lineEdit_Email->isVisible()){
        QString email= ui->lineEdit_Email->text();
        reg(login,pass,email);
        ui->lineEdit_Email->setVisible(false);
        ui->pushButton_Reg->setVisible(true);
    }
    else {
    auth(login,pass);
    emit logged_in();
    hide();
    }
}

