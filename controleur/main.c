//Maxime VINCENT, Hugues GUILLEUS

#include "main.h"

NUMBOX attend_click_non_invalide(int ig) {
	NUMBOX b ;
	do {
		b = attend_clic_numbox(ig);
	} while(!est_pas_invalide(b));
	return b ;
}

int main(){
	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();
	jouer();
}


void jouer(void) {
	int ig = 1 ;
	NUMBOX boxOrigine, boxDest, clic ;
	COUL joueur = BLANC ;
	int lisere = 0;

	init_piece1_debug();
	//init_piece2_debug();

	afficher_panneau_info();
	afficher_panneau_jeu(ig);

	while (TRUE) {
		selectionne_pion(joueur,lisere, NULL);
		afficher_plateau(ig);

		clic = attend_click_non_invalide(ig);

		do {
			boxOrigine = clic ;

			selectionne_pion(joueur,lisere, &boxOrigine);
			selection_possibilite(boxOrigine);
			afficher_plateau(ig);
			clic = attend_click_non_invalide(ig);
		} while(est_pion(clic));

		boxDest = clic ;
		deplacement_simple(boxOrigine, boxDest);

		lisere = change_lisere(boxDest);
		change_joueur(&joueur);
	}
}
