/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTask1;
    QAction *actionTask2;
    QAction *actionTask3;
    QAction *actionExit;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Task1;
    QPushButton *pushButton_Task2;
    QPushButton *pushButton_Task3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Stat;
    QPushButton *pushButton_Exit;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionTask1 = new QAction(MainWindow);
        actionTask1->setObjectName(QString::fromUtf8("actionTask1"));
        actionTask2 = new QAction(MainWindow);
        actionTask2->setObjectName(QString::fromUtf8("actionTask2"));
        actionTask3 = new QAction(MainWindow);
        actionTask3->setObjectName(QString::fromUtf8("actionTask3"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 60, 721, 451));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_Task1 = new QPushButton(verticalLayoutWidget);
        pushButton_Task1->setObjectName(QString::fromUtf8("pushButton_Task1"));

        horizontalLayout->addWidget(pushButton_Task1);

        pushButton_Task2 = new QPushButton(verticalLayoutWidget);
        pushButton_Task2->setObjectName(QString::fromUtf8("pushButton_Task2"));

        horizontalLayout->addWidget(pushButton_Task2);

        pushButton_Task3 = new QPushButton(verticalLayoutWidget);
        pushButton_Task3->setObjectName(QString::fromUtf8("pushButton_Task3"));

        horizontalLayout->addWidget(pushButton_Task3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_Stat = new QPushButton(verticalLayoutWidget);
        pushButton_Stat->setObjectName(QString::fromUtf8("pushButton_Stat"));

        horizontalLayout_2->addWidget(pushButton_Stat);

        pushButton_Exit = new QPushButton(verticalLayoutWidget);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));

        horizontalLayout_2->addWidget(pushButton_Exit);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionTask1);
        menuMenu->addAction(actionTask2);
        menuMenu->addAction(actionTask3);
        menuMenu->addSeparator();
        menuMenu->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionTask1->setText(QCoreApplication::translate("MainWindow", "Task1", nullptr));
        actionTask2->setText(QCoreApplication::translate("MainWindow", "Task2", nullptr));
        actionTask3->setText(QCoreApplication::translate("MainWindow", "Task3", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        pushButton_Task1->setText(QCoreApplication::translate("MainWindow", "Task 1", nullptr));
        pushButton_Task2->setText(QCoreApplication::translate("MainWindow", "Task 2", nullptr));
        pushButton_Task3->setText(QCoreApplication::translate("MainWindow", "Task 3", nullptr));
        pushButton_Stat->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
