#!/bin/bash

# break on error
set -e

# make build directory clean
if [ ! -d build ];then
    mkdir build
else
    rm -rf build/* build/.*
fi

# copy needed data
cd build
cp -r ../src .
cp ../license.txt .
cp ../readme.md .
cp ../python/pyqt6-pyproject.toml pyproject.toml
cp ../python/QHexEdit.sip .

# build wheel and sdist
# sip-build --jobs 12 --verbose
python -m build --verbose

# go back to root dir and exit
cd ..
