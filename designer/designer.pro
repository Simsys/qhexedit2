CONFIG      += plugin
TEMPLATE    = lib
QT          += designer

include(../src/qhexedit.pro)
INCLUDEPATH = ../src

HEADERS = \
    QHexEditPlugin.h


SOURCES = \
    QHexEditPlugin.cpp

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target