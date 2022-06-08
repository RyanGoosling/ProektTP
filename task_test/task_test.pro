QT += testlib
QT -= gui
QT += network

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_task1_test.cpp \
    ../client/clientfunctions.cpp

HEADERS += \
    ../client/Client.h \
    ../client/clientfunctions.h
