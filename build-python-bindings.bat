cd build
qmake ..\sip\qhexedit.pro -r -spec win32-g++ "CONFIG+=release
make

python ..\sip\configure.py
make
make install
cd ..