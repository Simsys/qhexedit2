cd build

qmake ../sip/qhexedit.pro
sudo make

python ../sip/configure.py
make
sudo make install

cd ..

