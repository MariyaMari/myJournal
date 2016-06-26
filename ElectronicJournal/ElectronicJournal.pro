#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T13:20:43
#
#-------------------------------------------------

QT       += core gui sql widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += release c++11
QMAKE_CXXFLAGS += -std=c++11

TARGET = ElectronicJournal
TEMPLATE = app

CONFIG += release c++11
INCLUDEPATH += ../ImportExport
LIBPATH     += ../ElectronicJournal
LIBS   += -L../../ImportExport
LIBS   += -lImportExport

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
    tablemadeworks.cpp \
    mainwindow.cpp \
    settings.cpp \
    addspecialty.cpp \
    addgroup.cpp \
    addplan.cpp \
    addlistworks.cpp

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
    tablemadeworks.h \
    mainwindow.h \
    settings.h \
    addspecialty.h \
    addgroup.h \
    addplan.h \
    addlistworks.h

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
    tablemadeworks.ui \
    mainwindow.ui \
    addspecialty.ui \
    addgroup.ui \
    addplan.ui \
    addlistworks.ui

CONFIG += mobility
MOBILITY = 


