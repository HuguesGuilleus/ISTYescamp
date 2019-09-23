//Maxime VINCENT, Hugues GUILLEUS

#include "partie.h"


NUMBOX attend_clic_numbox(int ig) {
	POINT clic;

	do {
		clic = wait_clic();
	} while(estHors_plateau(clic));

	return point_ig_to_numBoite(ig,clic) ;

}

NUMBOX attend_click_non_invalide(int ig) {
	NUMBOX b ;
	do {
		b = attend_clic_numbox(ig);
	} while(!est_pas_invalide(b));
	return b ;
}

// Teste si les coordonées d'un point (comme un clic) sont dans le plateau.
BOOL estHors_plateau(POINT click) {
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int finPlateau = marge + TAILLE_PLATEAU ;

	return click.x < marge || finPlateau < click.x ||
		click.y < marge || finPlateau < click.y ;
}

POINT numBoite_to_pointBG_ig(int ig, NUMBOX numboxB){
	POINT P;
	P.x=0;P.y=0;
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_box = (TAILLE_PLATEAU/NB_BOX_PLATEAU);
	
	switch(ig){
		case 1:
			P.x = (numboxB.c*largeur_box) + marge;
			P.y = (numboxB.l*largeur_box) + marge;
			break;
		case 2:
			P.x = (H_FENETRE-largeur_box)-((numboxB.l*largeur_box) + marge);
			P.y = ((numboxB.c*largeur_box) + marge);
			break;
		case 3:
			P.x = (H_FENETRE-largeur_box)-((numboxB.c*largeur_box) + marge);
			P.y = (H_FENETRE-largeur_box)-((numboxB.l*largeur_box) + marge);
			break;
		case 4:
			P.x = (numboxB.l*largeur_box) + marge;
			P.y = (H_FENETRE-largeur_box)-((numboxB.c*largeur_box) + marge);
			break;
	}
	
	return P;
}
NUMBOX point_ig_to_numBoite(int ig, POINT P){
	NUMBOX box;
	box.c=0;box.l=0;
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_box = (TAILLE_PLATEAU/NB_BOX_PLATEAU);
	
	switch(ig){
		case 1:
			box.c = (P.x - marge)/largeur_box;
			box.l = (P.y - marge)/largeur_box;
			break;
		case 2:
			box.c = (P.y - marge)/(largeur_box);
			box.l = (NB_BOX_PLATEAU-1)-((P.x - marge)/(largeur_box));
			break;
		case 3:
			box.c = (NB_BOX_PLATEAU-1)-((P.x - marge)/(largeur_box));
			box.l = (NB_BOX_PLATEAU-1)-((P.y - marge)/(largeur_box));
			break;
		case 4:
			box.c = (NB_BOX_PLATEAU-1)-((P.y - marge)/(largeur_box));
			box.l = (P.x - marge)/(largeur_box);
			break;
	}
	
	return box;
}
