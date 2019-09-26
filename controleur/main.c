//Maxime VINCENT, Hugues GUILLEUS

#include "main.h"

int main() {
	POINT clic_menu;
	int ig = 1 ;
	COUL joueur ;

	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();
	init_plateau();
	afficher_menu();
	joueur = BLANC;

	while (TRUE) {
		clic_menu = wait_clic();
		if (est_dans_bouton_quitter(clic_menu)) {
			return 0;
		} else if (est_dans_bouton_JvsJ(clic_menu)) {
			afficher_menu_select_joueur(joueur, ig, 1);
			do {
				clic_menu = wait_clic();
				if (est_dans_bouton_ig_gauche(clic_menu)) {
					ig = (ig+2)%4 + 1 ;
					afficher_menu_select_joueur(joueur,ig,1);
				} else if (est_dans_bouton_ig_droit(clic_menu)) {
					ig = ig%4 + 1 ;
					afficher_menu_select_joueur(joueur,ig,1);
				}
			} while(!est_dans_bouton_valider(clic_menu));
			jouer_humain(ig);
			init_plateau();
			afficher_menu();
			joueur = BLANC;
		} else if (est_dans_bouton_JvsIA(clic_menu)) {
			afficher_menu_select_joueur(joueur, ig, 2);
			do {
				clic_menu = wait_clic();
				if (est_dans_bouton_coul(clic_menu)) {
					if (joueur == BLANC)
						joueur = NOIR;
					else
						joueur = BLANC;
					afficher_menu_select_joueur(joueur, ig, 2);
				} else if (est_dans_bouton_ig_gauche(clic_menu)) {
					ig = (ig+2) % 4 + 1 ;
					afficher_menu_select_joueur(joueur,ig,2);
				} else if (est_dans_bouton_ig_droit(clic_menu)) {
					ig = ig % 4 + 1 ;
					afficher_menu_select_joueur(joueur,ig,2);
				}
			} while(!est_dans_bouton_valider(clic_menu));
			jouer_ia(joueur, ig);
			init_plateau();
			afficher_menu();
			joueur = BLANC;
		}
	}
}

void jouer_humain(int ig) {
	NUMBOX boxOrigine, boxDest, coord ;
	COUL joueur = BLANC ;
	int lisere = 0;

	init_plateau();
	// positionne_pions(ig, NOIR);
	// positionne_pions(ig, BLANC);
	afficher_panneau_info();

	init_piece3_debug();

	while (TRUE) {
		afficher_panneau_jeu(ig);
		afficher_joueur_courant(joueur);
		if (selectionne_pion(joueur, lisere, NULL)) {
			afficher_plateau(ig) ;
			if (attend_clic_numbox_non_invalide(ig,&coord)) return ;
			do {
				boxOrigine = coord ;
				selectionne_pion(joueur, lisere, &boxOrigine);
				afficher_plateau(ig);
				if (attend_clic_numbox_non_invalide(ig,&coord)) return ;
				if ((gagne(boxOrigine, coord, joueur, ig))) return ;
			} while(est_pion(coord));
			boxDest = coord ;
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

void jouer_ia(COUL joueur,int ig) {

}
