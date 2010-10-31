#!/usr/bin/env python

from PyQt4 import QtCore, QtGui
from qhexedit import QHexEdit

from optionsdialog import OptionsDialog
import qhexedit_rc


class MainWindow(QtGui.QMainWindow):

    def __init__(self, fileName=None):
        super(MainWindow, self).__init__()
        self.init()
        self.setCurrentFile('')
        
    def about(self):
        QtGui.QMessageBox.about(self, "About HexEdit",
            "The HexEdit example is a short Demo of the QHexEdit Widget.");

    def open(self):
        fileName = QtGui.QFileDialog.getOpenFileName(self)
        if fileName:
            self.loadFile(fileName)

    def save(self):
        if self.isUntitled:
            return self.saveAs()
        else:
            return self.saveFile(self.curFile)

    def saveAs(self):
        fileName = QtGui.QFileDialog.getSaveFileName(self, "Save As", self.curFile)
        if not fileName:
            return False
        return self.saveFile(fileName)
        
    def setAddress(self, address):
        self.lbAddress.setText('%04x' % address)
        
    def setOverwriteMode(self, mode):
        if mode:
            self.lbOverwriteMode.setText("Overwrite")
        else:
            self.lbOverwriteMode.setText("Insert")
            
    def showOptionsDialog(self):
        self.optionsDialog.show()

    def init(self):
        self.setAttribute(QtCore.Qt.WA_DeleteOnClose)
        self.optionsDialog = OptionsDialog(self)
        self.optionsDialog.accepted.connect(self.readSettings)
        
        self.isUntitled = True
        
        self.hexEdit = QHexEdit()
        self.setCentralWidget(self.hexEdit)
        self.hexEdit.overwriteModeChanged.connect(self.setOverwriteMode)

        self.createActions()
        self.createMenus()
        self.createToolBars()
        self.createStatusBar()

        self.readSettings()

    def createActions(self):
        self.openAct = QtGui.QAction(QtGui.QIcon(':/images/open.png'),
                "&Open...", self, shortcut=QtGui.QKeySequence.Open,
                statusTip="Open an existing file", triggered=self.open)

        self.saveAct = QtGui.QAction(QtGui.QIcon(':/images/save.png'),
                "&Save", self, shortcut=QtGui.QKeySequence.Save,
                statusTip="Save the document to disk", triggered=self.save)

        self.saveAsAct = QtGui.QAction("Save &As...", self,
                shortcut=QtGui.QKeySequence.SaveAs,
                statusTip="Save the document under a new name", triggered=self.saveAs)

        self.closeAct = QtGui.QAction("&Close", self, shortcut="Ctrl+W",
                statusTip="Close this window", triggered=self.close)

        self.exitAct = QtGui.QAction("E&xit", self, shortcut="Ctrl+Q",
                statusTip="Exit the application", triggered=self.close)
                
        self.aboutAct = QtGui.QAction("&About", self,
                statusTip="Show the application's About box", triggered=self.about)
                
        self.optionsAct = QtGui.QAction("&Options", self,
                statusTip="Show the options dialog", triggered=self.showOptionsDialog)

    def createMenus(self):
        self.fileMenu = self.menuBar().addMenu("&File")
        self.fileMenu.addAction(self.openAct)
        self.fileMenu.addAction(self.saveAct)
        self.fileMenu.addAction(self.saveAsAct)
        self.fileMenu.addSeparator()
        self.fileMenu.addAction(self.closeAct)
        self.fileMenu.addAction(self.exitAct)
        
        self.helpMenu = self.menuBar().addMenu("&Help")
        self.helpMenu.addAction(self.aboutAct)
        self.helpMenu.addAction(self.optionsAct)
        
    def createStatusBar(self):
        self.lbAddress = QtGui.QLabel()
        self.lbAddress.setFrameShape(QtGui.QFrame.Panel)
        self.lbAddress.setFrameShadow(QtGui.QFrame.Sunken)
        self.statusBar().addPermanentWidget(self.lbAddress)
        self.hexEdit.currentAddress.connect(self.setAddress)
        
        self.lbOverwriteMode = QtGui.QLabel()
        self.lbOverwriteMode.setFrameShape(QtGui.QFrame.Panel)
        self.lbOverwriteMode.setFrameShadow(QtGui.QFrame.Sunken)
        self.statusBar().addPermanentWidget(self.lbOverwriteMode)
        self.setOverwriteMode(self.hexEdit.overwriteMode())

        self.statusBar().showMessage("Ready")
        
    def createToolBars(self):
        self.fileToolBar = self.addToolBar("File")
        self.fileToolBar.addAction(self.openAct)
        self.fileToolBar.addAction(self.saveAct)

    def loadFile(self, fileName):
        file = QtCore.QFile(fileName)
        if not file.open( QtCore.QFile.ReadOnly | QtCore.QFile.Text):
            QtGui.QMessageBox.warning(self, "QHexEdit",
                    "Cannot read file %s:\n%s." % (fileName, file.errorString()))
            return

        QtGui.QApplication.setOverrideCursor(QtCore.Qt.WaitCursor)
        self.hexEdit.setData(file.readAll())
        QtGui.QApplication.restoreOverrideCursor()

        self.setCurrentFile(fileName)
        self.statusBar().showMessage("File loaded", 2000)

    def readSettings(self):
        settings = QtCore.QSettings()
        pos = settings.value('pos', QtCore.QPoint(200, 200)).toPoint()
        size = settings.value('size', QtCore.QSize(610, 460)).toSize()
        self.move(pos)
        self.resize(size)
        
        self.hexEdit.setAddressArea(settings.value("AddressArea").toBool())
        self.hexEdit.setAsciiArea(settings.value("AsciiArea").toBool());
        self.hexEdit.setHighlighting(settings.value("Highlighting").toBool());
        self.hexEdit.setOverwriteMode(settings.value("OverwriteMode").toBool());

        self.hexEdit.setHighlightingColor(QtGui.QColor(settings.value("HighlightingColor")));
        self.hexEdit.setAddressAreaColor(QtGui.QColor(settings.value("AddressAreaColor")));

        self.hexEdit.setAddressWidth(settings.value("AddressAreaWidth").toInt()[0]);

    def closeEvent(self, event):
        self.writeSettings()
        del self.optionsDialog
        self.close()

    def saveFile(self, fileName):
        file = QtCore.QFile(fileName)
        if not file.open( QtCore.QFile.WriteOnly | QtCore.QFile.Text):
            QtGui.QMessageBox.warning(self, "HexEdit",
                    "Cannot write file %s:\n%s." % (fileName, file.errorString()))
            return False

        QtGui.QApplication.setOverrideCursor(QtCore.Qt.WaitCursor)
        file.write(self.hexEdit.data())
        QtGui.QApplication.restoreOverrideCursor()

        self.setCurrentFile(fileName)
        self.statusBar().showMessage("File saved", 2000)
        return True

    def setCurrentFile(self, fileName):
        self.curFile = fileName
        self.isUntitled = (fileName == "")
        self.setWindowModified(False)
        self.setWindowTitle("%s[*] - QHexEdit" % self.strippedName(self.curFile))

    def strippedName(self, fullFileName):
        return QtCore.QFileInfo(fullFileName).fileName()

    def writeSettings(self):
        settings = QtCore.QSettings()
        settings.setValue('pos', self.pos())
        settings.setValue('size', self.size())
        
if __name__ == '__main__':

    import sys

    app = QtGui.QApplication(sys.argv)
    app.setApplicationName("Hexedit");
    app.setOrganizationName("QHexEdit");
    mainWin = MainWindow()
    mainWin.show()
    sys.exit(app.exec_())
