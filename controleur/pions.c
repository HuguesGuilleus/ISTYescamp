#include "pions.h"

void positionne_pions(int ig, COUL joueur) {
	NUMBOX clic ;
	int paladin = 0, licorne = 0 ;

	afficher_panneau_jeu(ig);
	afficher_panneau_info();
	afficher_joueur_courant(joueur);
	while (TRUE) {
		afficher_plateau(ig);
		affiche_all();
		clic = attend_clic_numbox(ig);
		switch (plateau[clic.c][clic.l].typeP) {
			case VIDE:
				ajoute_paladin(clic,joueur) ;
				paladin++;
				break ;
			case PALADIN:
				ajoute_licorne(clic,joueur) ;
				paladin--;
				licorne++;
				break ;
			case LICORNE:
				supprime_pion(clic) ;
				licorne--;
				break ;
		}
		afficher_placement_pions(paladin, licorne);
	}
}
