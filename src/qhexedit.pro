
QT += core gui widgets
TEMPLATE = lib

VERSION = 0.8.11

DEFINES += QHEXEDIT_EXPORTS

HEADERS = \
    qhexedit.h \
    chunks.h \
    commands.h \
    color_manager.h


SOURCES = \
    qhexedit.cpp \
    chunks.cpp \
    commands.cpp \
    color_manager.cpp

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
