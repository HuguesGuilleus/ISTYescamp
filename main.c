#include "main.h"

int main(){
	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();


	afficher_panel_score();
	afficher_panel_jeu();
	afficher_plateau();
		
	wait_clic();
	return(0);
}
