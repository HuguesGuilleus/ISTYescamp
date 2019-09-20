#include "vue.h"


void afficher_plateau(int ig){
	POINT centreBoite;
	NUMBOITE boite;
	
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);
	int rayon_boite = largeur_boite/2;
	int x,y;
	
	for(x=0;x<NB_BOITE_PLATEAU;x++){
		centreBoite.x = marge+( largeur_boite*x)+rayon_boite;
		
		for(y=0;y<NB_BOITE_PLATEAU;y++){
			centreBoite.y = marge+(largeur_boite*y)+rayon_boite;
			
			if (ig == 1)
				boite = point_ig1_to_numBoite(centreBoite);
			else
				boite = point_ig2_to_numBoite(centreBoite);
				
			affiche_lisere(centreBoite, plateau[boite.x][boite.y].lisere);
			
			if(plateau[boite.x][boite.y].typeP == LICORNE)
				afficher_licorne(centreBoite, plateau[boite.x][boite.y].coulP);
			else if(plateau[boite.x][boite.y].typeP == PALADIN)
				afficher_paladin(centreBoite, plateau[boite.x][boite.y].coulP);
			
			
		}
	}
	affiche_all();
}


void afficher_panel_score(){
	POINT pBG,pHD;
	
	pBG.x = H_FENETRE;pBG.y=0;
	pHD.x = L_FENETRE;pHD.y=H_FENETRE;
	
	draw_fill_rectangle(pBG,pHD,blanc);
	affiche_all();

}

void afficher_panel_jeu(int ig){
	POINT pBG,pHD;
	
	pBG.x = 0;pBG.y=0;
	pHD.x = H_FENETRE;pHD.y=H_FENETRE;
	draw_fill_rectangle(pBG,pHD,couleur_RGB(232,210,160));
	
	pBG.x += (H_FENETRE-TAILLE_PLATEAU)/2-25;pBG.y+=(H_FENETRE-TAILLE_PLATEAU)/2-25;
	pHD.x -= (H_FENETRE-TAILLE_PLATEAU)/2-18;pHD.y-=(H_FENETRE-TAILLE_PLATEAU)/2-18;
	
	draw_fill_rectangle(pBG,pHD,couleur_RGB(129,116,98));
	
	afficher_plateau(ig);
}

void afficher_licorne(POINT centre, COUL coul){
	COULEUR pCouleur = noir;
	
	if (coul == BLANC)
		pCouleur = blanc;
	else if(coul == NOIR)
		pCouleur = noir;
		
	draw_fill_circle(centre,10,pCouleur);
}

void afficher_paladin(POINT centre, COUL coul){
	COULEUR pCouleur = noir;
	
	if (coul == BLANC)
		pCouleur = blanc;
	else if(coul == NOIR)
		pCouleur = noir;
		
	draw_fill_circle(centre,5,pCouleur);

}

void affiche_lisere(POINT centre, int nbLisere){
	int cercle;
	int rayon_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU)/2;
	
	for (cercle = 0;cercle < nbLisere;cercle++){
		draw_circle(centre,rayon_boite-(cercle*4),blanc);
	}
	
	
}

