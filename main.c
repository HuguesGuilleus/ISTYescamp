#include "main.h"

int main(){
	int ig = 1 ;
	NUMBOX boiteOrigine, boiteDest ;

	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();

	init_piece1_debug();
	afficher_panneau_info();
	afficher_panneau_jeu(ig);
	//jouer();

	while (TRUE) {
		boiteOrigine = attend_click_numbox(ig);
		boiteDest    = attend_click_numbox(ig);
		deplacement_simple(boiteOrigine, boiteDest);
		afficher_plateau(ig);
	}
}
