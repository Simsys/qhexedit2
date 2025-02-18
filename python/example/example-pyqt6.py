import sys, os

from PyQt6 import QtWidgets, QtCore, QtGui
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
        self.openAct = QtGui.QAction(QtGui.QIcon(':/images/open.png'),
                "&Open...", self, shortcut=QtGui.QKeySequence.StandardKey.Open,
                statusTip="Open an existing file", triggered=self.open)

        self.saveAct = QtGui.QAction(QtGui.QIcon(':/images/save.png'),
                "&Save", self, shortcut=QtGui.QKeySequence.StandardKey.Save,
                statusTip="Save the document to disk", triggered=self.save)

        self.saveAsAct = QtGui.QAction("Save &As...", self,
                shortcut=QtGui.QKeySequence.StandardKey.SaveAs,
                statusTip="Save the document under a new name", triggered=self.saveAs)
        
        self.saveReadable = QtGui.QAction("Save as &Readable...", self,
                statusTip="Save in a readable format", triggered=self.saveToReadableFile)

        self.exitAct = QtGui.QAction("E&xit", self, shortcut="Ctrl+Q",
                statusTip="Exit the application", triggered=self.close)
        
        self.undoAct = QtGui.QAction(QtGui.QIcon(':/images/undo.png'),
                "&Undo", self, shortcut=QtGui.QKeySequence.StandardKey.Undo, triggered=self.hexEdit.undo)
                
        self.redoAct = QtGui.QAction(QtGui.QIcon(':/images/redo.png'), 
                "&Redo", self, shortcut=QtGui.QKeySequence.StandardKey.Redo, triggered=self.hexEdit.redo)
        
        self.saveSelectionReadable = QtGui.QAction("Save Selection Readable...", self,
                statusTip="Save selection in a readable format",
                triggered=self.saveSelectionToReadableFile)
        
        self.aboutAct = QtGui.QAction("&About", self,
                statusTip="Show the application's About box", triggered=self.about)
                
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
        self.lbAddress.setFrameShape(QtWidgets.QFrame.Shape.Panel)
        self.lbAddress.setFrameShadow(QtWidgets.QFrame.Shadow.Sunken)
        self.lbAddress.setMinimumWidth(70)
        self.statusBar().addPermanentWidget(self.lbAddress)
        self.hexEdit.currentAddressChanged.connect(self.setAddress)
        
        # Address Size
        self.lbSizeName = QtWidgets.QLabel()
        self.lbSizeName.setText("Size:")
        self.statusBar().addPermanentWidget(self.lbSizeName)
        self.lbSize = QtWidgets.QLabel()
        self.lbSize.setFrameShape(QtWidgets.QFrame.Shape.Panel)
        self.lbSize.setFrameShadow(QtWidgets.QFrame.Shadow.Sunken)
        self.lbSize.setMinimumWidth(70)
        self.statusBar().addPermanentWidget(self.lbSize)
        self.hexEdit.currentSizeChanged.connect(self.setSize)
        
        # Overwrite Mode label
        self.lbOverwriteModeName = QtWidgets.QLabel()
        self.lbOverwriteModeName.setText("Mode:")
        self.statusBar().addPermanentWidget(self.lbOverwriteModeName)
        self.lbOverwriteMode = QtWidgets.QLabel()
        self.lbOverwriteMode.setFrameShape(QtWidgets.QFrame.Shape.Panel)
        self.lbOverwriteMode.setFrameShadow(QtWidgets.QFrame.Shadow.Sunken)
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
        self.setAttribute(QtCore.Qt.WidgetAttribute.WA_DeleteOnClose)
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
        QtWidgets.QApplication.setOverrideCursor(QtCore.Qt.CursorShape.WaitCursor)
        with open(fileName, 'rb') as f:
            self.hexEdit.setData(f.read())
        QtWidgets.QApplication.restoreOverrideCursor()

        self.setCurrentFile(fileName)
        self.statusBar().showMessage("File loaded", 2000)

    def open(self):
        fileName, _filter = QtWidgets.QFileDialog.getOpenFileName(self)
        if fileName:
            self.loadFile(fileName)

    def readSettings(self):
        settings = QtCore.QSettings()

        pos = settings.value('pos', QtCore.QPoint(200, 200))
        size = settings.value('size', QtCore.QSize(610, 460))
        self.move(pos)
        self.resize(size)

    def save(self):
        if self.isUntitled:
            self.saveAs()
        else:
            self.saveFile(self.curFile)

    def saveAs(self):
        fileName, _filter = QtWidgets.QFileDialog.getSaveFileName(self, "Save As", self.curFile)
        if fileName != "":
            self.saveFile(fileName)

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
        QtWidgets.QApplication.setOverrideCursor(QtCore.Qt.CursorShape.WaitCursor)
        with open(fileName, 'wb') as f:
            f.write(self.hexEdit.data())
        QtWidgets.QApplication.restoreOverrideCursor()

        self.setCurrentFile(fileName)
        self.statusBar().showMessage("File saved", 2000)
    
    def saveToReadableFile(self):
        fileName, _filter = QtWidgets.QFileDialog.getSaveFileName(self, "Save To Readable File")
        if fileName != "":
            QtWidgets.QApplication.setOverrideCursor(QtCore.Qt.CursorShape.WaitCursor)
            with open(fileName, "w") as f:
                f.write(self.hexEdit.toReadableString())
            QtWidgets.QApplication.restoreOverrideCursor()
            self.statusBar().showMessage("File saved", 2000);

    def saveSelectionToReadableFile(self):
        fileName, _filter = QtWidgets.QFileDialog.getSaveFileName(self, "Save To Readable File")
        if fileName != "":
            QtWidgets.QApplication.setOverrideCursor(QtCore.Qt.CursorShape.WaitCursor)
            with open(fileName, 'w') as f:
                f.write(self.hexEdit.selectionToReadableString())
            QtWidgets.QApplication.restoreOverrideCursor()
            self.statusBar().showMessage("File saved", 2000);

    def setCurrentFile(self, fileName):
        self.curFile = fileName
        self.isUntitled = (fileName == "")
        self.setWindowModified(False)
        basename = os.path.basename(self.curFile)
        self.setWindowTitle("%s[*] - QHexEdit" % basename)

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
