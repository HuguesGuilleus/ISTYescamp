#ifndef VUE_H
	#define VUE_H
	#include "graphics.h"
	#include "../modele/modele.h"
	#include "../controleur/partie.h"

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
	
	#define H_FENETRE 600
	#define L_FENETRE 900
	#define L_PANEL_SCORE L_FENETRE-H_FENETRE
	#define TAILLE_PLATEAU 500
	
	// ###############################
	// 2. FONCTIONS
	// ###############################
	
	void afficher_plateau(int ig);
	void afficher_legende_plateau(int ig);

	void afficher_panneau_info();
	void afficher_panneau_jeu(int ig);
	
	void afficher_licorne(POINT centre, COUL coul);
	void afficher_paladin(POINT centre, COUL coul);
	void affiche_lisere(POINT centre, int nbLisere);

#endif
