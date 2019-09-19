//Maxime VINCENT, Hugues GUILLEUS

#include "main.h"

int main(){

	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();

	POINT clic_menu;
	afficher_menu();
	
	while(TRUE){
		clic_menu = wait_clic();
		if (est_dans_bouton_quitter(clic_menu)){
			return 0;
		}else if(est_dans_bouton_JvsJ(clic_menu)){
			jouer("j");
		}else if(est_dans_bouton_JvsIA(clic_menu)){
			jouer("ia");
		}
	}

}

void jouer(char * mod){
	int ig = 2;
	NUMBOX boxOrigine, boxDest ;

	init_piece1_debug();
	//init_piece2_debug();

	afficher_panneau_info();
	afficher_panneau_jeu(ig);

	while (TRUE) {
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
