#include <optional>
#include <QApplication>
#include <QCommandLineParser>
#include <QFile>
#include <QIcon>
#include <QLocale>
#include <QTranslator>
#include <QLibraryInfo>

#include "mainwindow.h"

struct ParsedOptions
{
    bool hasFile = false;
    QString file = "";
};

struct CommandLineParseResult {
    enum class Status {
        Ok,
        Error,
        VersionRequested,
        HelpRequested
    };
    Status statusCode = Status::Ok;
    std::optional<QString> errorString = std::nullopt;
};

CommandLineParseResult parseCommandLine(QCommandLineParser &parser, ParsedOptions *query) {
    using Status = CommandLineParseResult::Status;

    const QCommandLineOption helpOption = parser.addHelpOption();
    const QCommandLineOption versionOption = parser.addVersionOption();
    parser.addPositionalArgument("file", "File to open");

    if (!parser.parse(QCoreApplication::arguments()))
        return { Status::Error, parser.errorText() };

    if (parser.isSet(versionOption))
        return { Status::VersionRequested };

    if (parser.isSet(helpOption))
        return { Status::HelpRequested };

    const QStringList positionalArguments = parser.positionalArguments();
    if (!positionalArguments.isEmpty()) {
        if (positionalArguments.size() > 1)
            return { Status::Error, "Several 'name' arguments specified." };
        query->hasFile = true;
        query->file = positionalArguments.first();
    }

    return { Status::Ok };
}

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(qhexedit);
    QApplication app(argc, argv);

    QCoreApplication::setApplicationName("QHexEdit");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    app.setOrganizationName("QHexEdit");
    app.setWindowIcon(QIcon(":images/qhexedit.ico"));

    QTranslator translator_app;
    if (translator_app.load(QLocale(), "qhexedit", "_", ":/translations"))
        QCoreApplication::installTranslator(&translator_app);

    QTranslator translator_qt;

    #if QT_VERSION < 0x060000
    QString path = QLibraryInfo::location(QLibraryInfo::TranslationsPath);
    #else
    QString path = QLibraryInfo::path(QLibraryInfo::TranslationsPath);
    #endif

    if (translator_qt.load(QLocale(), "qt", "_", path))
        QCoreApplication::installTranslator(&translator_qt);

    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::translate("QHexEdit", "A hex editor application"));

    MainWindow *mainWin = new MainWindow;

    ParsedOptions query;
    using Status = CommandLineParseResult::Status;
    CommandLineParseResult parseResult = parseCommandLine(parser, &query);

    switch (parseResult.statusCode) {
        case Status::Ok:
            break;

        case Status::Error:
            std::fputs(qPrintable(parseResult.errorString.value_or("Unknown error occurred")), stderr);
            std::fputs("\n\n", stderr);
            std::fputs(qPrintable(parser.helpText()), stderr);
            return 1;

        case Status::VersionRequested:
            parser.showVersion();
            return 0;

        case Status::HelpRequested:
            parser.showHelp();
            return 0;
    }

    if (query.hasFile)
        mainWin->loadFile(query.file);

    mainWin->show();

    return app.exec();
}
