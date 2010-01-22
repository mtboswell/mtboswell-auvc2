#!/bin/sh
v4lctl setattr "Auto White Balance" off
rm -i camread_log.yuv
./agent 2> /dev/null &
