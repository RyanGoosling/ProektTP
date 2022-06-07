/********************************************************************************
** Form generated from reading UI file 'taskform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKFORM_H
#define UI_TASKFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser_Task;
    QTextBrowser *textBrowser_Question;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_Answer;
    QPushButton *pushButton_Ok;

    void setupUi(QWidget *TaskForm)
    {
        if (TaskForm->objectName().isEmpty())
            TaskForm->setObjectName(QString::fromUtf8("TaskForm"));
        TaskForm->resize(783, 660);
        verticalLayoutWidget = new QWidget(TaskForm);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(37, 50, 661, 491));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser_Task = new QTextBrowser(verticalLayoutWidget);
        textBrowser_Task->setObjectName(QString::fromUtf8("textBrowser_Task"));

        verticalLayout->addWidget(textBrowser_Task);

        textBrowser_Question = new QTextBrowser(verticalLayoutWidget);
        textBrowser_Question->setObjectName(QString::fromUtf8("textBrowser_Question"));

        verticalLayout->addWidget(textBrowser_Question);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_Answer = new QLineEdit(verticalLayoutWidget);
        lineEdit_Answer->setObjectName(QString::fromUtf8("lineEdit_Answer"));

        horizontalLayout->addWidget(lineEdit_Answer);

        pushButton_Ok = new QPushButton(verticalLayoutWidget);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));

        horizontalLayout->addWidget(pushButton_Ok);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TaskForm);

        QMetaObject::connectSlotsByName(TaskForm);
    } // setupUi

    void retranslateUi(QWidget *TaskForm)
    {
        TaskForm->setWindowTitle(QCoreApplication::translate("TaskForm", "Form", nullptr));
        textBrowser_Question->setHtml(QCoreApplication::translate("TaskForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Question for Task</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        lineEdit_Answer->setPlaceholderText(QCoreApplication::translate("TaskForm", "Your answer", nullptr));
        pushButton_Ok->setText(QCoreApplication::translate("TaskForm", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskForm: public Ui_TaskForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKFORM_H
