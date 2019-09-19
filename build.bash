#!/bin/bash


CC="gcc"
CFLAGS="-O2 -Wall `sdl-config --cflags`"
LIBS="`sdl-config --libs` -lm -lSDL_ttf"

clear

rm -f police.h
touch police.h
test -e /usr/include/SDL_ttf.h           && echo "#define SDL_TTF_OK" > police.h
test -e /usr/include/SDL/SDL_ttf.h       && echo "#define SDL_TTF_OK" > police.h
test -e /usr/local/include/SDL_ttf.h     && echo "#define SDL_TTF_OK" > police.h
test -e /usr/local/include/SDL/SDL_ttf.h && echo "#define SDL_TTF_OK" > police.h

for prog in `find . -name '*.c' -print`
do
	if [[ ${prog%%.c}.o -ot $prog ]]; then
		printf "\t\033[01;34m$prog\033[0m\n"
		$CC $CFLAGS -c $prog
	fi
done

gcc -o escampe `find . -name '*.o' -print` $LIBS

./escampe
