// Maxime VINCENT, Hugues GUILLEUS

#include "modele.h"

void init_plateau() {
	int x,y ;

	for (x = 0; x < 6; x++) {
		for (y = 0; y < 6; y++) {
			plateau[x][y].lisere = 1 ;
			plateau[x][y].typeP = VIDE ;
			plateau[x][y].coulP = BLANC ;
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
	plateau[1][1].typeP = LICORNE ;
	plateau[1][1].coulP = NOIR ;
	plateau[2][0].typeP = PALADIN ;
	plateau[2][0].coulP = NOIR ;
	plateau[2][1].typeP = PALADIN ;
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

	for (y = 0; y < 6; y++) {
		plateau[0][y].typeP = PALADIN ;
		plateau[0][y].coulP = BLANC ;
	}
	plateau[0][0].typeP = LICORNE ;

	for (y = 0; y < 6; y++) {
		plateau[5][y].typeP = PALADIN ;
		plateau[5][y].coulP = NOIR;
	}
	plateau[5][3].typeP = LICORNE ;
}

// Renvoie vrai si b n'a pas de pion sur la case, sinon false.
BOOL est_numbox_vide(NUMBOX b) {
	return plateau[b.c][b.l].typeP == VIDE ;
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

// Pour le développement, écrit un box dans la console.
void imprime_box(BOX * b) {
	printf("  %p\n", b);
	printf("  type: %d\n", b->typeP);
	printf("  couleur: %d\n", b->coulP);
	printf("  lisere: %d\n", b->lisere);
}
