Release 0.8.10, 2025-01-08
-------------------------
- Replace QPallete::Background with QPallete::Window (for Qt6)
- Update main.cpp to add version option and future extensibility
- Support the use of SIP5
- Some small improvements- clang detach temporary
- initialize with initialization lists
- open file from cli
- add colors customization

Release 0.8.9, 2020-07-03
-------------------------
- make appveyor upload assets

Release 0.8.8, 2020-06-24
-------------------------
- test appveyor

Release 0.8.7, 2020-06-24
-------------------------
- extend HexCaps check to address and edit text
- use 'monospace' hint to improve font guess
- fix build with qt < 5.11.0
- add icon pics to source
- forward key press events to parent widget
- limit undo stack to 1000 entries

Release 0.8.6, 2019-03-16
-------------------------
- Bug fix: select data above 2GB
- add selectedData() method
- minor changes

Release 0.8.5, 2018-12-12
-------------------------
- Dynamic bytesPerLine property
- Russian translation
- QDesigner plugin
- Bug fixes

Release 0.8.4, 2018-12-12
-------------------------
- Dynamic bytesPerLine property
- Russian translation
- QDesigner plugin
- Bug fixes

Release 0.8.3, 2017-01-09
-------------------------
- Ascii area ist now editable
- New property hexCaps
- Bugfixes
- Translation updates
- Bump lib version to 4.0.0

Release 0.8.2, 2016-12-19
-------------------------
- New feature: Bytes per line is now adjustable
- Fix build for MSVC
- Allow hex input chars 'a'...'f' and 'A'...'F'
- Typos
- Bug fix: Glitch address area background color when view slided left
- Bug fix: Glitch when view slided left and paint event
- Bump lib version to 3.1.0

Release 0.8.1, 2016-11-08
-------------------------
- Bump lib version to 3.0.0

Release 0.8.0, 2016-11-07
-------------------------
- Add copyright and license statement
- Make python example work (binary read)
- setFont() ist not longer 'virtual' (minimal change in lib interface)
- Fix leak memory issue

Release 0.7.8, 2016-08-01
-------------------------
- Adjust include directory for qt5 in setup.py for Ubuntu 16.04
- Initialize values in constructor

Release 0.7.7, 2016-04-14
-------------------------
- Take horizontal scrolling position into account, when calculation cursor
position from graphical (mouse click) position
- Adjust horizontal scrollbar, when the cursor leaves the viewport

Release 0.7.6, 2016-06-07
-------------------------
- Miscalculation of the position of cursor when scrolling horizontally corrected

Release 0.7.5, 2016-04-07
-------------------------
- Cursor position in insert mode (when deleting last byte) corrected
- resetSelection() now clips to max data size
- setSelection() now clips to max data size

Release 0.7.4, 2015-09-17
-------------------------
- Include some get/set functions in the definition of Q_PROPERTY, change lib version to 2.1.0
- Definition of property "data" should mention signal "dataChanged"
- Replace these "and" and "or" with their counterparts "&&" and "||"
- LONG_LONG_MAX should not be used

Release 0.7.3, 2015-06-01
-------------------------
- Get ready for PyQt5
- Use palette colors instead of inventing new colors if possible

Release 0.7.2, 2015-05-19
-------------------------
- Change library version to 2.0.0, because the ABI has incompatible changes

Release 0.7.1, 2015-05-19
-------------------------
- Change library version to 1.1.0, because the ABI has changed 

Release 0.7.0, 2015-05-18
-------------------------
- QHexEdit is now based on QIODevice. The data shown is not buffered in memory. QHexEdit can show now very big files (> 2 gigabytes) without any problems
- QHexEdit has also a QByteArray based, backward compatible (as far as possible) interface for convenience 
- Changes on the data will be stored in copied memory chunks, the base file will only read (QIODevice::ReadOnly)
- QHexEdit is now directly derived from QAbstractScrollArea
- The Widget calculates now all dimensions dynamically, hence small or big fonts will be shown properly on all screens
- You can use also proportional fonts, though it is not recommended
- Paint event needs very low cpu activity, when editor is in idle mode without user actions. Only the section of the data is rendered, which is shown to the user
- Several bugfixes.

Release 0.6.7, 2015-05-11
-------------------------
- Bugfix Ctrl-C does not work properly

Release 0.6.6, 2015-05-01
-------------------------
- Feature Adding drag and drop
- Feature Adding toolbar buttons for undo, redo and find
- Bugfix Selection is allways shown to end of file

Release 0.6.5, 2015-04-16
-------------------------
- Feature Python Example ready for Python 2 and 3
- Bugfix Handling overwriteMode Flag

Release 0.6.4, 2015-04-09
-------------------------
- Feature Ready for Qt5
- Feature Show Selection in ASCII Part
- Bugfix Selecting last item in a row
- Bugfix Scroll Bar not shown when extra data inserted
- Bugfix address area doesn't update when changed ouside
- Bugfix Error while saving (Example)
    
Release 0.6.3, 2012-01-28
-------------------------
- Searching and replacing included (indexOf(), lastIndexOf(), replace())
- Example ist now named consequently "QHexEdit"
- Example reflects the search/replace functionality
- Translateions (cs, de) for the example are contained
- Python bindings include also the new features
- Paython example is also updated

Release 0.6.2, 2012-01-21
-------------------------
- Fix issue #4 "Hiding the ascii area doesn't resize the widget properly"
- Fix issue #5 "Blinking cursor is displayed even if the control is set to read only"

Release 0.6.1, 2011-10-22
-------------------------
- Fix issue #2 "setData() steals focus"
- Fix issue #3 "QHexEdit crashes, when hitting Backspace on the first Byte"

Release 0.6.0, 2011-10-03
-------------------------
- Undo/Redo functioinality
- toReadableString(), selectionToReadableString() added
- New structure, new classes XByteArray, CharCommands, ArrayCommands
- C++ and Python example reflect the new features

Release 0.5.4, 2011-08-31
-------------------------
- New Feature: Property font
- Python Example is now identical to C++ Example
- Windows and Linux build scripts added

Release 0.5.3, 2011-08-29
-------------------------
- BugFix: recursive call in "qhexedit.cpp" addressOffset()
- New Feature: Property readOnly

Release 0.5.2, 2011-08-27
-------------------------
QHexEdit
- New Feature: Del & Backspace fill with 0x0 in overwrite mode,
      so data length is here allways constant

Release 0.5.1, 2011-08-27
-------------------------
Documentation
- Release information corrected

Release 0.5.0, 2011-08-27
-------------------------
Example/OptionsDialog:
- BugFix: No redefining of signal "accepted"
- BugFix: Method "recect" removed
- New Feature: Choose selection color

QHexEdit:
- New Feature: Select data with mouse and keyboard
- New Feature: Cut, Copy and Paste functionality
- BugFix: Ensure cursor visible now works properly
- BugFix: When using mouse weel, qhexedit looses focus
- BugFix: Changed status is independent on the content
- Polishing: Nicer colors for highlighting, selection, and address area

