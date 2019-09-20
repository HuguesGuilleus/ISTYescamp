#include "partie.h"


void jouer(){
	//COUL joueur1;
	//COUL joueur2;
	
	init_plateau();
	init_piece1_debug();
	
	
	afficher_panel_score();
	afficher_panel_jeu(1);
	
	wait_clic();
	
	init_plateau();
	init_piece1_debug();
	
	
	afficher_panel_score();
	afficher_panel_jeu(2);
	
	wait_clic();
	
	
}

POINT numBoite_to_pointBG_ig1(NUMBOITE numboxB){
	POINT a;
	a.x = 0;
	a.y = 0;
	return a;
}
POINT numBoite_to_pointBG_ig2(NUMBOITE numboxB){
	POINT a;
	a.x = 0;
	a.y = 0;
	return a;
}

NUMBOITE point_ig1_to_numBoite(POINT P){
	NUMBOITE a;
	
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);
	int rayon_boite = largeur_boite/2;
	
	a.x = (P.x - marge-rayon_boite)/largeur_boite;
	a.y = (P.y - marge-rayon_boite)/largeur_boite;
	return a;
}

NUMBOITE point_ig2_to_numBoite(POINT P){
	NUMBOITE a;
	
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);
	int rayon_boite = largeur_boite/2;
	
	a.x = ((P.x - marge-rayon_boite)/(largeur_boite));
	a.y = ((P.y - marge-rayon_boite)/(largeur_boite));
	
	return a;
}


