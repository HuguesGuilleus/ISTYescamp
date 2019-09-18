#include "main.h"

int main(){
	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();
	
	//JOUEUR joueur1;
	//JOUEUR joueur2;
	
	
	init_plateau();
	init_piece1_debug();
	
	
	afficher_panel_score();
	afficher_panel_jeu();
	
	wait_clic();
	return(0);
}
