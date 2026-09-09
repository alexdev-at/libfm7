#!/bin/sh

if [ "$1" = "init" ]; then
    echo "Initializing libfm7 project..."
    cp /opt/libfm7/templates/Makefile.template ./Makefile
    mkdir -p src
    cp /opt/libfm7/templates/main.c.template ./src/main.c
    echo "Done."
    exit 0
fi

exec "$@"

