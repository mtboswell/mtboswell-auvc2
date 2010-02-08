#! /bin/bash
qmake
make | grep warn
make clean
