#include <QApplication>

#include "mainwindow.h"
#include <QCommandLineParser>

//Sync this version with the widget one is a good idea probably
#define QHEXEDIT_VERSION "0.7.8"

int main(int argc, char *argv[])
{

    Q_INIT_RESOURCE(qhexedit);
    QApplication app(argc, argv);
    app.setApplicationName("QHexEdit");
    app.setOrganizationName("QHexEdit");
    app.setApplicationVersion(QHEXEDIT_VERSION);

    QDir appDir = QApplication::applicationDirPath();

    // Identify locale and load translation if available
    QSettings settings;
    QString localeFromSettings = settings.value("Language","DEFAULT").toString();
    QString effectiveLocale;

    if  (localeFromSettings.compare("DEFAULT") == 0)
    {
        effectiveLocale = QLocale::system().name();
    } else
    {
        effectiveLocale = localeFromSettings;
    }

    QTranslator translator;
    translator.load(appDir.absoluteFilePath(QString("qhexedit_") + effectiveLocale));
    app.installTranslator(&translator);

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

    MainWindow *mainWin = new MainWindow;

    // Determining if any file was specified in the command line
    QString filename = parser.positionalArguments().value(0);
    if (filename.length())
    {
        filename = appDir.absoluteFilePath(filename);
        mainWin->loadFileWrapper(filename);
    }

    mainWin->show();

    return app.exec();
}
