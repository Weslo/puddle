#!/bin/bash

# run cmake and make
mkdir -p bin
cd bin/
cmake ../ || exit 1
make || exit 1

# run tests
./math/tests/quaternion-tests
./math/tests/vector2-tests
./math/tests/vector3-tests
