CONFIG      += plugin
TEMPLATE    = lib
QT          += designer

INCLUDEPATH = ../src

HEADERS = \
    ../src/qhexedit.h \
    ../src/chunks.h \
    ../src/commands.h \
    QHexEditPlugin.h


SOURCES = \
    ../src/qhexedit.cpp \
    ../src/chunks.cpp \
    ../src/commands.cpp \
    QHexEditPlugin.cpp

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target