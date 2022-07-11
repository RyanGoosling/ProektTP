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
    void test_case3();

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

void task_test::test_case3()
{
    QCOMPARE("1", solve_task3("0\t3\t9\t6\t5\t1\t\n3\t0\t3\t2\t1\t6\t\n9\t3\t0\t5\t2\t3\t\n6\t2\t5\t0\t9\t7\t\n5\t1\t2\t9\t0\t2\t\n1\t6\t3\t7\t2\t0\t\n"));
}

QTEST_APPLESS_MAIN(task_test)

#include "tst_task1_test.moc"
