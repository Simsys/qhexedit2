#include <QApplication>

#include "mainwindow.h"
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(qhexedit);
    QApplication app(argc, argv);
    app.setApplicationName("QHexEdit");
    app.setOrganizationName("QHexEdit");

    // Identify locale and load translation if available
    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString("qhexedit_") + locale);
    app.installTranslator(&translator);

    MainWindow *mainWin = new MainWindow;

    // Parsing the command line parameters
    QCommandLineParser parser;
    parser.setApplicationDescription(
       QApplication::translate(
          "QApplication",
          "The QHexEdit example is a short Demo of the QHexEdit Widget.")
       );
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("file", "The file to open.");
    parser.process(app);

    // Determining if any file was specified in the command line
    QString filename = parser.positionalArguments().value(0);
    if (filename.length()) {
        QDir appDir(QApplication::applicationDirPath());
        filename = appDir.absoluteFilePath(filename);
        mainWin->loadFileWrapper(filename);
    }

    mainWin->show();

    return app.exec();
}
