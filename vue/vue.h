#ifndef VUE_H
	#define VUE_H
	#include "graphics.h"
	#include "../main.h"

	// ############################################
	//                    ISTY
	//
	//
	// Maxime Vincent, Hugues G
	//
	//
	// SOMMAIRE
	//
	// 1. TYPES, VARIABLES, CONSTANTES ... ligne 
	// 2. FONCTIONS                    ... ligne 
	// #############################################
	
	
	// ###############################
	// 1. TYPES, VARIABLES, CONSTANTES
	// ###############################
	
	#define H_FENETRE 300
	#define L_FENETRE 800
	#define L_PANEL_JEU 500
	#define L_PANEL_SCORE 300
	
	#define NB_BOX_PLATEAU 6
	
	
	// ###############################
	// 2. FONCTIONS
	// ###############################
	
	void afficher_plateau();
	void afficher_panel_score();
	void afficher_panel_jeu();

#endif
