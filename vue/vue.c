#include "vue.h"


void afficher_plateau(BOITE plateau[NB_BOITE_PLATEAU][NB_BOITE_PLATEAU]){
	POINT centreBoite;
	
	int marge;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);
	int rayon_boite = largeur_boite/2;
	int x,y,cercle;
	
	for(x=0;x<NB_BOITE_PLATEAU;x++){
		marge = (L_PANEL_JEU-TAILLE_PLATEAU)/2;
		
		centreBoite.x = marge+( largeur_boite*x)+rayon_boite;
		
		for(y=0;y<NB_BOITE_PLATEAU;y++){
			marge = (H_FENETRE-TAILLE_PLATEAU)/2;
			
			centreBoite.y = marge+(largeur_boite*y)+rayon_boite;

			for (cercle = 0;cercle < plateau[x][y].lisere;cercle++){
				draw_circle(centreBoite,rayon_boite-(cercle*4),blanc);
			}
			
			if(plateau[x][y].typeP == LICORNE)
				afficher_licorne(plateau[x][y].coulP,centreBoite);
			else if(plateau[x][y].typeP == PALADIN)
				afficher_paladin(plateau[x][y].coulP,centreBoite);
			
			
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

void afficher_panel_jeu(BOITE plateau[NB_BOITE_PLATEAU][NB_BOITE_PLATEAU]){
	POINT pBG,pHD;
	
	pBG.x = 0;pBG.y=0;
	pHD.x = L_PANEL_JEU;pHD.y=H_FENETRE;
	draw_fill_rectangle(pBG,pHD,couleur_RGB(232,210,160));
	
	pBG.x += (L_PANEL_JEU-TAILLE_PLATEAU)/2-25;pBG.y+=(H_FENETRE-TAILLE_PLATEAU)/2-25;
	pHD.x -= (L_PANEL_JEU-TAILLE_PLATEAU)/2-18;pHD.y-=(H_FENETRE-TAILLE_PLATEAU)/2-18;
	
	draw_fill_rectangle(pBG,pHD,couleur_RGB(129,116,98));
	
	afficher_plateau(plateau);
}

void afficher_licorne(COUL coul,POINT centre){
	COULEUR pCouleur = noir;
	
	if (coul == BLANC)
		pCouleur = blanc;
	else if(coul == NOIR)
		pCouleur = noir;
		
	draw_fill_circle(centre,10,pCouleur);
}

void afficher_paladin(COUL coul,POINT centre){
	COULEUR pCouleur = noir;
	
	if (coul == BLANC)
		pCouleur = blanc;
	else if(coul == NOIR)
		pCouleur = noir;
		
	draw_fill_circle(centre,5,pCouleur);

}

