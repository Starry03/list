#!/bin/bash

cd ./UniC || exit

if ! git pull
then
	echo "Error: git pull failed"
	exit 1
fi

cd .. || exit

if ! git pull
then
    echo "Error: git pull failed"
    exit 1
fi

sh ./linux_install.sh

echo "List correcly updated"
