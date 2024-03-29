//Maxime VINCENT, Hugues GUILLEUS

#ifndef MODELE_H
	#define MODELE_H 1

	#include "../vue/graphics.h"

	#define NB_BOX_PLATEAU 6

	// Les coordonées d'une BOX du plateau
	typedef struct {
		int c ; // pour la colone
		int l ; // pour la ligne
	} NUMBOX ;

	// La couleur d'un pion
	typedef enum {
		BLANC, NOIR
	} COUL ;

	// Le type d'un pion
	typedef enum {
		VIDE, LICORNE, PALADIN
	} TYPE ;

	typedef enum {
		INVALIDE, // case non séléctionnable
		VALIDE, // case clicable
		SELECT, // case séléctionné
		ACCESSIBLE, // case vide où l'on peut envoyer une pièce
		PARCOUR, // case sur un trajet
	} STATUS ;

	// Une case du plateau
	typedef struct  {
		int lisere; /* {1.2.3} */
		TYPE typeP; /* {VIDE, LICORNE , PALADIN} */
		COUL coulP; /* {BLANC, NOIR} */
		STATUS status ;
	} BOX ;

	BOX plateau [NB_BOX_PLATEAU][NB_BOX_PLATEAU];

	void init_plateau();
	void init_status();
	void init_juste_case_accessible();

	void init_piece1_debug();
	void init_piece2_debug();
	void init_piece3_debug();
	void init_piece4_debug();

	void init_case_accessible_position(int ig, COUL joueur);
	BOOL est_accessible_positionnement(NUMBOX box, int ig, COUL joueur);
	void ajoute_paladin(NUMBOX coord, COUL coul);
	void ajoute_licorne(NUMBOX coord, COUL coul);
	void supprime_pion(NUMBOX coord);

	BOOL peut_selectionner_pion(COUL coul, int lisere);
	void selectionne_case_accessible(COUL coul, int lisere, NUMBOX select);
	BOOL selectionne_pion(COUL coul, int lisere, NUMBOX * select);

	BOOL est_pas_invalide(NUMBOX b);
	BOOL est_pion_joueur_courant(NUMBOX coord, COUL joueur);
	BOOL est_licorne_adverse(NUMBOX coord, COUL coul);
	BOOL est_numbox_vide(NUMBOX b);
	BOOL peut_selectioner_pion(NUMBOX entreBox, COUL coul, int lisere);

	void deplacement_simple(NUMBOX origine, NUMBOX dest);
	void change_joueur(COUL * j);
	int change_lisere(NUMBOX b);

	BOOL parcourt_plusieurs_cases(int c, int l, COUL coul, TYPE pion, int lisere);
	BOOL parcourt_une_case(int c, int l, COUL coul, TYPE pion, int lisere);
	BOOL peut_parourir(BOX * b, COUL c, TYPE pion, int lisere);

	BOX* getBox(int c, int l);

	void imprime_box(BOX * b);
	void imprime_numbox(NUMBOX b);

#endif
