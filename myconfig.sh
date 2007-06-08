#!/bin/sh

../configure --prefix=/usr CC=gcc-4.0 --with-tls --disable-profile CFLAGS="-pipe -fstrict-aliasing -g1 -O3"
