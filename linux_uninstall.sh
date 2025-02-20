#!/bin/bash

# main
sudo rm -rf /usr/local/bin/list

# dependencies
sudo rm /usr/local/share/list/*
sudo rmdir /usr/local/share/list

echo "Successfully uninstalled list"
