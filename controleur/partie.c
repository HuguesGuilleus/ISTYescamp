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
	int rayon_boite = largeur_boite/2;
	
	P.x = (numboxB.x*largeur_boite) + marge+rayon_boite;
	P.y = (numboxB.y*largeur_boite) + marge+rayon_boite;
	return P;
}

POINT numBoite_to_pointBG_ig2(NUMBOITE numboxB){
	POINT P;
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);
	int rayon_boite = largeur_boite/2;
	
	P.x = (H_FENETRE)-((numboxB.y*largeur_boite) + marge+rayon_boite);
	P.y = ((numboxB.x*largeur_boite) + marge+rayon_boite);
	
	return P;
}

NUMBOITE point_ig1_to_numBoite(POINT P){
	NUMBOITE boite;
	
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);
	int rayon_boite = largeur_boite/2;
	
	boite.x = (P.x - marge-rayon_boite)/largeur_boite;
	boite.y = (P.y - marge-rayon_boite)/largeur_boite;
	return boite;
}

NUMBOITE point_ig2_to_numBoite(POINT P){
	NUMBOITE boite;
	
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);
	int rayon_boite = largeur_boite/2;
	
	boite.x = (P.y - marge-rayon_boite)/(largeur_boite);
	boite.y = 5-((P.x - marge-rayon_boite)/(largeur_boite));
	
	return boite;
}


