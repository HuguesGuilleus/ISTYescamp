// Maxime VINCENT, Hugues GUILLEUS

#include "modele.h"

void init_plateau() {
	int x,y ;

	for (x = 0; x < NB_BOX_PLATEAU; x++) {
		for (y = 0; y < NB_BOX_PLATEAU; y++) {
			plateau[x][y].lisere = 1 ;
			plateau[x][y].typeP = VIDE ;
			plateau[x][y].coulP = BLANC ;
			plateau[x][y].status = INVALIDE ;
		}
	}

	plateau[0][0].lisere = 3 ;
	plateau[0][4].lisere = 3 ;
	plateau[1][1].lisere = 3 ;
	plateau[1][3].lisere = 3 ;
	plateau[2][2].lisere = 3 ;
	plateau[2][4].lisere = 3 ;
	plateau[3][1].lisere = 3 ;
	plateau[3][5].lisere = 3 ;
	plateau[4][0].lisere = 3 ;
	plateau[4][2].lisere = 3 ;
	plateau[4][4].lisere = 3 ;
	plateau[5][3].lisere = 3 ;

	plateau[0][2].lisere = 2 ;
	plateau[0][3].lisere = 2 ;
	plateau[1][0].lisere = 2 ;
	plateau[1][5].lisere = 2 ;
	plateau[2][0].lisere = 2 ;
	plateau[2][5].lisere = 2 ;
	plateau[3][2].lisere = 2 ;
	plateau[3][3].lisere = 2 ;
	plateau[5][0].lisere = 2 ;
	plateau[5][1].lisere = 2 ;
	plateau[5][4].lisere = 2 ;
	plateau[5][5].lisere = 2 ;
}

void init_piece1_debug() {
	init_plateau(plateau);

	plateau[0][1].typeP = PALADIN ;
	plateau[0][1].coulP = NOIR ;
	plateau[0][1].status = VALIDE ;
	plateau[1][1].typeP = LICORNE ;
	plateau[1][1].coulP = NOIR ;
	plateau[1][1].status = SELECT;
	plateau[2][0].typeP = PALADIN ;
	plateau[2][0].coulP = NOIR ;
	plateau[2][1].typeP = PALADIN ;
	plateau[2][1].status = VALIDE ;
	plateau[2][1].coulP = NOIR ;
	plateau[4][0].typeP = PALADIN ;
	plateau[4][0].coulP = NOIR ;
	plateau[5][1].typeP = PALADIN ;
	plateau[5][1].coulP = NOIR ;

	plateau[1][4].typeP = PALADIN ;
	plateau[1][4].coulP = BLANC ;
	plateau[1][5].typeP = PALADIN ;
	plateau[1][5].coulP = BLANC ;
	plateau[2][5].typeP = PALADIN ;
	plateau[2][5].coulP = BLANC ;
	plateau[3][4].typeP = PALADIN ;
	plateau[3][4].coulP = BLANC ;
	plateau[3][5].typeP = LICORNE ;
	plateau[3][5].coulP = BLANC ;
	plateau[4][4].typeP = PALADIN ;
	plateau[4][4].coulP = BLANC ;
}

void init_piece2_debug() {
	int y;

	init_plateau(plateau);

	for (y = 0; y < NB_BOX_PLATEAU; y++) {
		plateau[0][y].typeP = PALADIN ;
		plateau[0][y].coulP = BLANC ;
	}
	plateau[0][0].typeP = LICORNE ;

	for (y = 0; y < NB_BOX_PLATEAU; y++) {
		plateau[5][y].typeP = PALADIN ;
		plateau[5][y].coulP = NOIR;
	}
	plateau[5][3].typeP = LICORNE ;
}

void init_piece3_debug() {
	int y;

	init_plateau(plateau);

	for (y = 3; y < NB_BOX_PLATEAU; y++) {
		plateau[0][y].typeP = PALADIN ;
		plateau[0][y].coulP = BLANC ;
	}
	plateau[0][0].coulP = BLANC ;
	plateau[0][0].typeP = LICORNE ;

	plateau[1][1].coulP = BLANC ;
	plateau[1][1].typeP = PALADIN ;
	plateau[2][2].coulP = BLANC ;
	plateau[2][2].typeP = PALADIN ;

	for (y = 0; y < NB_BOX_PLATEAU; y++) {
		plateau[5][y].typeP = PALADIN ;
		plateau[5][y].coulP = NOIR;
	}
	plateau[5][3].typeP = VIDE ;

	plateau[2][3].typeP = LICORNE ;
	plateau[2][3].coulP = NOIR ;
}

void ajoute_paladin(NUMBOX coord, COUL coul) {
	plateau[coord.c][coord.l].typeP = PALADIN ;
	plateau[coord.c][coord.l].coulP = coul ;
}

void ajoute_licorne(NUMBOX coord, COUL coul) {
	plateau[coord.c][coord.l].typeP = LICORNE ;
	plateau[coord.c][coord.l].coulP = coul ;
}

void supprime_pion(NUMBOX coord) {
	plateau[coord.c][coord.l].typeP = VIDE ;
	plateau[coord.c][coord.l].coulP = BLANC ;
}

// Met tout les status à invalide
void init_status() {
	int c,l;
	for (c = 0; c < NB_BOX_PLATEAU; c++) {
		for (l = 0; l < NB_BOX_PLATEAU; l++) {
			plateau[c][l].status = INVALIDE ;
		}
	}
}

// Séléctionne les pions déplacable, et les cases d'arrivés en fonction
// de coul: la couleur du joueur actuel; lisere: la case d'arrivé de la
// dernière pièce, 0 au premier tour; select: la case séléctionné ou NULL.
// Renvoie TRUE si il y a des pions déplaçable.
BOOL selectionne_pion(COUL coul, int lisere, NUMBOX * select) {
	int c,l ;
	BOX * b ;
	BOOL peutJouer = FALSE ;

	init_status();

	for (c = 0; c < NB_BOX_PLATEAU; c++) {
		for (l = 0; l < NB_BOX_PLATEAU; l++) {
			b = &plateau[c][l] ;
			if (b->typeP != VIDE && b->coulP == coul) {
				if (lisere == 0 || lisere == b->lisere) {
					plateau[c][l].status = VALIDE ;
					peutJouer = TRUE ;
				}
			}
		}
	}

	if (select) {
		b = &plateau[select->c][select->l] ;
		parcourt_plusieurs_cases(select->c, select->l, b->coulP, b->typeP, b->lisere) ;
		b->status = SELECT ;
	}

	return peutJouer ;
}

// Déplacement pour la séléction des possibilités
void parcourt_plusieurs_cases(int c, int l, COUL coul, TYPE pion, int lisere) {
	BOX* b = getBox(c, l) ;

	if (lisere == 0) {
		b->status = ACCESSIBLE ;
		return ;
	}

	parcourt_une_case(c, l-1, coul, pion, lisere-1);
	parcourt_une_case(c, l+1, coul, pion, lisere-1);
	parcourt_une_case(c-1, l, coul, pion, lisere-1);
	parcourt_une_case(c+1, l, coul, pion, lisere-1);

	if (b->status == PARCOUR ) {
		b->status = INVALIDE ;
	}
}

// Regarde si on peut parourire cette case et si oui, parcour les cases adjacentes.
void parcourt_une_case(int c, int l, COUL coul, TYPE pion, int lisere) {
	BOX * b = getBox(c, l);

	if (b == NULL) {
		return ;
	}

	if (peut_parourir(b, coul, pion, lisere)) {
		if (b->status != ACCESSIBLE) {
			b->status = PARCOUR ;
		}
		parcourt_plusieurs_cases(c, l, coul, pion, lisere);
	}
}

// indique si un pion peut parcourire sur une case
BOOL peut_parourir(BOX * b, COUL c, TYPE pion, int lisere) {
	if (b == NULL || b->status == PARCOUR) {
		return FALSE ;
	}
	if (pion == LICORNE) {
		return b->typeP == VIDE ;
	} else {
		return b->typeP == VIDE || (b->typeP == LICORNE && b->coulP != c && lisere == 0) ;
	}
}

// Récuère l'addresse d'une case du plateau. Renvoie NULL si en dehors.
BOX* getBox(int c, int l) {
	if (c<0 || c>=NB_BOX_PLATEAU || l<0 || l>=NB_BOX_PLATEAU) {
		return NULL ;
	} else {
		return &plateau[c][l] ;
	}
}

// Renvoie vrai si b n'a pas de pion sur la case, sinon false.
BOOL est_numbox_vide(NUMBOX b) {
	return plateau[b.c][b.l].typeP == VIDE ;
}

BOOL est_pas_invalide(NUMBOX b) {
	return plateau[b.c][b.l].status != INVALIDE ;
}

BOOL est_pion(NUMBOX b) {
	return plateau[b.c][b.l].typeP != VIDE ;
}

BOOL est_licorne_adverse(NUMBOX coord, COUL coul) {
	BOX * b = &plateau[coord.c][coord.l] ;
	return b->typeP == LICORNE && coul != b->coulP ;
}

// Deplace un pion d'une case à une autre. Pas de vérication de validité.
void deplacement_simple(NUMBOX origine, NUMBOX dest) {
	plateau[dest.c][dest.l].coulP = plateau[origine.c][origine.l].coulP ;
	plateau[dest.c][dest.l].typeP = plateau[origine.c][origine.l].typeP ;
	plateau[origine.c][origine.l].typeP = VIDE ;
}

// Fonction pour la suite
BOOL peut_selectioner_pion(NUMBOX entreBox, COUL coul, int lisere) {
	BOX * plateauBox = &plateau[entreBox.c][entreBox.l] ;
	imprime_box(plateauBox);
	if (plateauBox->typeP == VIDE) {
		printf("type\n");
		return FALSE ;
	}
	if (plateauBox->coulP != coul) {
		printf("couleur\n");
		return FALSE ;
	}
	if (plateauBox->lisere != lisere) {
		printf("lisere\n");
		return FALSE ;
	}
	return TRUE ;
}

// Inverse la couleur du joueur courant
void change_joueur(COUL * j) {
	if (*j == BLANC) {
		*j = NOIR ;
	} else {
		*j = BLANC ;
	}
}

// Retourne le lisere pour le tour suivant
int change_lisere(NUMBOX b) {
	return plateau[b.c][b.l].lisere ;
}


// Pour le développement, écrit un box dans la console.
void imprime_box(BOX * b) {
	printf("  %p\n", b);
	printf("  type: %d\n", b->typeP);
	printf("  couleur: %d\n", b->coulP);
	printf("  lisere: %d\n", b->lisere);
	printf("  status: %d\n", b->status);
}

// Pour le développement, écrit un NUMBOX dans la console.
void imprime_numbox(NUMBOX b) {
	printf("NUMBOX: (%d,%d)\n", b.c, b.l);
}
