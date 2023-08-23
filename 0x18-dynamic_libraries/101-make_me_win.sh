#!/bin/bash
wget -P /tmp https://github.com/Katlego1993/alx-low_level_programming/rdw/master/0x18-dynamic_libraries/libgiga.so
export LD_PRELOAD=/tmp/libgiga.
