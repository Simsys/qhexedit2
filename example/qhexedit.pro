QT += widgets
CONFIG += c++17

HEADERS = \
    mainwindow.h \
    optionsdialog.h \
    searchdialog.h \
    ../src/qhexedit.h \
    ../src/chunks.h \
    ../src/commands.h


SOURCES = \
    main.cpp \
    mainwindow.cpp \
    optionsdialog.cpp \
    searchdialog.cpp \
    ../src/qhexedit.cpp \
    ../src/chunks.cpp \
    ../src/commands.cpp

RESOURCES = \
    qhexedit.qrc

FORMS += \
    optionsdialog.ui \
    searchdialog.ui

TRANSLATIONS += \
    translations/qhexedit_cs.ts \
    translations/qhexedit_de.ts \
    translations/qhexedit_es.ts \
    translations/qhexedit_fr.ts \
    translations/qhexedit_it.ts \
    translations/qhexedit_ru.ts
    
DEFINES += QHEXEDIT_EXPORTS