//Maxime VINCENT, Hugues GUILLEUS

#include "partie.h"

void positionne_pions(int ig, COUL joueur) {
	POINT clic ;
	NUMBOX coord ;
	int paladin = 0, licorne = 0 ;

	init_case_accessible_position(ig, joueur);

	afficher_panneau_jeu(ig);
	afficher_panneau_info();
	afficher_joueur_courant(joueur);
	afficher_pion_info(joueur);

	while (TRUE) {
		afficher_placement_pions(paladin, licorne);
		afficher_plateau(ig);
		affiche_all();
		do {
			clic = wait_clic();
			if (estDans_btn_info(clic) && licorne == 1 && paladin == 5) {
				return ;
			}
			coord = point_ig_to_numBoite(ig, clic);
		} while(estHors_plateau(clic) || !est_accessible_positionnement(coord, ig, joueur));
		switch (plateau[coord.c][coord.l].typeP) {
			case VIDE:
				ajoute_paladin(coord,joueur) ;
				paladin++;
				break ;
			case PALADIN:
				ajoute_licorne(coord,joueur) ;
				paladin--;
				licorne++;
				break ;
			case LICORNE:
				supprime_pion(coord) ;
				licorne--;
				break ;
		}
	}
}

BOOL test_perdre(NUMBOX dest, COUL joueur) {
	return est_licorne_adverse(dest, joueur) ;
}

// Teste si le pion va sur la licorne adverse, si
BOOL gagne(NUMBOX origine, NUMBOX dest, COUL joueur, int ig) {
	if (est_licorne_adverse(dest, joueur)) {
		deplacement_simple(origine, dest);
		afficher_plateau(ig);
		afficher_victoire(joueur);
		wait_clic();
		return TRUE ;
	} else {
		return FALSE ;
	}
}

POINT attend_clic_quitter_ou_case_non_invalide(int ig) {
	POINT c ;
	NUMBOX b ;

	do {
		c = wait_clic() ;
		b = point_ig_to_numBoite(ig, c) ;
	} while( !est_dans_bouton_quitter(c) && ( estHors_plateau(c) || !est_pas_invalide(b) ) );

	return c ;
}

// Modifie box au premier clic dans une case non invalide ou
// renvoie TRUE si le clic est dans le bouton quitter.
BOOL attend_clic_numbox_non_invalide(int ig, NUMBOX* box) {
	POINT clic;

	do {
		clic = wait_clic();
		if (estDans_btn_info(clic)){
			return TRUE ;
		}
		*box = point_ig_to_numBoite(ig,clic) ;
	} while(estHors_plateau(clic) || !est_pas_invalide(*box));

	return FALSE;
}

BOOL estHors_plateau(POINT click) {
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int finPlateau = marge + TAILLE_PLATEAU ;

	return click.x < marge || finPlateau < click.x ||
		click.y < marge || finPlateau < click.y ;
}

BOOL estDans_btn_info(POINT p) {
	return p.x > H_FENETRE+50 && p.x < L_FENETRE-50 && p.y > 50 && p.y < 100;
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
