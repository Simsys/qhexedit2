# A demonstration custom widget plugin for Qt Designer.
# 
# Copyright (c) 2007 Phil Thompson


from PyQt4 import QtGui, QtDesigner

from qhexedit import QHexEdit


# This class implements the interface expected by Qt Designer to access the
# custom widget.  See the description of the QDesignerCustomWidgetInterface
# class for full details.
class QHexEditPlugin(QtDesigner.QPyDesignerCustomWidgetPlugin):

    # Initialise the instance.
    def __init__(self, parent=None):
        super(QHexEditPlugin, self).__init__(parent)

        self._initialized = False

    # Initialise the custom widget for use with the specified formEditor
    # interface.
    def initialize(self, formEditor):
        if self._initialized:
            return

        self._initialized = True

    # Return True if the custom widget has been intialised.
    def isInitialized(self):
        return self._initialized

    # Return a new instance of the custom widget with the given parent.
    def createWidget(self, parent):
        he = QHexEdit(parent)
        he.setMinimumSize(100, 100)
        return he

    # Return the name of the class that implements the custom widget.
    def name(self):
#        return "QHexEdit"
        return "QHexEdit"

    # Return the name of the group to which the custom widget belongs.  A new
    # group will be created if it doesn't already exist.
    def group(self):
        return "Python Widgets"

    # Return the icon used to represent the custom widget in Designer's widget
    # box.
    def icon(self):
        return QtGui.QIcon(_logo_pixmap)

    # Return a short description of the custom widget used by Designer in a
    # tool tip.
    def toolTip(self):
        return "A simple Hex Editor"

    # Return a full description of the custom widget used by Designer in
    # "What's This?" help for the widget.
    def whatsThis(self):
        return "QHexEdit is a simple Hexeditor. " \
               "You can show end edit binary data."

    # Return True if the custom widget acts as a container for other widgets.
    def isContainer(self):
        return False

    # Return an XML fragment that allows the default values of the custom
    # widget's properties to be overridden.
    def domXml(self):
        return '<widget class="QHexEdit" name="hexEdit">\n' \
               ' <property name="toolTip" >\n' \
               '  <string>A Simple Hex Editor</string>\n' \
               ' </property>\n' \
               ' <property name="whatsThis" >\n' \
               '  <string>QHexEdit is a simple Hexeditor. ' \
               '  You can show end edit binary data.' \
               '  </string>\n' \
               ' </property>\n' \
               '</widget>\n'

    # Return the name of the module containing the class that implements the
    # custom widget.  It may include a module path.
    def includeFile(self):
        return "qhexedit"


# Define the image used for the icon.
_logo_xpm = [
"32 32 52 1",
" 	c None",
".	c #414141",
"+	c #3E3E3E",
"@	c #404040",
"#	c #F4F4F4",
"$	c #F3F3F3",
"%	c #F2F2F2",
"&	c #F1F1F1",
"*	c #F0F0F0",
"=	c #EFEFEF",
"-	c #EEEEEE",
";	c #EDEDED",
">	c #EEEFEE",
",	c #EBEBEB",
"'	c #ECECEC",
")	c #EAEBEA",
"!	c #EAEAEA",
"~	c #E9E9E9",
"{	c #E8E8E8",
"]	c #E7E7E7",
"^	c #000000",
"/	c #E5E7E5",
"(	c #E5E5E5",
"_	c #E4E4E4",
":	c #E3E3E3",
"<	c #E2E2E2",
"[	c #E1E1E1",
"}	c #E0E0E0",
"|	c #DFDFDF",
"1	c #DEDEDE",
"2	c #DCDDDC",
"3	c #DDDDDD",
"4	c #DCDCDC",
"5	c #DBDBDB",
"6	c #DADADA",
"7	c #D9D9D9",
"8	c #D8D9D8",
"9	c #D8D8D8",
"0	c #D7D7D7",
"a	c #D6D6D6",
"b	c #D5D5D5",
"c	c #D4D4D4",
"d	c #D3D4D3",
"e	c #D3D3D3",
"f	c #D2D2D2",
"g	c #D0D0D0",
"h	c #D1D1D1",
"i	c #CFCFCF",
"j	c #CECFCE",
"k	c #CECECE",
"l	c #CDCDCD",
"m	c #030303",
"                                ",
"                                ",
"                  .+@@..+@@     ",
"     ##############$%%&*=-;     ",
"     #############%%&*=>-;,     ",
"     ###########$%%*=>-;',)     ",
"     #########$%%&*=-;',)!~     ",
"     ########%%&*=>-;,)!~{]     ",
"     #########$%%&*=-;',)!~     ",
"     ######^^%%&*=>^^,)!~{]     ",
"     ######^^%*=>-;^^)~{]/(     ",
"     ####$%^^*=-;',^^~{/(_:     ",
"     ###%%&^^>-;,)!^^]/_:<[     ",
"     #$%%*=^^;',)~{^^(_:[[}     ",
"     %%&*=-^^^^^^^^^^:<[[|1     ",
"     &*=>-;^^^^^^^^^^[[}|12     ",
"     =>-;',^^{]/(_:^^}|1324     ",
"     -;',)!^^/(_:<[^^132456     ",
"     ;,)!~{^^_:<[[}^^245678     ",
"     ,)~{]/^^:[[}|1^^467890     ",
"     !~{/(_^^[[|132^^6790ab     ",
"     {]/_:<^^}|1245^^890bcd     ",
"     /(_:[[}|132467890abcef     ",
"     _:<[[|132456790abcdefg     ",
"     <[[}|124567890bcdefhgi     ",
"     [}|132467890abcefhgijk     ",
"     |132456790abcdefgijkll     ",
"     124567890bcdefhgikllll     ",
"     mmmmmmmmmmmmmmmmmmmmmm     ",
"                                ",
"                                ",
"                                "]

_logo_pixmap = QtGui.QPixmap(_logo_xpm)

