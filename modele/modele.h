// GUILLEUS Hugues <hugues.guilleus@ens.uvsq.fr>

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

	// Une case du plateau
	typedef struct  {
		int lisere; /* {1.2.3} */
		TYPE typeP; /* {VIDE, LICORNE , PALADIN} */
		COUL coulP; /* {BLANC, NOIR} */
	} BOX ;

	BOX plateau [6][6];

	void init_plateau();
	void init_piece1_debug();
	void init_piece2_debug();

	BOOL est_numbox_vide(NUMBOX b);
	BOOL peut_selectioner_pion(NUMBOX entreBox, COUL coul, int lisere);

	void deplacement_simple(NUMBOX origine, NUMBOX dest);
	void imprime_box(BOX * b);

#endif
