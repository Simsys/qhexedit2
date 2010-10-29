TEMPLATE    = lib

CONFIG      += qt warn_on release

HEADERS     = ../src/qhexedit.h \
           ../src/qhexedit_p.h

SOURCES     = ../src/qhexedit.cpp \
            ../src/qhexedit_p.cpp

# RESOURCES   =  hexedit.qrc

TARGET      = qhexedit

DESTDIR     = /usr/lib
 
