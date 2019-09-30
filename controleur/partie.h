//Maxime VINCENT, Hugues GUILLEUS

#ifndef PARTIE_H
	#define PARTIE_H 1

	#include "../vue/graphics.h"
	#include "../modele/modele.h"
	#include "../vue/vue.h"

	void positionne_pions(int ig, COUL joueur);

	BOOL gagne(NUMBOX origine, NUMBOX dest, COUL joueur, int ig);

	POINT attend_clic_quitter_ou_case_non_invalide(int ig);

	NUMBOX point_ig_to_numBoite(int ig, POINT P);
	POINT numBoite_to_pointBG_ig(int ig, NUMBOX numboxB);

	BOOL estHors_plateau(POINT click);
	BOOL estDans_btn_info(POINT p);

	BOOL attend_clic_numbox_non_invalide(int ig, NUMBOX* box);

#endif
