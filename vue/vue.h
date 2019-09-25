//Maxime VINCENT, Hugues GUILLEUS

#ifndef VUE_H
	#define VUE_H
	#include "graphics.h"
	#include "../modele/modele.h"
	#include "../controleur/partie.h"
	#include "../controleur/menu.h"

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

	void afficher_licorne(POINT bg, COUL coul);
	void afficher_paladin(POINT bg, COUL coul);
	void afficher_lisere(POINT bg, int nbLisere,NUMBOX box);
	void afficher_lisere_pion(int ig, NUMBOX box);

	void afficher_victoire(COUL joueur);
	void afficher_coups_impossible();
	void afficher_joueur_courant(COUL joueur);

	void afficher_btn(POINT bg, COULEUR couleur, char* text);
	void afficher_menu();
	void afficher_menu_select_joueur(COUL joueur,int i,int mod);
	void afficher_btn_select_joueur(POINT bg, COULEUR couleur, COUL joueur);
	void afficher_btn_select_ig(POINT bg, COULEUR couleur, int ig);
	void afficher_plateau_mini(int ig);

	void afficher_placement_pions(int paladin, int licorne);

#endif
