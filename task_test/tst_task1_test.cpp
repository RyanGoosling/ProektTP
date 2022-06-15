#include <QtTest>

// add necessary includes here
#include "../client/clientfunctions.h"
#include <QWidget>

Client * Client::p_instance=0;
ClientDestroyer Client::destroyer;
QTcpSocket * Client::mTcpSocket;

class task_test : public QObject
{
    Q_OBJECT

public:
    task_test();
    ~task_test();

private slots:
    void test_case1();
    void test_case2();

};

task_test::task_test()
{

}

task_test::~task_test()
{

}

void task_test::test_case1()
{
    QCOMPARE("(x1' & x2' & x3') V (x1' & x2 & x3) V (x1 & x2' & x3') V (x1 & x2' & x3) V (x1 & x2 & x3')", solve_task1("10011110"));
}

void task_test::test_case2()
{
    QCOMPARE("(x1 V x2' V x3) & (x1 V x2' V x3') & (x1' V x2 V x3') & (x1' V x2' V x3) & (x1' V x2' V x3')", solve_task2("11001000"));
}

QTEST_APPLESS_MAIN(task_test)

#include "tst_task1_test.moc"
