import sys

from PyQt5 import QtWidgets, QtCore, QtGui
from QHexEdit import QHexEdit

import qhexedit_rc


class MainWindow(QtWidgets.QMainWindow):

    def __init__(self, fileName=None):
        super(MainWindow, self).__init__()
        self.init()
        self.setCurrentFile('')
        
    def about(self):
        QtWidgets.QMessageBox.about(self, "About HexEdit",
            "The HexEdit example is a short Demo of the QHexEdit Widget.");

    def closeEvent(self, event):
        self.writeSettings()
        self.close()

    def createActions(self):
        self.openAct = QtWidgets.QAction(QtGui.QIcon(':/images/open.png'),
                "&Open...", self, shortcut=QtGui.QKeySequence.Open,
                statusTip="Open an existing file", triggered=self.open)

        self.saveAct = QtWidgets.QAction(QtGui.QIcon(':/images/save.png'),
                "&Save", self, shortcut=QtGui.QKeySequence.Save,
                statusTip="Save the document to disk", triggered=self.save)

        self.saveAsAct = QtWidgets.QAction("Save &As...", self,
                shortcut=QtGui.QKeySequence.SaveAs,
                statusTip="Save the document under a new name", triggered=self.saveAs)
        
        self.saveReadable = QtWidgets.QAction("Save as &Readable...", self,
                statusTip="Save in a readable format", triggered=self.saveToReadableFile)

        self.exitAct = QtWidgets.QAction("E&xit", self, shortcut="Ctrl+Q",
                statusTip="Exit the application", triggered=self.close)
        
        self.undoAct = QtWidgets.QAction(QtGui.QIcon(':/images/undo.png'),
                "&Undo", self, shortcut=QtGui.QKeySequence.Undo, triggered=self.hexEdit.undo)
                
        self.redoAct = QtWidgets.QAction(QtGui.QIcon(':/images/redo.png'), 
                "&Redo", self, shortcut=QtGui.QKeySequence.Redo, triggered=self.hexEdit.redo)
        
        self.saveSelectionReadable = QtWidgets.QAction("Save Selection Readable...", self,
                statusTip="Save selection in a readable format",
                triggered=self.saveSelectionToReadableFile)
        
        self.aboutAct = QtWidgets.QAction("&About", self,
                statusTip="Show the application's About box", triggered=self.about)
                
        self.findAct = QtWidgets.QAction("&Find/Replace", self, shortcut=QtGui.QKeySequence.Find,
                statusTip="Show the Dialog for finding and replacing", triggered=self.showSearchDialog)

        self.findNextAct = QtWidgets.QAction("Find &next", self, shortcut=QtGui.QKeySequence.FindNext, 
                statusTip="Find next occurrence of the searched pattern", triggered=self.findNext)

        self.optionsAct = QtWidgets.QAction("&Options", self,
                statusTip="Show the options dialog", triggered=self.showOptionsDialog)

    def createMenus(self):
        self.fileMenu = self.menuBar().addMenu("&File")
        self.fileMenu.addAction(self.openAct)
        self.fileMenu.addAction(self.saveAct)
        self.fileMenu.addAction(self.saveAsAct)
        self.fileMenu.addAction(self.saveReadable)
        self.fileMenu.addSeparator()
        self.fileMenu.addAction(self.exitAct)
        
        self.editMenu = self.menuBar().addMenu("&Edit")
        self.editMenu.addAction(self.undoAct)
        self.editMenu.addAction(self.redoAct)
        self.editMenu.addAction(self.saveSelectionReadable)
        
        self.helpMenu = self.menuBar().addMenu("&Help")
        self.helpMenu.addAction(self.aboutAct)
        
    def createStatusBar(self):
        # Address Label
        self.lbAddressName = QtWidgets.QLabel()
        self.lbAddressName.setText("Address:")
        self.statusBar().addPermanentWidget(self.lbAddressName)
        self.lbAddress = QtWidgets.QLabel()
        self.lbAddress.setFrameShape(QtWidgets.QFrame.Panel)
        self.lbAddress.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.lbAddress.setMinimumWidth(70)
        self.statusBar().addPermanentWidget(self.lbAddress)
        self.hexEdit.currentAddressChanged.connect(self.setAddress)
        
        # Address Size
        self.lbSizeName = QtWidgets.QLabel()
        self.lbSizeName.setText("Size:")
        self.statusBar().addPermanentWidget(self.lbSizeName)
        self.lbSize = QtWidgets.QLabel()
        self.lbSize.setFrameShape(QtWidgets.QFrame.Panel)
        self.lbSize.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.lbSize.setMinimumWidth(70)
        self.statusBar().addPermanentWidget(self.lbSize)
        self.hexEdit.currentSizeChanged.connect(self.setSize)
        
        # Overwrite Mode label
        self.lbOverwriteModeName = QtWidgets.QLabel()
        self.lbOverwriteModeName.setText("Mode:")
        self.statusBar().addPermanentWidget(self.lbOverwriteModeName)
        self.lbOverwriteMode = QtWidgets.QLabel()
        self.lbOverwriteMode.setFrameShape(QtWidgets.QFrame.Panel)
        self.lbOverwriteMode.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.lbOverwriteMode.setMinimumWidth(70)
        self.statusBar().addPermanentWidget(self.lbOverwriteMode)
        self.setOverwriteMode(self.hexEdit.overwriteMode())

        self.statusBar().showMessage("Ready")
        
    def createToolBars(self):
        self.fileToolBar = self.addToolBar("File")
        self.fileToolBar.addAction(self.openAct)
        self.fileToolBar.addAction(self.saveAct)
        self.fileToolBar.addAction(self.undoAct)
        self.fileToolBar.addAction(self.redoAct)

    def init(self):
        self.setAttribute(QtCore.Qt.WA_DeleteOnClose)
        self.isUntitled = True
        
        self.hexEdit = QHexEdit()
        self.setCentralWidget(self.hexEdit)
        self.hexEdit.overwriteModeChanged.connect(self.setOverwriteMode)

        self.createActions()
        self.createMenus()
        self.createToolBars()
        self.createStatusBar()

        self.readSettings()

    def loadFile(self, fileName):
        file = QtCore.QFile(fileName)
        if not file.open( QtCore.QFile.ReadOnly | QtCore.QFile.Text):
            QtWidgets.QMessageBox.warning(self, "QHexEdit",
                    "Cannot read file %s:\n%s." % (fileName, file.errorString()))
            return

        QtWidgets.QApplication.setOverrideCursor(QtCore.Qt.WaitCursor)
        self.hexEdit.setData(file.readAll())
        QtWidgets.QApplication.restoreOverrideCursor()

        self.setCurrentFile(fileName)
        self.statusBar().showMessage("File loaded", 2000)

    def open(self):
        fileName, _filter = QtWidgets.QFileDialog.getOpenFileName(self)
        if fileName:
            self.loadFile(fileName)

    def optionsAccepted(self):
        self.writeSettings()
        self.readSettings()
        
    def findNext(self):
        self.searchDialog.findNext()

    def readSettings(self):
        settings = QtCore.QSettings()

        pos = settings.value('pos', QtCore.QPoint(200, 200))
        size = settings.value('size', QtCore.QSize(610, 460))
        self.hexEdit.setAddressArea(settings.value("AddressArea")=='true')
        self.hexEdit.setAsciiArea(settings.value("AsciiArea")=='true')
        self.hexEdit.setHighlighting(settings.value("Highlighting")=='true')
        self.hexEdit.setOverwriteMode(settings.value("OverwriteMode")=='true')
        self.hexEdit.setReadOnly(settings.value("ReadOnly")=='true')

        self.hexEdit.setHighlightingColor(QtGui.QColor(settings.value("HighlightingColor")))
        self.hexEdit.setAddressAreaColor(QtGui.QColor(settings.value("AddressAreaColor")))
        self.hexEdit.setSelectionColor(QtGui.QColor(settings.value("SelectionColor")))
        self.hexEdit.setFont(QtGui.QFont(settings.value("WidgetFont", QtGui.QFont(QtGui.QFont("Courier New", 10)))))

        self.hexEdit.setAddressWidth(int(settings.value("AddressAreaWidth")));
        self.move(pos)
        self.resize(size)

    def save(self):
        if self.isUntitled:
            return self.saveAs()
        else:
            return self.saveFile(self.curFile)

    def saveAs(self):
        fileName, _filter = QtWidgets.QFileDialog.getSaveFileName(self, "Save As", self.curFile)
        if not fileName:
            return False
        return self.saveFile(fileName)

    def showOptionsDialog(self):
        self.optionsDialog.show()
        
    def showSearchDialog(self):
        self.searchDialog.show()
        
    def setAddress(self, address):
        self.lbAddress.setText('%x' % address)
        
    def setOverwriteMode(self, mode):
        settings = QtCore.QSettings()
        settings.setValue("OverwriteMode", mode)
        if mode:
            self.lbOverwriteMode.setText("Overwrite")
        else:
            self.lbOverwriteMode.setText("Insert")
            
    def setSize(self, size):
        self.lbSize.setText('%d' % size)
            
    def saveFile(self, fileName):
        file = QtCore.QFile(fileName)
        if not file.open( QtCore.QFile.WriteOnly | QtCore.QFile.Truncate):
            QtWidgets.QMessageBox.warning(self, "HexEdit",
                    "Cannot write file %s:\n%s." % (fileName, file.errorString()))
            return False

        file.write(self.hexEdit.data())

        self.setCurrentFile(fileName)
        self.statusBar().showMessage("File saved", 2000)
        return True
    
    def saveToReadableFile(self):
        fileName, _filter = QtWidgets.QFileDialog.getSaveFileName(self, "Save To Readable File")
        if fileName != "":
            file = open(str(fileName), "w")
            file.write(str(self.hexEdit.toReadableString()))
            self.statusBar().showMessage("File saved", 2000);

    def saveSelectionToReadableFile(self):
        fileName, _filter = QtWidgets.QFileDialog.getSaveFileName(self, "Save To Readable File")
        if fileName != "":
            file = open(str(fileName), "w")
            file.write(str(self.hexEdit.selectionToReadableString()))
            self.statusBar().showMessage("File saved", 2000);

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
    app = QtWidgets.QApplication(sys.argv)
    app.setApplicationName("QHexEdit");
    app.setOrganizationName("QHexEdit");
    mainWin = MainWindow()
    mainWin.show()
    sys.exit(app.exec())
