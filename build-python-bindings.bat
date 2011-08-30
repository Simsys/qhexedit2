cd build
D:\Programme\Qt\4.6.2\bin\qmake ..\sip\qhexedit.pro -r -spec win32-g++ "CONFIG+=release
D:\Programme\QtSDK\mingw\bin\mingw32-make

python ..\sip\configure.py
D:\Programme\QtSDK\mingw\bin\mingw32-make
D:\Programme\QtSDK\mingw\bin\mingw32-make install
cd ..