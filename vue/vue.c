#include "vue.h"

//Prend en paramètre un entier 1 ou 2, pour a l'interface graphique (rotation plateau)
//Affiche les boites du plateau, les paladins et les licornes
void afficher_plateau(int ig){
	
	int marge = (H_FENETRE-TAILLE_PLATEAU)/2;
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);
	int rayon_boite = largeur_boite/2;
	int x,y;
	
	POINT pBG,pHD;
	pBG.x = (H_FENETRE-TAILLE_PLATEAU)/2;
	pBG.y=(H_FENETRE-TAILLE_PLATEAU)/2;
	pHD.x = H_FENETRE-((H_FENETRE-TAILLE_PLATEAU)/2);
	pHD.y=H_FENETRE-((H_FENETRE-TAILLE_PLATEAU)/2);
	draw_fill_rectangle(pBG,pHD,couleur_RGB(129,116,98));
	
	POINT centreBoite;
	NUMBOITE boite;
	
	for(x=0;x<NB_BOITE_PLATEAU;x++){
		centreBoite.x = marge+( largeur_boite*x)+rayon_boite;
		
		for(y=0;y<NB_BOITE_PLATEAU;y++){
			centreBoite.y = marge+(largeur_boite*y)+rayon_boite;
			
			if (ig == 1)
				boite = point_ig1_to_numBoite(centreBoite);
			else
				boite = point_ig2_to_numBoite(centreBoite);
			
			affiche_lisere(centreBoite, plateau[boite.x][boite.y].lisere);
			
			switch (plateau[boite.x][boite.y].typeP){
				case LICORNE:
					afficher_licorne(centreBoite, plateau[boite.x][boite.y].coulP);
					break;
				case PALADIN:
					afficher_paladin(centreBoite, plateau[boite.x][boite.y].coulP);
					break;
				default:
					break;
			}
		}
	}
	affiche_all();
}

//Affiche le 
void afficher_panneau_info(){
	POINT pBG,pHD;
	
	pBG.x = H_FENETRE;pBG.y=0;
	pHD.x = L_FENETRE;pHD.y=H_FENETRE;
	
	draw_fill_rectangle(pBG,pHD,blanc);
	affiche_all();

}

void afficher_panneau_jeu(int ig){
	POINT pBG,pHD;
	
	pBG.x = 0;pBG.y=0;
	pHD.x = H_FENETRE;pHD.y=H_FENETRE;
	draw_fill_rectangle(pBG,pHD,couleur_RGB(232,210,160));
	
	pBG.x += (H_FENETRE-TAILLE_PLATEAU)/2-25;
	pBG.y+=(H_FENETRE-TAILLE_PLATEAU)/2-25;
	pHD.x -= (H_FENETRE-TAILLE_PLATEAU)/2-20;
	pHD.y-=(H_FENETRE-TAILLE_PLATEAU)/2-20;
	
	draw_fill_rectangle(pBG,pHD,couleur_RGB(129,116,98));
	
	afficher_legende_plateau(ig);
	
	
	afficher_plateau(ig);
}

void afficher_legende_plateau(int ig){
	int i;
	POINT pLettre,pChiffre;
	char lettre[2];
	int largeur_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU);
	
	for(i=0;i<NB_BOITE_PLATEAU;i++){
		lettre[0] = ('A'+i);
		if (ig == 1){
			pLettre.x = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_boite)+largeur_boite/2-3;
			pChiffre.y = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_boite)+largeur_boite/2+6;
		
			pLettre.y = (H_FENETRE-TAILLE_PLATEAU)/2-6;
			pChiffre.x = (H_FENETRE-TAILLE_PLATEAU)/2-18;
			aff_pol(lettre, 12, pLettre, blanc);
			aff_int((i+1), 12, pChiffre, blanc);

			pLettre.y = H_FENETRE-(H_FENETRE-TAILLE_PLATEAU)/2+20;
			pChiffre.x = H_FENETRE-(H_FENETRE-TAILLE_PLATEAU)/2+5;
			aff_pol(lettre, 12, pLettre, blanc);
			aff_int((i+1), 12, pChiffre, blanc);
		}else if (ig == 2){
			pLettre.y = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_boite)+largeur_boite/2+6;
			pChiffre.x = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_boite)+largeur_boite/2-3;
		
			pLettre.x = (H_FENETRE-TAILLE_PLATEAU)/2-18;
			pChiffre.y = (H_FENETRE-TAILLE_PLATEAU)/2-6;
			aff_pol(lettre, 12, pLettre, blanc);
			aff_int((NB_BOITE_PLATEAU-i), 12, pChiffre, blanc);

			pLettre.x = H_FENETRE-(H_FENETRE-TAILLE_PLATEAU)/2+5;
			pChiffre.y = H_FENETRE-(H_FENETRE-TAILLE_PLATEAU)/2+20;
			aff_pol(lettre, 12, pLettre, blanc);
			aff_int((NB_BOITE_PLATEAU-i), 12, pChiffre, blanc);
		}
	}
}

void afficher_licorne(POINT centre, COUL coul){
	COULEUR pCouleur = noir;
	
	if (coul == BLANC)
		pCouleur = blanc-(0x646464);
	else if(coul == NOIR)
		pCouleur = noir;
	
	int i;
	for(i = 20;i>5;i--){
		pCouleur += 0x050505;
		centre.y += 2;
		if (i%2 == 0)
			centre.x += 2;
		draw_fill_circle(centre,i, pCouleur);
	}
}

void afficher_paladin(POINT centre, COUL coul){
	COULEUR pCouleur = noir;
	
	if (coul == BLANC)
		pCouleur = blanc-(0x747474);
	else if(coul == NOIR)
		pCouleur = noir;
		
	int i;
	for(i = 15;i>10;i--){
		pCouleur += 0x0F0F0F;
		centre.y += 2;
		if (i%2 == 0)
			centre.x += 2;
		draw_fill_circle(centre,i, pCouleur);
	}

}

void affiche_lisere(POINT centre, int nbLisere){
	int cercle;
	int rayon_boite = (TAILLE_PLATEAU/NB_BOITE_PLATEAU)/2;
	
	for (cercle = 0;cercle < nbLisere;cercle++){
		draw_circle(centre,rayon_boite-(cercle*4),blanc);
	}
	
	
}

