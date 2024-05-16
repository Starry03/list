#!/bin/bash
make

sudo rm -rf /usr/local/bin/list

sudo mkdir /usr/local/bin/list
sudo cp ./list /usr/local/bin/list
sudo cp ./icons.txt /usr/local/bin/list
sudo chmod +x /usr/local/bin/list/list

echo "Installed list to /usr/local/bin/list"