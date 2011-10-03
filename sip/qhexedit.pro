TEMPLATE    = lib

CONFIG      += qt warn_on release

HEADERS     = \
    ../src/qhexedit.h \
    ../src/qhexedit_p.h \
    ../src/xbytearray.h \
    ../src/commands.h


SOURCES     = \
    ../src/qhexedit.cpp \
    ../src/qhexedit_p.cpp \
    ../src/xbytearray.cpp \
    ../src/commands.cpp

# RESOURCES   =  hexedit.qrc

TARGET      = qhexedit

DESTDIR     = /usr/lib
 
