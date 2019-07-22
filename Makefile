#
# Make the postfixer.
#
# Written by Max Hanson, July 2019.
# Licensed under MIT, see LICENSE.md for details
#


clean:
	rm -rf translator
	rm -rf build/*

all: build/main.o
	gcc -o translator build/main.o

build/main.o:
	mkdir -p build
	gcc -o build/main.o -g -c source/main.c

