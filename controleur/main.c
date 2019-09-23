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
	int ig = 1 ;
	NUMBOX boxOrigine, boxDest, clic ;
	COUL joueur = BLANC ;
	int lisere = 0;

	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();

	init_piece1_debug();
	//init_piece2_debug();

	afficher_panneau_info();
	afficher_panneau_jeu(ig);

	while (TRUE) {
		printf("*** Début du tour\n");
		selectionne_pion(joueur,lisere, NULL);
		afficher_plateau(ig);

		clic = attend_click_non_invalide(ig);

		do {
			boxOrigine = clic ;
			printf("boxOrigine: ");
			imprime_numbox(boxOrigine);

			selectionne_pion(joueur,lisere, &boxOrigine);
			selection_possibilite(boxOrigine);
			afficher_plateau(ig);
			clic = attend_click_non_invalide(ig);
		} while(est_pion(clic));

		printf("*** fin du do while\n");

		boxDest = clic ;
		deplacement_simple(boxOrigine, boxDest);

		// deplacement_simple(boxOrigine, boxDest);
		// afficher_lisere_pion(ig, boxOrigine);
		// afficher_lisere_pion(ig, boxDest);
		// afficher_plateau(ig);

		lisere = change_lisere(boxDest);
		change_joueur(&joueur);
	}
}
