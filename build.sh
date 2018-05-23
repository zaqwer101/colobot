#!/bin/bash

if ! [ -d build ]; then 
	mkdir build
fi
cd build
cmake -DCMAKE_BUILD_TYPE=release -DOPENAL_SOUND=1 -DASSERTS=1  -DCMAKE_INSTALL_PREFIX="/usr" -DCOLOBOT_INSTALL_BIN_DIR="/usr/bin" ..
make -j8
sudo make install

