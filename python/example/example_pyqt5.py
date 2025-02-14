import sys

from PyQt5 import QtWidgets
    
from QHexEdit import QHexEdit


class HexEdit(QHexEdit):

    def __init__(self):
        super(HexEdit, self).__init__()
        file = open(__file__, 'rb')
        data = file.read()
        self.setData(data)
        self.setReadOnly(False)

        
if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    mainWin = HexEdit()
    mainWin.resize(600, 400)
    mainWin.move(300, 300)
    mainWin.show()
    sys.exit(app.exec())

