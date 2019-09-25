//Maxime VINCENT, Hugues GUILLEUS

#include "main.h"

int main() {
	POINT clic_menu;
	int ig = 1;
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
			jouer(1, joueur, ig);
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
			jouer(2,joueur,ig);
			init_plateau();
			afficher_menu();
			joueur = BLANC;
		}
	}
}

void jouer(int mod,COUL joueur,int ig) {
	NUMBOX boxOrigine, boxDest, clic ;
	int lisere = 0;

	init_plateau();
	// init_piece3_debug();
	positionne_pions(ig, BLANC);
	positionne_pions(ig, NOIR);

	afficher_panneau_info();
	afficher_panneau_jeu(ig);

	while (TRUE) {
		afficher_panneau_jeu(ig);
		afficher_joueur_courant(joueur);

		if (selectionne_pion(joueur, lisere, NULL)) {
			afficher_plateau(ig);
			if (attend_clic_numbox_valide(ig,&clic))
				return ;
			do {
				boxOrigine = clic ;
				selectionne_pion(joueur, lisere, &boxOrigine);
				afficher_plateau(ig);
				if (attend_clic_numbox_valide(ig,&clic))
					return ;
				if (est_licorne_adverse(clic, joueur)) {
					boxDest = clic ;
					deplacement_simple(boxOrigine, boxDest);
					afficher_plateau(ig);
					afficher_victoire(joueur);
					wait_clic();
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
