#!/bin/sh

set -e

PLASH_DIR=$(pwd)/../plash
export PYTHONPATH=$PLASH_DIR/python/lib
export BUILT_WRAPPER=$PLASH_DIR/python/run_built.py
make -C build
