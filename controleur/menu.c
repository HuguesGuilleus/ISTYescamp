#include "menu.h"

/***** MENU *****/

BOOL est_dans_bouton_quitter(POINT clic){
	return (clic.y >= 50 && clic.y <= 150 && clic.x <= (L_FENETRE-50) && clic.x >= 50);
}

BOOL est_dans_bouton_JvsJ(POINT clic){
	return (clic.y >= 350 && clic.y <= 450 && clic.x <= (L_FENETRE-50) && clic.x >= 50);
}

BOOL est_dans_bouton_JvsIA(POINT clic){
	return (clic.y >= 200 && clic.y <= 300 && clic.x <= (L_FENETRE-50) && clic.x >= 50);

}

BOOL est_dans_bouton_valider(POINT clic){
	return (clic.y >= 50 && clic.y <= 150 && clic.x <= (L_FENETRE-50) && clic.x >= 50);
}

BOOL est_dans_bouton_ig_gauche(POINT clic) {
	return clic.y >= 350 && clic.y <= 450 && clic.x <= 100 && clic.x >= 50 ;
}

BOOL est_dans_bouton_ig_droit(POINT clic) {
	return clic.y >= 350 && clic.y <= 450 && clic.x <= (L_FENETRE-50) && clic.x >= (L_FENETRE-100) ;
}

BOOL est_dans_bouton_coul(POINT clic){
	return (clic.y >= 200 && clic.y <= 300 && ( (clic.x <= 100 && clic.x >= 50) || (clic.x <= (L_FENETRE-50) && clic.x >= (L_FENETRE-100))));
}

POINT numBoite_to_pointBG_ig_mini(int ig, NUMBOX numboxB){
	POINT P;
	int largeur_box = 20;
	int margeX = (L_FENETRE-(largeur_box*6))/2;
	int margeY = (H_FENETRE-(largeur_box*6))/2+100;


	switch(ig){
		case 1:
			P.x = (numboxB.c*largeur_box) + margeX;
			P.y = (numboxB.l*largeur_box) + margeY;
			break;
		case 2:
			P.x = (L_FENETRE-largeur_box)-((numboxB.l*largeur_box) + margeX);
			P.y = ((numboxB.c*largeur_box) + margeY);
			break;
		case 3:
			P.x = (L_FENETRE-largeur_box)-((numboxB.c*largeur_box) + margeX);
			P.y = (H_FENETRE-largeur_box)-((numboxB.l*largeur_box) + margeY)+200;
			break;
		case 4:
			P.x = (numboxB.l*largeur_box) + margeX;
			P.y = (H_FENETRE-largeur_box)-((numboxB.c*largeur_box) + margeY)+200;
			break;
	}

	return P;
}
