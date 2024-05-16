#!/bin/bash
make
sudo rm -f /usr/local/bin/list
sudo cp ./list /usr/local/bin/
sudo chmod +x /usr/local/bin/list
echo "Installed list to /usr/local/bin/list"