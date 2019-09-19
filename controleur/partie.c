#include "partie.h"

POINT numBoite_to_pointBG_ig1(NUMBOX numboxB){
	POINT P;
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);

	P.x = (numboxB.c*largeur_boite) + marge;
	P.y = (numboxB.l*largeur_boite) + marge;
	return P;
}

POINT numBoite_to_pointBG_ig2(NUMBOX numboxB){
	POINT P;
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);

	P.x = (H_FENETRE-largeur_boite)-((numboxB.l*largeur_boite) + marge);
	P.y = ((numboxB.c*largeur_boite) + marge);

	return P;
}

NUMBOX attend_clic_numbox(int ig) {
	POINT clic;

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

NUMBOX point_ig1_to_numBoite(POINT P){
	NUMBOX boite;

	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);

	boite.c = (P.x - marge)/largeur_boite;
	boite.l = (P.y - marge)/largeur_boite;
	return boite;
}

NUMBOX point_ig2_to_numBoite(POINT P){
	NUMBOX boite;

	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);

	boite.c = (P.y - marge)/(largeur_boite);
	boite.l = 5-((P.x - marge)/(largeur_boite));

	return boite;
}
