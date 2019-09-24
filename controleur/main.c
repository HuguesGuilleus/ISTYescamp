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
			afficher_menu_select_joueur(joueur,ig,1);

			while(!go){
				clic_menu = wait_clic();

				if(est_dans_bouton_valider(clic_menu)){
					go = TRUE;
				}else if(est_dans_bouton_ig(clic_menu)){
					if (est_dans_bouton_ig_gauche(clic_menu))
						ig = (((ig-1)+3)%4)+1;
					else
						ig = (ig%4)+1;

					afficher_menu_select_joueur(joueur,ig,1);
				}
			}
			jouer(1,joueur,ig);
		}else if(est_dans_bouton_JvsIA(clic_menu)){
			afficher_menu_select_joueur(joueur,ig,2);

			while(!go){
				clic_menu = wait_clic();

				if(est_dans_bouton_valider(clic_menu)){
					go = TRUE;
				}else if(est_dans_bouton_coul(clic_menu)){
					if (joueur == BLANC)
					joueur = NOIR;
					else
					joueur = BLANC;
					afficher_menu_select_joueur(joueur,ig,2);
				}else if(est_dans_bouton_ig(clic_menu)){
					if (est_dans_bouton_ig_gauche(clic_menu))
						ig = (((ig-1)+3)%4)+1;
					else
						ig = (ig%4)+1;

					afficher_menu_select_joueur(joueur,ig,2);
				}
			}
			jouer(2,joueur,ig);
		}
	}
}

void jouer(int mod,COUL joueur,int ig) {
	NUMBOX boxOrigine, boxDest, clic ;
	int lisere = 0;

	init_piece3_debug();

	afficher_panneau_info();
	afficher_panneau_jeu(ig);

	while (TRUE) {
		afficher_joueur_courant(joueur);

		if (selectionne_pion(joueur, lisere, NULL)) {
			afficher_plateau(ig);
			clic = attend_click_non_invalide(ig);
			do {
				boxOrigine = clic ;
				selectionne_pion(joueur, lisere, &boxOrigine);
				afficher_plateau(ig);
				clic = attend_click_non_invalide(ig);
				if (est_licorne_adverse(clic, joueur)) {
					printf("\e[01;32mVous avez gagné (%d)\e[0m\n", joueur);
					return ;
				}
			} while(est_pion(clic));

			boxDest = clic ;
			deplacement_simple(boxOrigine, boxDest);
			lisere = change_lisere(boxDest);

		} else {
			afficher_plateau(ig);
			afficher_coups_impossible();
			wait_clic();
		}

		change_joueur(&joueur);
	}
}
