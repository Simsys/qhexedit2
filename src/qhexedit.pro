
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += core gui
TEMPLATE = lib

VERSION = 4.2.0

DEFINES += QHEXEDIT_EXPORTS

HEADERS = \
    qhexedit.h \
    chunks.h \
    commands.h


SOURCES = \
    qhexedit.cpp \
    chunks.cpp \
    commands.cpp

Release:TARGET = qhexedit
Debug:TARGET = qhexeditd


unix {
    # Allows users to specify parameters when running qmake
    QHEXEDIT_DESTDIR = $$(QHEXEDIT_DESTDIR)
    isEmpty(QHEXEDIT_DESTDIR): QHEXEDIT_DESTDIR = $$[QT_INSTALL_LIBS]
    target.path = $$QHEXEDIT_DESTDIR
    INSTALLS += target
}
win32:DESTDIR = ../lib
