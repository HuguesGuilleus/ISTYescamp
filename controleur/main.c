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

void jouer(char * mod,COUL joueur,int ig){
	NUMBOX boxOrigine, boxDest ;

	//init_piece1_debug();
	init_piece2_debug();

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
