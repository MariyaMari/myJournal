#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T13:20:43
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ElectronicJournal
TEMPLATE = app

deployment.files += test.db
deployment.path = /assets
INSTALLS += deployment

SOURCES += main.cpp\
        mainform.cpp \
    worktables.cpp \
    spravochniki.cpp \
    formdiscipline.cpp \
    formspecialty.cpp \
    formtypeworks.cpp \
    formfaculty.cpp \
    formstudents.cpp \
    formgroup.cpp \
    toplan.cpp \
    tocompositiongroup.cpp \
    tovisit.cpp \
    tolistworks.cpp \
    tomadeworks.cpp \
    tableplan.cpp \
    tablecompositiongroup.cpp \
    tablevisit.cpp \
    tablelistworks.cpp \
    tablemadeworks.cpp

HEADERS  += mainform.h \
    worktables.h \
    spravochniki.h \
    formdiscipline.h \
    formspecialty.h \
    formtypeworks.h \
    formfaculty.h \
    formstudents.h \
    formgroup.h \
    toplan.h \
    tocompositiongroup.h \
    tovisit.h \
    tolistworks.h \
    tomadeworks.h \
    tableplan.h \
    tablecompositiongroup.h \
    tablevisit.h \
    tablelistworks.h \
    tablemadeworks.h

FORMS    += mainform.ui \
    worktables.ui \
    spravochniki.ui \
    formdiscipline.ui \
    formspecialty.ui \
    formtypeworks.ui \
    formfaculty.ui \
    formstudents.ui \
    formgroup.ui \
    toplan.ui \
    tocompositiongroup.ui \
    tovisit.ui \
    tolistworks.ui \
    tomadeworks.ui \
    tableplan.ui \
    tablecompositiongroup.ui \
    tablevisit.ui \
    tablelistworks.ui \
    tablemadeworks.ui

CONFIG += mobility
MOBILITY = 


