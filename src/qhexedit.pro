
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE    = lib

VERSION     = 2.1.0

CONFIG      += qt warn_on release

HEADERS     = \
    qhexedit.h \
    chunks.h \
    commands.h


SOURCES     = \
    qhexedit.cpp \
    chunks.cpp \
    commands.cpp

TARGET      = qhexedit

DESTDIR     = /usr/lib
