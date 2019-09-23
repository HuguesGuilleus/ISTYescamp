#!/bin/bash

# Issue de Makefile de Franck QUESSETTE et Laurence PILARD
# Modifié par Hugues GUILLEUS

CC="gcc"
CFLAGS="-O2 -Wall `sdl-config --cflags`"
LIBS="`sdl-config --libs` -lm -lSDL_ttf"

# Affiche les messages en couleur
function print() {
	if [[ $# != 0 ]]; then
		printf "\t\033[01;34m$*\033[0m\n"
	fi
}

if [[ $# == 1 && $1 == "clean" ]]; then
	print "Netoyage"
	rm -f *.o */*.o vue/police.h doc.html escampe
	exit 0
fi

clear
which getDoc &>/dev/null && getDoc && print "Documentation"

rm -f vue/police.h
touch vue/police.h
test -e /usr/include/SDL_ttf.h           && echo "#define SDL_TTF_OK" > vue/police.h
test -e /usr/include/SDL/SDL_ttf.h       && echo "#define SDL_TTF_OK" > vue/police.h
test -e /usr/local/include/SDL_ttf.h     && echo "#define SDL_TTF_OK" > vue/police.h
test -e /usr/local/include/SDL/SDL_ttf.h && echo "#define SDL_TTF_OK" > vue/police.h

# Indique si il y a eu une erreur
validation=true

for prog in `find . -name '*.c' -print`
do
	if [[ `sed -r 's#.*/(\w*).c#\1.o#' <<< $prog` -ot $prog ]]; then
		print "Compilation:" $prog
		$CC $CFLAGS -c $prog || validation=false
	else
		print "Déjà compilé:" $prog
	fi
done

$validation && gcc -o escampe `find . -name '*.o' -print` $LIBS && ./escampe
