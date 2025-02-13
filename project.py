"""The build configuration file for QHexEdit, used by sip."""

import os
from os.path import abspath, join
from sipbuild import Option
from pyqtbuild import PyQtBindings, PyQtProject

try:
    import PyQt6
    PyQt_Version = 'PyQt6'
except ImportError:
    try:
        import PyQt5
        PyQt_Version = 'PyQt5'
    except ImportError:
        try:
            import PyQt4
            PyQt_Version = 'PyQt4'
        except ImportError:
            PyQt_Version = None

if PyQt_Version is None:
    raise ImportError("No compatible PyQt version (PyQt4, PyQt5, or PyQt6) found.")

class QHexEditProject(PyQtProject):
    """The QHexEdit Project class."""

    def __init__(self):
        super().__init__()
        self.bindings_factories = [QHexEditBindings]

    def update(self, tool):
        """Allows SIP to find PyQt .sip files."""
        super().update(tool)
        if PyQt_Version == 'PyQt6':
            self.sip_include_dirs.append(join(PyQt6.__path__[0], 'bindings'))
        elif PyQt_Version == 'PyQt5':
            self.sip_include_dirs.append(join(PyQt5.__path__[0], 'bindings'))
        else:
            # unexpected and not supported here
            raise ValueError(f"Unsupported PyQt version: {PyQt_Version}.")


class QHexEditBindings(PyQtBindings):
    """The QHexEdit Bindings class."""

    def __init__(self, project):
        super().__init__(project, name='QHexEdit',
                         sip_file='qhexedit.sip',
                         qmake_QT=['widgets'])

    def apply_user_defaults(self, tool):
        self.headers.append("src/qhexedit.h")
        self.headers.append("src/chunks.h")
        self.headers.append("src/commands.h")

        self.sources.append("src/qhexedit.cpp")
        self.sources.append("src/chunks.cpp")
        self.sources.append("src/commands.cpp")
        super().apply_user_defaults(tool)
