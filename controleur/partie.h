//Maxime VINCENT, Hugues GUILLEUS

#ifndef PARTIE_H
	#define PARTIE_H 1

	#include "../vue/graphics.h"
	#include "../modele/modele.h"
	#include "../vue/vue.h"

	NUMBOX point_ig_to_numBoite(int ig, POINT P);
	POINT numBoite_to_pointBG_ig(int ig, NUMBOX numboxB);

	NUMBOX attend_click_non_invalide(int ig);
	NUMBOX attend_clic_numbox(int ig);
	BOOL estHors_plateau(POINT click);

#endif
