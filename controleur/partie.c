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

	P.x = (H_FENETRE-largeur_boite)-((numboxB.y*largeur_boite) + marge);
	P.y = ((numboxB.x*largeur_boite) + marge);

	return P;
}

NUMBOITE attend_click_NUMBOITE(int ig) {
	POINT clic ;

	do {
		clic = wait_clic();
	} while(estHors_plateau(clic));

	if (ig == 1) {
		return point_ig1_to_numBoite(clic) ;
	} else {
		return point_ig2_to_numBoite(clic) ;
	}
}

// Teste si les coordonées d'un point (comme un clic) sont dans le plateau.
BOOL estHors_plateau(POINT click) {
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int finPlateau = marge + TAILLE_PLATEAU ;

	return click.x < marge || finPlateau < click.x ||
		click.y < marge || finPlateau < click.y ;
}

NUMBOITE point_ig1_to_numBoite(POINT P){
	NUMBOITE boite;

	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);

	boite.x = (P.x - marge)/largeur_boite;
	boite.y = (P.y - marge)/largeur_boite;
	return boite;
}

NUMBOITE point_ig2_to_numBoite(POINT P){
	NUMBOITE boite;

	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);

	boite.x = (P.y - marge)/(largeur_boite);
	boite.y = 5-((P.x - marge)/(largeur_boite));

	return boite;
}
