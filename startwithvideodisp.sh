#!/bin/sh
if [`rm -i camread_log.yuv`]
 then
mkfifo camread_log.yuv
fi
./agent 2> /dev/null & gmplayer -really-quiet -demuxer rawvideo -rawvideo fps=7:w=640:h=480:i420 -vo x11 camread_log.yuv &
