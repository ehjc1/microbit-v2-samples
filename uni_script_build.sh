#! /usr/bin/bash

python build.py

if [ $? = 0 ]; then
    echo "Build Complete!"
    cp MICROBIT.hex /media/ehjc1/MICROBIT
    if [ $? = 0 ]; then
        echo "File Transfer Complete!"
    else
        echo "Transfer Failed!"
    fi
else
    echo "Build Failed!"
    exit -1
fi