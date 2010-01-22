#!/bin/sh
v4lctl setattr "Auto White Balance" off
rm -i camread_log.yuv
mkfifo camread_log.yuv
./agent &
sleep 3
mplayer -really-quiet -demuxer rawvideo -rawvideo fps=7:w=640:h=480:i420 -vo x11 camread_log.yuv &
