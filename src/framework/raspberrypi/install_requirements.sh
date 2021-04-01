#!/bin/bash

echo "Downloading source for BCM2835 library..."
wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.68.tar.gz

echo "Compiling BCM2835 library..."
tar zxvf bcm2835-1.68.tar.gz
cd bcm2835-1.68
./configure
make

echo "Installing BCM2835 library..."
sudo make check
sudo make install

echo "Cleaning up..."
cd ..
rm -f bcm2835-1.68.tar.gz
rm -rf bcm2835-1.68
