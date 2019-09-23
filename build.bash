#!/bin/bash

CC="gcc"
CFLAGS="-O2 -Wall `sdl-config --cflags`"
LIBS="`sdl-config --libs` -lm -lSDL_ttf"

clear

if [[ $# == 1 && $1 == "netoyage" ]]; then
	rm -f *.o vue/police.h doc.html
fi

which getDocxx &>/dev/null && getDoc

rm -f vue/police.h
touch vue/police.h
test -e /usr/include/SDL_ttf.h           && echo "#define SDL_TTF_OK" > vue/police.h
test -e /usr/include/SDL/SDL_ttf.h       && echo "#define SDL_TTF_OK" > vue/police.h
test -e /usr/local/include/SDL_ttf.h     && echo "#define SDL_TTF_OK" > vue/police.h
test -e /usr/local/include/SDL/SDL_ttf.h && echo "#define SDL_TTF_OK" > vue/police.h

validation=true

for prog in `find . -name '*.c' -print`
do
	if [[ ${prog%%.c}.o -ot $prog ]]; then
		printf "\t\033[01;34m$prog\033[0m\n"
		$CC $CFLAGS -c $prog || validation=false
	fi
done

# echo "Édition de lien"

validation && gcc -o escampe `find . -name '*.o' -print` $LIBS && ./escampe
