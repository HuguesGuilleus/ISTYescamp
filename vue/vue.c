#include "vue.h"


void afficher_plateau(){
	POINT centreBoite;
	
	int marge;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);
	int rayon_boite = largeur_boite/2;
	int x,y;
	
	for(x=0;x<NB_BOITE_PLATEAU;x++){
		marge = (L_PANEL_JEU-TAILLE_PLATEAU)/2;
		
		centreBoite.x = marge+( largeur_boite*x)+rayon_boite;
		
		for(y=0;y<NB_BOITE_PLATEAU;y++){
			marge = (H_FENETRE-TAILLE_PLATEAU)/2;
			centreBoite.y = marge+(largeur_boite*y)+rayon_boite;
			
			affiche_lisere(centreBoite, plateau[x][y].lisere);
			
			if(plateau[x][y].typeP == LICORNE)
				afficher_licorne(centreBoite, plateau[x][y].coulP);
			else if(plateau[x][y].typeP == PALADIN)
				afficher_paladin(centreBoite, plateau[x][y].coulP);
			
			
		}
	}
	affiche_all();
}


void afficher_panel_score(){
	POINT pBG,pHD;
	
	pBG.x = L_PANEL_JEU;pBG.y=0;
	pHD.x = L_FENETRE;pHD.y=H_FENETRE;
	
	draw_fill_rectangle(pBG,pHD,blanc);
	affiche_all();

}

void afficher_panel_jeu(){
	POINT pBG,pHD;
	
	pBG.x = 0;pBG.y=0;
	pHD.x = L_PANEL_JEU;pHD.y=H_FENETRE;
	draw_fill_rectangle(pBG,pHD,couleur_RGB(232,210,160));
	
	pBG.x += (L_PANEL_JEU-TAILLE_PLATEAU)/2-25;pBG.y+=(H_FENETRE-TAILLE_PLATEAU)/2-25;
	pHD.x -= (L_PANEL_JEU-TAILLE_PLATEAU)/2-18;pHD.y-=(H_FENETRE-TAILLE_PLATEAU)/2-18;
	
	draw_fill_rectangle(pBG,pHD,couleur_RGB(129,116,98));
	
	afficher_plateau();
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

