/********************************************************************************
** Form generated from reading UI file 'authform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHFORM_H
#define UI_AUTHFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_Login;
    QLineEdit *lineEdit_Password;
    QLineEdit *lineEdit_Email;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Ok;
    QPushButton *pushButton_Reg;

    void setupUi(QWidget *AuthForm)
    {
        if (AuthForm->objectName().isEmpty())
            AuthForm->setObjectName(QString::fromUtf8("AuthForm"));
        AuthForm->resize(646, 536);
        verticalLayoutWidget = new QWidget(AuthForm);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 40, 531, 441));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_Login = new QLineEdit(verticalLayoutWidget);
        lineEdit_Login->setObjectName(QString::fromUtf8("lineEdit_Login"));

        verticalLayout->addWidget(lineEdit_Login);

        lineEdit_Password = new QLineEdit(verticalLayoutWidget);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));

        verticalLayout->addWidget(lineEdit_Password);

        lineEdit_Email = new QLineEdit(verticalLayoutWidget);
        lineEdit_Email->setObjectName(QString::fromUtf8("lineEdit_Email"));
        lineEdit_Email->setMaxLength(32767);

        verticalLayout->addWidget(lineEdit_Email);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_Ok = new QPushButton(verticalLayoutWidget);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));

        horizontalLayout->addWidget(pushButton_Ok);

        pushButton_Reg = new QPushButton(verticalLayoutWidget);
        pushButton_Reg->setObjectName(QString::fromUtf8("pushButton_Reg"));

        horizontalLayout->addWidget(pushButton_Reg);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AuthForm);

        QMetaObject::connectSlotsByName(AuthForm);
    } // setupUi

    void retranslateUi(QWidget *AuthForm)
    {
        AuthForm->setWindowTitle(QCoreApplication::translate("AuthForm", "Form", nullptr));
        lineEdit_Login->setPlaceholderText(QCoreApplication::translate("AuthForm", "Login", nullptr));
        lineEdit_Password->setPlaceholderText(QCoreApplication::translate("AuthForm", "Password", nullptr));
        lineEdit_Email->setInputMask(QString());
        lineEdit_Email->setText(QString());
        lineEdit_Email->setPlaceholderText(QCoreApplication::translate("AuthForm", "Email", nullptr));
        pushButton_Ok->setText(QCoreApplication::translate("AuthForm", "Ok", nullptr));
        pushButton_Reg->setText(QCoreApplication::translate("AuthForm", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthForm: public Ui_AuthForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHFORM_H
