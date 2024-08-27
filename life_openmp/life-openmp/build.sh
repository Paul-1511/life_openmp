#!/bin/sh

# This script compiles every third party header and source file
# if no compiled header or object file is found in the thirdparty
# directory, files installed in system are used as a fallback

# Then it compiles every source file in the src directory using
# the compiled headers and object files in the thirdparty directory
# and using pkg-config to obtain compilation flags and
# library flags also using every reasonable warnings flags.

set -xe

build()
{
    case $1 in
	header )
	    fallback="$INCDIR"
	    ex=".gch"
	    ;;
	source )
	    fallback="$LIBDIR"
	    ex=".o"
	    ;;
    esac
    shift;
    for path in "$@"; do
	f="$(basename "$path")"
	
	if [ ! -e "$f$ex" ]; then
	    if [ -e "$f" ]; then
		gcc "$f" -o "$f$ex"
	    elif [ -e "$fallback/$f" ]; then
		gcc "$fallback/$f" -o "$f$ex"
	    fi
	fi
    done
}



# Third party and data
TP_HFILES="$(find thirdparty -type f -name '*.h')"
INCDIR="/usr/include"
LIBDIR="/usr/lib"
DATADIR="./data/raygui"

# Compiler options
CFLAGS="-Wall -Wextra -Wpedantic $(pkg-config --cflags raylib) -fopenmp -lm -lpthread -ldl"
LIBS="$(pkg-config --libs raylib)"
SFILES="$(find src -type f -name '*.c')"

# Generate gui
if [ "$1" = "-g" ]; then
    rguilayout -i "$DATADIR/lifegui.rgl" -o "src/interface.h" -t "$DATADIR/template.h"
fi

cd thirdparty
build header $TP_HFILES
cd ..

mkdir -p build
# build source $RSFILES

OFILES="$(find thirdparty -type f -name '*.o')"

time gcc $OFILES $SFILES $CFLAGS $LIBS -I./thirdparty -o ./build/life
