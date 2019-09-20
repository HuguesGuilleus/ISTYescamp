#ifndef PARTIE_H
	#define PARTIE_H 1

	#include "../vue/graphics.h"
	#include "../modele/modele.h"
	#include "../vue/vue.h"

	void jouer();

	POINT numBoite_to_pointBG_ig1(NUMBOITE numboxB);
	POINT numBoite_to_pointBG_ig2(NUMBOITE numboxB);
	NUMBOITE point_ig1_to_numBoite(POINT P);
	NUMBOITE point_ig2_to_numBoite(POINT P);

	NUMBOITE attend_click_NUMBOITE(int ig);
	BOOL estHors_plateau(POINT click);


#endif
