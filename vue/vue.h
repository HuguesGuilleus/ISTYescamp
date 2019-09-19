#ifndef VUE_H
	#define VUE_H
	#include "graphics.h"
	#include "../main.h"
	#include "../modele/modele.h"

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
	
	#define H_FENETRE 500
	#define L_FENETRE 900
	#define L_PANEL_JEU 550
	#define L_PANEL_SCORE 350
	#define TAILLE_PLATEAU 400
	
	// ###############################
	// 2. FONCTIONS
	// ###############################
	
	void afficher_plateau(BOX plateau[NB_BOX_PLATEAU][NB_BOX_PLATEAU]);
	void afficher_panel_score();
	void afficher_panel_jeu(BOX plateau[NB_BOX_PLATEAU][NB_BOX_PLATEAU]);
	
	void afficher_licorne(COUL coul,POINT centre);
	void afficher_paladin(COUL coul,POINT centre);

#endif
