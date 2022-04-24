#ifndef AUTHFORM_H
#define AUTHFORM_H
#include "clientfunctions.h"
#include <QWidget>

namespace Ui {
class AuthForm;
}

class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(QWidget *parent = nullptr);
    ~AuthForm();
    Ui::AuthForm * auth_form(){
        return ui;
    }

private slots:
    void on_pushButton_Reg_clicked();

    void on_pushButton_Ok_clicked();

signals:
    void logged_in();
private:
    Ui::AuthForm *ui;
};

#endif // AUTHFORM_H
