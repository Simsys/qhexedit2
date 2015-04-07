#
# Attention: QT4 and Python2
#

cd build

/usr/share/qt4/bin/qmake ../sip/qhexedit.pro
sudo make

python ../sip/configure.py
make
sudo make install

cd ..

