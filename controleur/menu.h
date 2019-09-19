//Maxime VINCENT, Hugues GUILLEUS

#ifndef MENU_H
	#define MENU_H 1

	#include "../vue/graphics.h"
	#include "../modele/modele.h"
	#include "../vue/vue.h"
	
	BOOL est_dans_bouton_quitter(POINT clic);
	BOOL est_dans_bouton_JvsJ(POINT clic);
	BOOL est_dans_bouton_JvsIA(POINT clic);
	
#endif
