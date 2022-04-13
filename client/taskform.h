#ifndef TASKFORM_H
#define TASKFORM_H
#include <QWidget>
#include "clientfunctions.h"
namespace Ui {
class TaskForm;
}

class TaskForm : public QWidget
{
    Q_OBJECT

public:
    explicit TaskForm(QWidget *parent = nullptr);
    ~TaskForm();
    void set_task(int n);
private slots:
    void on_pushButton_Ok_clicked();

private:
    Ui::TaskForm *ui;
    int task_num;
    QString input;
};

#endif // TASKFORM_H
