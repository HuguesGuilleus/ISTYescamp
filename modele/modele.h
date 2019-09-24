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
	void init_piece1_debug();
	void init_piece2_debug();

	BOOL est_pas_invalide(NUMBOX b);
	BOOL est_pion(NUMBOX b);
	BOOL est_numbox_vide(NUMBOX b);
	BOOL peut_selectioner_pion(NUMBOX entreBox, COUL coul, int lisere);

	void deplacement_simple(NUMBOX origine, NUMBOX dest);
	void imprime_box(BOX * b);

	void init_status();
	BOOL selectionne_pion(COUL coul, int lisere, NUMBOX * select);

	void change_joueur(COUL * j);
	int change_lisere(NUMBOX b);

	void selection_possibilite(NUMBOX b);
	void valide_deplacement(int c, int l, COUL coul, TYPE pion, int lisere);
	BOOL peut_aller(BOX * b, COUL c, TYPE pion);
	BOX* getBox(int c, int l);

	void imprime_numbox(NUMBOX b);

#endif
