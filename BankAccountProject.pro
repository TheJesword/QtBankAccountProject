TEMPLATE = app
TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp \
    user.cpp \
    account.cpp \
    checkingaccount.cpp \
    Savingsaccount.cpp

HEADERS += \
    window.h \
    user.h \
    account.h \
    checkingaccount.h \
    Savingsaccount.h
