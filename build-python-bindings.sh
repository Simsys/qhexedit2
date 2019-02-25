if [ ! -d build ];then
    mkdir build
else
    rm -rf build/*
fi

cd build
qmake ../src/qhexedit.pro
sudo make
cd ..

# for PyQt4 use python2 and PyQt4
# sudo python2 setup.py install

# for PyQt5 use python3 and PyQt5
sudo python3 setup.py install
