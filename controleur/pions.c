#include "pions.h"

BOOL est_accessible_positionnement(NUMBOX box, int ig, COUL joueur) {
	switch (ig) {
		case 1:
			return (box.l < 2 && joueur == BLANC) || (box.l > 3 && joueur == NOIR) ;
		case 2:
			return (box.c < 2 && joueur == BLANC) || (box.c > 3 && joueur == NOIR) ;
		case 3:
			return (box.l > 3 && joueur == BLANC) || (box.l < 2 && joueur == NOIR) ;
		case 4:
			return (box.c > 3 && joueur == BLANC) || (box.c < 2 && joueur == NOIR) ;
		default:
			return FALSE;
	}
}

NUMBOX attend_clic_zone_deplacement(int ig) {
	POINT clic;
	NUMBOX coord ;

	COUL joueur = BLANC ;

	do {
		clic = wait_clic();
		coord = point_ig_to_numBoite(ig, clic);
	} while(!est_accessible_positionnement(coord, ig, joueur));

	return coord ;
}

BOOL estDans_panneau_info(POINT p) {
	return p.x > H_FENETRE ;
}

void positionne_pions(int ig, COUL joueur) {
	POINT clic ;
	NUMBOX coord ;
	int paladin = 0, licorne = 0 ;

	regle_case_accessible_position(ig, joueur);

	afficher_panneau_jeu(ig);
	afficher_panneau_info();
	afficher_joueur_courant(joueur);

	while (TRUE) {
		afficher_plateau(ig);
		affiche_all();
		do {
			clic = wait_clic();
			if (estDans_panneau_info(clic) && licorne==1 && paladin == 5) {
				return ;
			}
			coord = point_ig_to_numBoite(ig, clic);
		} while(!est_accessible_positionnement(coord, ig, joueur));
		switch (plateau[coord.c][coord.l].typeP) {
			case VIDE:
				ajoute_paladin(coord,joueur) ;
				paladin++;
				break ;
			case PALADIN:
				ajoute_licorne(coord,joueur) ;
				paladin--;
				licorne++;
				break ;
			case LICORNE:
				supprime_pion(coord) ;
				licorne--;
				break ;
		}
		afficher_placement_pions(paladin, licorne);
	}
}
