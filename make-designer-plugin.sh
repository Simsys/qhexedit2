if [ ! -d build ];then
    mkdir build
else
    rm -rf build/* build/.*
fi

cd build
qmake ../designer/designer.pro
make -j 12
cd ..
