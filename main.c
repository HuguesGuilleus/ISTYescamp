#include "main.h"

int main(){
	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();
	
	BOX plateau [6][6];
	
	init_plateau(plateau);
	init_piece1_debug(plateau);

	afficher_panel_score();
	afficher_panel_jeu(plateau);
	
	wait_clic();
	return(0);
}
