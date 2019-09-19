// GUILLEUS Hugues <hugues.guilleus@ens.uvsq.fr>

#ifndef MODELE_H
	#define MODELE_H 1

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
		int lisere ; /* {1.2.3} */
		TYPE typeP ; /* {VIDE, LICORNE , PALADIN} */
		COUl coulP; /* {BLANC, NOIR} */
	} BOX ;

	BOX plateau [6][6] ;

	void init_plateau();

#endif
