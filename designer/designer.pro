CONFIG      += plugin
TEMPLATE    = lib
QT          += designer

INCLUDEPATH = ../src

HEADERS = \
    QHexEditPlugin.h


SOURCES = \
    QHexEditPlugin.cpp

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target