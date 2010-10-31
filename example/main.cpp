#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(hexedit);
    QApplication app(argc, argv);
    app.setApplicationName("Hexedit");
    app.setOrganizationName("QHexEdit");
    MainWindow *mainWin = new MainWindow;
    mainWin->show();
    return app.exec();
}
