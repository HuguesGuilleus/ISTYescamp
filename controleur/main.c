//Maxime VINCENT, Hugues GUILLEUS

#include "main.h"

int main() {
	POINT clic_menu;
	int ig = 1 ;
	COUL joueur ;

	srand(time(NULL));

	init_graphics(L_FENETRE,H_FENETRE);
	affiche_auto_off();
	init_plateau();
	afficher_menu();
	joueur = BLANC;

	while (TRUE) {
		clic_menu = wait_clic();
		if (est_dans_menu_bouton_quitter(clic_menu)) {
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
			jouer(ig, BLANC, TRUE);
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
			jouer(ig, joueur, FALSE);
			init_plateau();
			afficher_menu();
			joueur = BLANC;
		}
	}
}

void jouer(int ig, COUL joueur, BOOL JvsJ) {
	NUMBOX boxOrigine, boxDest, coord ;
	int lisere = 0;
	BOOL perdu = TRUE ;
	POINT clic ;
	COUL ia = NOIR;

	init_plateau();
	if (JvsJ) {
		positionne_pions(ig, NOIR);
		positionne_pions(ig, BLANC);
	} else {
		if (joueur == NOIR){
			ia = BLANC;
			positionne_pions(ig, joueur);
			positionne_pions_ia(ia, ig);
		} else {
			positionne_pions_ia(ia, ig);
			positionne_pions(ig, joueur);
		}
	}

	afficher_panneau_info();
	afficher_panneau_jeu(ig);
	do {
		change_joueur(&joueur);
		if (JvsJ || joueur != ia) {
			afficher_joueur_courant(joueur);
			if (peut_selectionner_pion(joueur, lisere)) {
				afficher_plateau(ig) ;
				clic = attend_clic_quitter_ou_case_non_invalide(ig) ;
				if (est_dans_bouton_quitter(clic))
					return ;
				coord = point_ig_to_numBoite(ig,clic) ;
				do {
					boxOrigine = coord ;
					selectionne_case_accessible(joueur, lisere, boxOrigine);
					afficher_plateau(ig);
					clic = attend_clic_quitter_ou_case_non_invalide(ig) ;
					if (est_dans_bouton_quitter(clic))
						return ;
					coord = point_ig_to_numBoite(ig,clic) ;
				} while(est_pion_joueur_courant(coord, joueur));
				boxDest = coord ;
				if (est_licorne_adverse(boxDest, joueur)) {
					perdu = FALSE ;
				}
				deplacement_simple(boxOrigine, boxDest);
				lisere = change_lisere(boxDest);
			} else {
				afficher_plateau(ig);
				afficher_coups_impossible();
				wait_clic();
			}
		} else {
			if (lancer_tour_ia(ia,lisere,ig))
				perdu = FALSE ;
		}
	} while (perdu) ;
	afficher_plateau(ig);
	afficher_victoire(joueur);
	wait_clic();
}
