set path=%PATH%;D:/Programme/Qt/Qt5.3.2/Tools/mingw482_32/bin
mkdir win
cd win
D:\Programme\Qt\Qt5.3.2\5.3\mingw482_32\bin\qmake ..\..\example\qhexedit.pro -r -spec win32-g++ "CONFIG+=release"
mingw32-make
cd ..

