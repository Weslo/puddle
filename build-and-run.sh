#!/bin/bash

# run cmake and make
mkdir -p bin
cd bin/
cmake ../ || exit 1
make || exit 1

# run executable
./opengl-play
