greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE    = lib

VERSION     = 2.0.0

CONFIG      += qt warn_on release

HEADERS     = \
    ../src/qhexedit.h \
    ../src/chunks.h \
    ../src/commands.h


SOURCES     = \
    ../src/qhexedit.cpp \
    ../src/chunks.cpp \
    ../src/commands.cpp

TARGET      = qhexedit

DESTDIR     = /usr/lib

win32 {
DESTDIR     = D:\\Programme\\Python27\\Lib\\site-packages\\PyQt4
}
