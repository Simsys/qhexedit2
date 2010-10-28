
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../src/qhexedit.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
QT_END_NAMESPACE

//! [class definition with macro]
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
//! [class definition with macro]
    MainWindow(const QString &fileName);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void open();
    bool save();
    bool saveAs();
    void about();
    void setAddress(int address);

private:
    void init();
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    MainWindow *findMainWindow(const QString &fileName);

    bool isUntitled;

    QHexEdit *hexEdit;
    QString curFile;
    QLabel *lbAddress;
    QSpinBox *sbAddressWidth;
    QCheckBox *cbAddressArea;
    QCheckBox *cbAsciiArea;
    QCheckBox *cbOverwriteMode;
    QCheckBox *cbHighlighting;

    QMenu *fileMenu;
    QMenu *helpMenu;

    QToolBar *fileToolBar;
    QToolBar *editToolBar;

    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *closeAct;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
};

#endif
