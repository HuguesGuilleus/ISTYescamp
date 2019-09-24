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

void init_status() {
	int c,l;
	for (c = 0; c < NB_BOX_PLATEAU; c++) {
		for (l = 0; l < NB_BOX_PLATEAU; l++) {
			plateau[c][l].status = INVALIDE ;
		}
	}
}

// Si lisere est nulle alors tous les pions peuvent être séléctionnés.
// select est la case séléctionnée.
// Renvoie TRUE si il y a des pions déplacable.
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
		selection_possibilite(*select);
		plateau[select->c][select->l].status = SELECT ;
		printf("plateau[select->c][select->l].status: %d\n", plateau[select->c][select->l].status );
	}

	return peutJouer ;
}

// séléctionne les cases accessibles
void selection_possibilite(NUMBOX coord) {
	BOX * b = getBox(coord.c, coord.l) ;
	valide_deplacement(coord.c, coord.l, b->coulP, b->typeP, b->lisere) ;
}

// Déplacement pour la séléction des possibilité
void valide_deplacement(int c, int l, COUL coul, TYPE pion, int lisere) {
	BOX* b = NULL ;

	if (lisere == 0) {
		getBox(c, l)->status = ACCESSIBLE ;
		return ;
	}

	b = getBox(c+1, l);
	if (peut_aller(b, coul, pion)) {
		b->status = PARCOUR ;
		valide_deplacement(c+1, l, coul, pion, lisere-1);
	}
	b = getBox(c-1, l);
	if (peut_aller(b, coul, pion)) {
		b->status = PARCOUR ;
		valide_deplacement(c-1, l, coul, pion, lisere-1);
	}
	b = getBox(c, l+1);
	if (peut_aller(b, coul, pion)) {
		b->status = PARCOUR ;
		valide_deplacement(c, l+1, coul, pion, lisere-1);
	}
	b = getBox(c, l-1);
	if (peut_aller(b, coul, pion)) {
		b->status = PARCOUR ;
		valide_deplacement(c, l-1, coul, pion, lisere-1);
	}

	b = getBox(c, l) ;
	if (b->status == PARCOUR ) {
		b->status = INVALIDE ;
	}
}

// indique si un pion peut aller sur une case
BOOL peut_aller(BOX * b, COUL c, TYPE pion) {
	if (b == NULL || b->status != INVALIDE) {
		return FALSE ;
	}
	if (pion == LICORNE) {
		return b->typeP == VIDE ;
	} else {
		return b->typeP == VIDE || ( b->typeP == LICORNE && b->coulP != c ) ;
	}
}

// Récuère l'addresse d'une c ase du plateau. Renvoie NULL si en dehors.
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
	printf("  status: %d\n", b->status);
}

// Pour le développement, écrit un NUMBOX dans la console.
void imprime_numbox(NUMBOX b) {
	printf("NUMBOX: (%d,%d)\n", b.c, b.l);
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
