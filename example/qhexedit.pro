greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS = \
    mainwindow.h \
    optionsdialog.h \
    ../src/qhexedit.h \
    ../src/qhexedit_p.h \
    ../src/xbytearray.h \
    ../src/commands.h \
    searchdialog.h


SOURCES = \
    main.cpp \
    mainwindow.cpp \
    optionsdialog.cpp \
    ../src/qhexedit.cpp \
    ../src/qhexedit_p.cpp \
    ../src/xbytearray.cpp \
    ../src/commands.cpp \
    searchdialog.cpp

RESOURCES = \
    qhexedit.qrc

FORMS += \
    optionsdialog.ui \
    searchdialog.ui

OTHER_FILES += \
    ../doc/release.txt

TRANSLATIONS += \
    translations/qhexedit_cs.ts \
    translations/qhexedit_de.ts
