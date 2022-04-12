#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "authform.h"
#include "taskform.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Task1_clicked();
    void on_pushButton_Task2_clicked();
    void on_pushButton_Task3_clicked();
    void on_actionTask1_triggered();
    void on_actionTask2_triggered();
    void on_actionTask3_triggered();
    void on_actionExit_triggered();

    void on_pushButton_Exit_clicked();

private:
    Ui::MainWindow *ui;
    AuthForm *auth_f;
    TaskForm *task_f;
};
#endif // MAINWINDOW_H
