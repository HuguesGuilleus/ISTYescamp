// GUILLEUS Hugues <hugues.guilleus@ens.uvsq.fr>

#ifndef MODELE_H
	#define MODELE_H 1

	#include "../vue/graphics.h"

	#define NB_BOITE_PLATEAU 6


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

	// Une case du plateau
	typedef struct  {
		int lisere; /* {1.2.3} */
		TYPE typeP; /* {VIDE, LICORNE , PALADIN} */
		COUL coulP; /* {BLANC, NOIR} */
	} BOITE ;

	BOITE plateau [6][6];

	void init_plateau();
	void init_piece1_debug();
	void init_piece2_debug();

	void deplacement_simple(NUMBOX origine, NUMBOX dest);
	BOOL peut_selectioner_pion(NUMBOX entreBoite, COUL coul, int lisere);

#endif
