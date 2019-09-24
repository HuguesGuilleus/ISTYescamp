//Maxime VINCENT, Hugues GUILLEUS

#include "main.h"

int main(){
	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();

	POINT clic_menu;
	BOOL go = FALSE;
	int ig = 1;
	COUL joueur = BLANC;

	afficher_menu();

	while(TRUE){
		clic_menu = wait_clic();
		if (est_dans_bouton_quitter(clic_menu)){
			return 0;
		}else if(est_dans_bouton_JvsJ(clic_menu)){
			afficher_menu_select_joueur(joueur,ig);

			while(!go){
				clic_menu = wait_clic();

				if(est_dans_bouton_valider(clic_menu)){
					go = TRUE;
				}else if(est_dans_bouton_coul(clic_menu)){
					if (joueur == BLANC)
					joueur = NOIR;
					else
					joueur = BLANC;
					afficher_menu_select_joueur(joueur,ig);
				}else if(est_dans_bouton_ig(clic_menu)){
					if (ig == 1)
					ig = 2;
					else
					ig = 1;
					afficher_menu_select_joueur(joueur,ig);
				}
			}
			jouer("j",joueur,ig);
		}else if(est_dans_bouton_JvsIA(clic_menu)){
			jouer("ia",joueur,ig);
		}
	}
}

void jouer(char * mod,COUL joueur,int ig) {
	NUMBOX boxOrigine, boxDest, clic ;
	int lisere = 0;

	init_piece1_debug();

	afficher_panneau_info();
	afficher_panneau_jeu(ig);

	while (TRUE) {
		
		
		selectionne_pion(joueur,lisere, NULL);
		afficher_plateau(ig);
		
		afficher_coups_impossible();
		wait_clic();
		
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
