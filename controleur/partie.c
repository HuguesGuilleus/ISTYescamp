#include "partie.h"


void jouer(){
	//COUL joueur1;
	//COUL joueur2;

	init_plateau();
	init_piece1_debug();
	afficher_panneau_info();
	afficher_panneau_jeu(1);
	wait_clic();

	init_plateau();
	init_piece2_debug();
	afficher_panneau_info();
	afficher_panneau_jeu(2);
	wait_clic();
}

POINT numBoite_to_pointBG_ig1(NUMBOITE numboxB){
	POINT P;
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);

	P.x = (numboxB.x*largeur_boite) + marge;
	P.y = (numboxB.y*largeur_boite) + marge;
	return P;
}

POINT numBoite_to_pointBG_ig2(NUMBOITE numboxB){
	POINT P;
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);

	P.x = (H_FENETRE)-((numboxB.y*largeur_boite) + marge);
	P.y = ((numboxB.x*largeur_boite) + marge);

	return P;
}

NUMBOITE attend_click_NUMBOITE(int ig) {
	NUMBOITE boite ;
	POINT clic ;
	do {
		clic = wait_clic();
		// clic.x -= (TAILLE_PLATEAU/NB_BOITE_PLATEAU)/2 ;
		// clic.y -= (TAILLE_PLATEAU/NB_BOITE_PLATEAU)/2 ;
		if (ig == 1) {
			boite = point_ig1_to_numBoite(clic) ;
		} else {
			boite = point_ig2_to_numBoite(clic) ;
		}
	} while(invalide_NUMBOITE(boite));
	return boite ;
}

// Test si les coordonées sont cooérentes. FALSE si coohérente.
BOOL invalide_NUMBOITE(NUMBOITE boite) {
	return boite.x < 0 || boite.x > 5 || boite.y < 0 || boite.y > 5 ;
}

NUMBOITE point_ig1_to_numBoite(POINT P){
	NUMBOITE boite;

	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);
	int rayon_boite = largeur_boite/2;

	boite.x = (P.x - marge)/largeur_boite;
	boite.y = (P.y - marge)/largeur_boite;
	return boite;
}

NUMBOITE point_ig2_to_numBoite(POINT P){
	NUMBOITE boite;

	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);
	int rayon_boite = largeur_boite/2;

	boite.x = (P.y - marge)/(largeur_boite);
	boite.y = 5-((P.x - marge)/(largeur_boite));

	return boite;
}
