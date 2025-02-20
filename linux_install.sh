#!/bin/bash
make install

# main
sudo rm -rf /usr/local/bin/list
sudo cp ./list /usr/local/bin/
sudo chmod +x /usr/local/bin/list

# dependencies
sudo mkdir /usr/local/share/list
sudo rm /usr/local/share/list/*
sudo cp ./icons.txt /usr/local/share/list/

echo "Installed list to /usr/local/bin"
