//Maxime VINCENT, Hugues GUILLEUS

#include "main.h"

int main(){
	int ig = 2 ;
	NUMBOX boxOrigine, boxDest ;

	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();

	init_piece1_debug();
	//init_piece2_debug();

	afficher_panneau_info();
	afficher_panneau_jeu(ig);
	
	while (TRUE) {
		selectionne_pion(BLANC, 1);
		afficher_plateau(ig);
		do{
			boxOrigine = attend_clic_numbox(ig);
		}while(est_numbox_vide(boxOrigine));
		boxDest = attend_clic_numbox(ig);
		deplacement_simple(boxOrigine, boxDest);

		afficher_lisere_pion(ig, boxOrigine);
		afficher_lisere_pion(ig, boxDest);
		affiche_all();
	}
}
