#include <optional>
#include <QApplication>
#include <QCommandLineParser>
#include <QFile>
#include <QIcon>
#include <QLocale>
#include <QTranslator>

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

    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString("qhexedit_") + locale);
    app.installTranslator(&translator);

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
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
            Q_UNREACHABLE_RETURN(0);
#else
            Q_UNREACHABLE();
            return 0;
#endif
        case Status::HelpRequested:
            parser.showHelp();
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
            Q_UNREACHABLE_RETURN(0);
#else
            Q_UNREACHABLE();
            return 0;
#endif
    }

    if (query.hasFile)
        mainWin->loadFile(query.file);

    mainWin->show();

    return app.exec();
}
