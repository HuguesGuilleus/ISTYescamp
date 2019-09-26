// Maxime VINCENT, Hugues GUILLEUS

#include "ia.h"

void positionne_pions_ia(COUL ia, int ig){
	NUMBOX box;
	box.l = 0; box.c = 0;
	
	int i;
	int minL = 0,minC = 0,maxL = 0,maxC = 0;
	
	for (i=0; i<NB_BOX_PLATEAU-1;i++){
		if (ia == NOIR){
			if (ig == 1){ minL = 0; maxL = 1; minC = 0; maxC = 5;}
			else if (ig == 2){ minL = 0; maxL = 5; minC = 0; maxC = 1;}
			else if (ig == 3){ minL = 4; maxL = 5; minC = 0; maxC = 5;}
			else if (ig == 4){ minL = 0; maxL = 5; minC = 4; maxC = 5;}
			
			do{
				box.l = minL+(rand()%(maxL-minL+1));
				box.c = minC+(rand()%(maxC-minC+1));
			}while (plateau[box.c][box.l].typeP != VIDE );
		}else{
			box = recup_meilleur_placement_ia(ia,PALADIN,ig);
		}
		plateau[box.c][box.l].typeP = PALADIN;
		plateau[box.c][box.l].coulP = ia;
	}//end for
	
	
	if (ia == NOIR){
		switch (ig) {
			case 1:
				do{
					box.l = rand()%2; box.c = rand()%NB_BOX_PLATEAU;
				}while (plateau[box.c][box.l].typeP != VIDE );
				break;
			case 2:
				do{
					box.l = rand()%NB_BOX_PLATEAU; box.c = rand()%2;
				}while (plateau[box.c][box.l].typeP != VIDE );
				break;
			case 3:
				do{
					box.l = 4 + (rand()%2); box.c = rand()%NB_BOX_PLATEAU;
				}while (plateau[box.c][box.l].typeP != VIDE );
				break;
			case 4:
				do{
					box.l = rand()%NB_BOX_PLATEAU; box.c = 4 + (rand()%2);
				}while (plateau[box.c][box.l].typeP != VIDE );
				break;
			default:
				break;
		}//end switch
	}else{
		box = recup_meilleur_placement_ia(ia,LICORNE,ig);
	}
	plateau[box.c][box.l].typeP = LICORNE;
	plateau[box.c][box.l].coulP = ia;
}

void lancer_tour_ia(COUL coul, int ig){
	
}

NUMBOX recup_meilleur_deplacement_ia(COUL ia, TYPE caseType, int ig){
	NUMBOX box;
	box.c = 0; box.l = 0;
	
	
	
	return box;
}

NUMBOX recup_meilleur_placement_ia(COUL ia, TYPE caseType, int ig){
	NUMBOX box;
	box.c = 0; box.l = 0;
	
	
	return box;
}
