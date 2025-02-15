if [ ! -d build ];then
    mkdir build
else
    rm -rf build/* build/.*
fi

cd build
qmake ../src/qhexedit.pro
make -j 12
cd ..
