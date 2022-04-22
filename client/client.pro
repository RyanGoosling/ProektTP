QT += core gui

QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TRANSLATIONS += \
    untitled_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

SOURCES += \
    authform.cpp \
    clientfunctions.cpp \
    main.cpp \
    mainwindow.cpp \
    taskform.cpp

HEADERS += \
    Client.h \
    authform.h \
    clientfunctions.h \
    mainwindow.h \
    taskform.h

FORMS += \
    authform.ui \
    mainwindow.ui \
    taskform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    untitled_ru_RU.ts
