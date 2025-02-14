#!/bin/bash

# break on error
set -e

# make build directory clean and copy needed data
cd build
rm -r -f *
cp -r ../src .
cp ../license.txt .
cp ../readme.md .
cp ../python/project.py .
cp ../python/pyqt5-pyproject.toml pyproject.toml
cp ../python/QHexEdit.sip .

# build wheel and sdist
# sip-build --jobs 12 --verbose
python -m build --verbose

# go back to root dir and exit
cd ..
