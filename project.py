"""The build configuration file for QHexEdit, used by sip."""

import os
from os.path import abspath, join
from sipbuild import Option
from pyqtbuild import PyQtBindings, PyQtProject
import PyQt5


class QHexEditProject(PyQtProject):
    """The QHexEdit Project class."""

    def __init__(self):
        super().__init__()
        self.bindings_factories = [QHexEditBindings]

    def update(self, tool):
        """Allows SIP to find PyQt5 .sip files."""
        super().update(tool)
        self.sip_include_dirs.append(join(PyQt5.__path__[0], 'bindings'))


class QHexEditBindings(PyQtBindings):
    """The QHexEdit Bindings class."""

    def __init__(self, project):
        super().__init__(project, name='QHexEdit',
                         sip_file='qhexedit.sip',
                         qmake_QT=['widgets'])
