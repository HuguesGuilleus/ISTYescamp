#include "vue.h"


void afficher_plateau(BOX plateau[NB_BOX_PLATEAU][NB_BOX_PLATEAU]){
	POINT centreBox;
	
	int marge;
	int largeur_box = (TAILLE_PLATEAU/NB_BOX_PLATEAU);
	int x,y,cercle;
	
	for(y=0;y<NB_BOX_PLATEAU;y++){
		marge = (H_FENETRE-TAILLE_PLATEAU)/2;
		centreBox.y = marge+( largeur_box*y)+largeur_box/2;
		
		for(x=0;x<NB_BOX_PLATEAU;x++){
			marge = (L_PANEL_JEU-TAILLE_PLATEAU)/2;
			
			centreBox.x = marge+(largeur_box*x)+largeur_box/2;

			for (cercle = 0;cercle < plateau[y][x].lisere;cercle++){
				draw_circle(centreBox,(largeur_box/2)-(cercle*4),blanc);
			}
			
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
	
	draw_fill_rectangle(pBG,pHD,marron);
	affiche_all();
}
