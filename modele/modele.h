// GUILLEUS Hugues <hugues.guilleus@ens.uvsq.fr>

#ifndef MODELE_H
	#define MODELE_H 1
	
	#define NB_BOITE_PLATEAU 6

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
		COUL coulP; /* {BLANC, NOIR} */
	} BOITE ;
	
	typedef struct {
		int angle;
		COUL coulJ;
	} JOUEUR;

	void init_plateau(BOITE plateau[NB_BOITE_PLATEAU][NB_BOITE_PLATEAU]);
	void init_piece1_debug(BOITE plateau[NB_BOITE_PLATEAU][NB_BOITE_PLATEAU]);
	void init_piece2_debug(BOITE plateau[NB_BOITE_PLATEAU][NB_BOITE_PLATEAU]);

#endif
