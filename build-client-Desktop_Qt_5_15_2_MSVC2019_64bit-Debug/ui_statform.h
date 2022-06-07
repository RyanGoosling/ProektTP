/********************************************************************************
** Form generated from reading UI file 'statform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATFORM_H
#define UI_STATFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatForm
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser_task1;
    QTextBrowser *textBrowser_task2;
    QTextBrowser *textBrowser_task3;

    void setupUi(QWidget *StatForm)
    {
        if (StatForm->objectName().isEmpty())
            StatForm->setObjectName(QString::fromUtf8("StatForm"));
        StatForm->resize(981, 590);
        horizontalLayoutWidget = new QWidget(StatForm);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(80, 50, 791, 441));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textBrowser_task1 = new QTextBrowser(horizontalLayoutWidget);
        textBrowser_task1->setObjectName(QString::fromUtf8("textBrowser_task1"));

        verticalLayout_2->addWidget(textBrowser_task1);

        textBrowser_task2 = new QTextBrowser(horizontalLayoutWidget);
        textBrowser_task2->setObjectName(QString::fromUtf8("textBrowser_task2"));

        verticalLayout_2->addWidget(textBrowser_task2);

        textBrowser_task3 = new QTextBrowser(horizontalLayoutWidget);
        textBrowser_task3->setObjectName(QString::fromUtf8("textBrowser_task3"));

        verticalLayout_2->addWidget(textBrowser_task3);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(StatForm);

        QMetaObject::connectSlotsByName(StatForm);
    } // setupUi

    void retranslateUi(QWidget *StatForm)
    {
        StatForm->setWindowTitle(QCoreApplication::translate("StatForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("StatForm", "task1", nullptr));
        label_2->setText(QCoreApplication::translate("StatForm", "task2", nullptr));
        label_3->setText(QCoreApplication::translate("StatForm", "task3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatForm: public Ui_StatForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATFORM_H
