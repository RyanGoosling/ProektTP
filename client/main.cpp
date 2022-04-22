#include "mainwindow.h"
#include "Client.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
/*
Client * Client::p_instance = 0;
ClientDestroyer Client::destroyer;
Client MyClient;
*/

Client * Client::p_instance=0;
ClientDestroyer Client::destroyer;
QTcpSocket * Client::mTcpSocket;
/*DataBase * DataBase::p_instance = 0;
DataBaseDestroyer DataBase::destroyer;

QSqlDatabase DataBase::db;*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
Client::getInstance();

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "untitled_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;

    return a.exec();
}
