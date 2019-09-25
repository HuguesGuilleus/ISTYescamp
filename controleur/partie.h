//Maxime VINCENT, Hugues GUILLEUS

#ifndef PARTIE_H
	#define PARTIE_H 1

	#include "../vue/graphics.h"
	#include "../modele/modele.h"
	#include "../vue/vue.h"

	void positionne_pions(int ig, COUL joueur);

	NUMBOX point_ig_to_numBoite(int ig, POINT P);
	POINT numBoite_to_pointBG_ig(int ig, NUMBOX numboxB);

	BOOL estHors_plateau(POINT click);
	BOOL estDans_btn_info(POINT p);

	NUMBOX attend_click_non_invalide(int ig);
	NUMBOX attend_clic_numbox(int ig);

#endif
