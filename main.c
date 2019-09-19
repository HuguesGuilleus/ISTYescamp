//Maxime VINCENT, Hugues GUILLEUS

#include "main.h"

int main(){
	int ig = 2 ;
	NUMBOX boiteOrigine, boiteDest ;

	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();

	init_piece1_debug();

	afficher_panneau_info();
	afficher_panneau_jeu(ig);

	while (TRUE) {
		do{
			boiteOrigine = attend_clic_numbox(ig);
		}while(est_numbox_vide(boiteOrigine));
		boiteDest = attend_clic_numbox(ig);
		deplacement_simple(boiteOrigine, boiteDest);

		afficher_lisere_pion(ig, boiteOrigine);
		afficher_lisere_pion(ig, boiteDest);
		affiche_all();
	}
}
