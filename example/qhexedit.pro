QT += widgets
CONFIG += c++17

include(../src/qhexedit.pro)

HEADERS = \
    mainwindow.h \
    optionsdialog.h \
    searchdialog.h


SOURCES = \
    main.cpp \
    mainwindow.cpp \
    optionsdialog.cpp \
    searchdialog.cpp

RESOURCES = \
    qhexedit.qrc

FORMS += \
    optionsdialog.ui \
    searchdialog.ui

DEFINES += QHEXEDIT_EXPORTS
