#! /bin/bash

# python build.py
docker run -v $(pwd):/app --rm microbit-tools

if [ $? = 0 ]; then
    echo "Build Complete!"
    cp MICROBIT.hex /mnt/e/embedded_sys
    if [ $? = 0 ]; then
        echo "File Transfer Complete!"
    else
        echo "Transfer Failed!"
    fi
else
    echo "Build Failed!"
    exit -1
fi