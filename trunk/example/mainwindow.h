#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../src/qhexedit.h"
#include "optionsdialog.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QUndoStack;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    MainWindow(const QString &fileName);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void about();
    void open();
    bool save();
    bool saveAs();
    void saveToReadableFile();
    void saveSelectionToReadableFile();
    void setAddress(int address);
    void setOverwriteMode(bool mode);
    void setSize(int size);
    void showOptionsDialog();

private slots:
    void optionsAccepted();

private:
    void init();
    void createActions();
    void createMenus();
    void createStatusBar();
    void createToolBars();
    void loadFile(const QString &fileName);
    void readSettings();
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    void writeSettings();

    QString curFile;
    bool isUntitled;
    
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;

    QToolBar *fileToolBar;

    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *saveReadable;
    QAction *closeAct;
    QAction *exitAct;

    QAction *undoAct;
    QAction *redoAct;
    QAction *saveSelectionReadable;

    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *optionsAct;

    QHexEdit *hexEdit;
    OptionsDialog *optionsDialog;
    QLabel *lbAddress, *lbAddressName;
    QLabel *lbOverwriteMode, *lbOverwriteModeName;
    QLabel *lbSize, *lbSizeName;
};

#endif
