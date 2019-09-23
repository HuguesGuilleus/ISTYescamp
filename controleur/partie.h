#ifndef PARTIE_H
	#define PARTIE_H 1

	#include "../vue/graphics.h"
	#include "../modele/modele.h"
	#include "../vue/vue.h"

	void jouer();

	POINT numBoite_to_pointBG_ig1(NUMBOX numboxB);
	POINT numBoite_to_pointBG_ig2(NUMBOX numboxB);
	NUMBOX point_ig1_to_numBoite(POINT P);
	NUMBOX point_ig2_to_numBoite(POINT P);

	NUMBOX attend_click_numbox(int ig);
	BOOL estHors_plateau(POINT click);


#endif
