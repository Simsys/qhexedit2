#!/usr/bin/env python


# This is only needed for Python v2 but is harmless for Python v3.
import sip
sip.setapi('QVariant', 2)

from PyQt4 import QtCore, QtGui
from qhexedit import QHexEdit

import qhexedit_rc


class MainWindow(QtGui.QMainWindow):

    def __init__(self, fileName=None):
        super(MainWindow, self).__init__()
        self.setCurrentFile('')
        self.init()

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
        fileName = QtGui.QFileDialog.getSaveFileName(self, "Save As",
                self.curFile)
        if not fileName:
            return False

        return self.saveFile(fileName)

    def init(self):
        self.isUntitled = True
        self.hexEdit = QHexEdit()
        self.setCentralWidget(self.hexEdit)

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
                statusTip="Save the document under a new name",
                triggered=self.saveAs)

        self.closeAct = QtGui.QAction("&Close", self, shortcut="Ctrl+W",
                statusTip="Close this window", triggered=self.close)

        self.exitAct = QtGui.QAction("E&xit", self, shortcut="Ctrl+Q",
                statusTip="Exit the application",
                triggered=self.exit)
                
    def createMenus(self):
        self.fileMenu = self.menuBar().addMenu("&File")
        self.fileMenu.addAction(self.openAct)
        self.fileMenu.addAction(self.saveAct)
        self.fileMenu.addAction(self.saveAsAct)
        self.fileMenu.addSeparator()
        self.fileMenu.addAction(self.closeAct)
        self.fileMenu.addAction(self.exitAct)
        
    def createToolBars(self):
        self.fileToolBar = self.addToolBar("File")
        self.fileToolBar.addAction(self.openAct)
        self.fileToolBar.addAction(self.saveAct)

    def createStatusBar(self):
        self.statusBar().showMessage("Ready")

        self.cbOverwriteMode = QtGui.QCheckBox();
        self.cbOverwriteMode.setText("Overwrite Mode");
        self.cbOverwriteMode.setChecked(QtCore.Qt.Checked);
        self.statusBar().addPermanentWidget(self.cbOverwriteMode);
        self.cbOverwriteMode.toggled.connect(self.hexEdit.setOverwriteMode);


    def readSettings(self):
        settings = QtCore.QSettings('QHexEdit', 'Example')
        pos = settings.value('pos', QtCore.QPoint(200, 200))
        size = settings.value('size', QtCore.QSize(400, 400))
        self.move(pos)
        self.resize(size)

    def writeSettings(self):
        settings = QtCore.QSettings('QHexEdit', 'Example')
        settings.setValue('pos', self.pos())
        settings.setValue('size', self.size())
        
    def exit(self):
        self.writeSettings()
        self.close()

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

    def saveFile(self, fileName):
        file = QtCore.QFile(fileName)
        if not file.open( QtCore.QFile.WriteOnly | QtCore.QFile.Text):
            QtGui.QMessageBox.warning(self, "QHexEdit",
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
        self.setWindowModified(False)
        self.setWindowTitle("%s[*] - QHexEdit" % self.strippedName(self.curFile))

    def strippedName(self, fullFileName):
        return QtCore.QFileInfo(fullFileName).fileName()

if __name__ == '__main__':

    import sys

    app = QtGui.QApplication(sys.argv)
    mainWin = MainWindow()
    mainWin.show()
    sys.exit(app.exec_())
