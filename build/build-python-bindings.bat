set path=%PATH%;D:\Programme\mingw\mingw_4.4.0\bin
mkdir win
cd win

D:\Programme\Qt\Qt4.8.5\Qt\bin\qmake ..\..\example\qhexedit.pro -r -spec win32-g++ "CONFIG+=release"
mingw32-make

python ..\..\sip\configure.py
mingw32-make
mingw32-make install

cd ..

