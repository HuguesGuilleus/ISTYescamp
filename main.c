#include "main.h"

int main(){
	int ig = 1 ;
	NUMBOITE boiteOrigine, boiteDest ;

	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();

	init_piece1_debug();
	afficher_panneau_info();
	afficher_panneau_jeu(ig);
	//jouer();

	while (TRUE) {
		boiteOrigine = attend_click_NUMBOITE(ig);
		printf("boite: (%d,%d)\n", boiteOrigine.x, boiteOrigine.y ); /////////////////
		boiteDest    = attend_click_NUMBOITE(ig);
		printf("boite: (%d,%d)\n", boiteDest.x, boiteDest.y ); /////////////////
		deplacement_simple(boiteOrigine, boiteDest);
		afficher_plateau(ig);
	}
}
