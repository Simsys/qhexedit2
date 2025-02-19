#!/bin/bash

# break on error
set -e

lupdate example/qhexedit.pro
python python/translate.py example/qhexedit.pro
lrelease example/qhexedit.pro
