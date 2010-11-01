#!/usr/bin/env python

from PyQt4 import QtCore, QtGui

from Ui_optionsdialog import Ui_OptionsDialog


class OptionsDialog(QtGui.QDialog):
    accepted = QtCore.pyqtSignal()

    def __init__(self, fileName=None):
        super(OptionsDialog, self).__init__()
        self.ui = Ui_OptionsDialog()
        self.ui.setupUi(self)
        self.ui.pbHighlightingColor.clicked.connect(self.onPbHighlightingColor)
        self.ui.pbAddressAreaColor.clicked.connect(self.onPbAddressAreaColor)
        self.ui.pbWidgetFont.clicked.connect(self.onPbWidgetFont)
        
        self.readSettings()
        self.writeSettings()
        
    def accept(self):
        self.writeSettings()
        self.accepted.emit()
        super(OptionsDialog, self).hide()
        
    def readSettings(self):
        settings = QtCore.QSettings()
        
        self.ui.cbAddressArea.setChecked(settings.value("AddressArea", True).toBool())
        self.ui.cbAsciiArea.setChecked(settings.value("AsciiArea", True).toBool())
        self.ui.cbHighlighting.setChecked(settings.value("Highlighting", True).toBool())
        self.ui.cbOverwriteMode.setChecked(settings.value("OverwriteMode", True).toBool())
        
        self.setPbHighlightingColor(QtGui.QColor(settings.value("HighlightingColor", QtGui.QColor(QtCore.Qt.yellow).lighter(160))));
        self.setPbAddressAreaColor(QtGui.QColor(settings.value("AddressAreaColor", QtGui.QColor(QtCore.Qt.lightGray).lighter(110))));
        self.ui.leWidgetFont.setFont(QtGui.QFont(settings.value("WidgetFont", QtGui.QFont(QtGui.QFont("Courier New", 10)))))
        
        self.ui.sbAddressAreaWidth.setValue(settings.value("AddressAreaWidth", 4).toInt()[0])
        
    def writeSettings(self):
        settings = QtCore.QSettings()
        settings.setValue("AddressArea", self.ui.cbAddressArea.isChecked())
        settings.setValue("AsciiArea", self.ui.cbAsciiArea.isChecked())
        settings.setValue("Highlighting", self.ui.cbHighlighting.isChecked())
        settings.setValue("OverwriteMode", self.ui.cbOverwriteMode.isChecked())
        
        settings.setValue("HighlightingColor", self.ui.lbHighlightingColor.palette().color(QtGui.QPalette.Background))
        settings.setValue("AddressAreaColor", self.ui.lbAddressAreaColor.palette().color(QtGui.QPalette.Background))
        settings.setValue("WidgetFont", self.ui.leWidgetFont.font())
        
        settings.setValue("AddressAreaWidth", self.ui.sbAddressAreaWidth.value())
        
    def reject(self):
        super(OptionsDialog, self).hide()
        
    def setPbHighlightingColor(self, color):
        palette = self.ui.lbHighlightingColor.palette()
        palette.setColor(QtGui.QPalette.Background, color)
        self.ui.lbHighlightingColor.setPalette(palette)
        self.ui.lbHighlightingColor.setAutoFillBackground(True)

    def setPbAddressAreaColor(self, color):
        palette = self.ui.lbAddressAreaColor.palette()
        palette.setColor(QtGui.QPalette.Background, color)
        self.ui.lbAddressAreaColor.setPalette(palette)
        self.ui.lbAddressAreaColor.setAutoFillBackground(True)
        
    def onPbHighlightingColor(self):
        color = QtGui.QColorDialog.getColor(self.ui.lbHighlightingColor.palette().color(QtGui.QPalette.Background), self)
        self.setPbHighlightingColor(color)
        
    def onPbAddressAreaColor(self):
        color = QtGui.QColorDialog.getColor(self.ui.lbAddressAreaColor.palette().color(QtGui.QPalette.Background), self)
        self.setPbAddressAreaColor(color)
        
    def onPbWidgetFont(self):
        font, ok = QtGui.QFontDialog().getFont(self.ui.leWidgetFont.font(), self)
        if ok:
            self.ui.leWidgetFont.setFont(font)
