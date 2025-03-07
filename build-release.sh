#!/bin/bash
sh ./build-clean.sh
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
cd ..
