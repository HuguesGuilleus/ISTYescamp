// Maxime VINCENT, Hugues GUILLEUS

#include "ia.h"

void positionne_pions_ia(COUL ia, int ig){
	NUMBOX box;
	
	int i;
	for (i=0; i<NB_BOX_PLATEAU;i++){
		box.l = rand()%NB_BOX_PLATEAU;
		box.c = rand()%NB_BOX_PLATEAU;
		printf("l : %d c: %d\n",box.l,box.c);
		switch (ig) {
			case 1:
				if (ia == BLANC){
					while (plateau[box.c][box.l].typeP == VIDE && box.l < 2 ){
						box.l = rand()%NB_BOX_PLATEAU; box.c = rand()%NB_BOX_PLATEAU;
					}
					plateau[box.c][box.l].typeP = PALADIN;
					plateau[box.c][box.l].coulP = ia;
				}else{
					break;
				}
				break;
				//~ return (box.l < 2 && joueur == BLANC) || (box.l > 3 && joueur == NOIR) ;
			case 2:
				break;
				//~ return (box.c < 2 && joueur == BLANC) || (box.c > 3 && joueur == NOIR) ;
			case 3:
				break;
				//~ return (box.l > 3 && joueur == BLANC) || (box.l < 2 && joueur == NOIR) ;
			case 4:
				break;
				//~ return (box.c > 3 && joueur == BLANC) || (box.c < 2 && joueur == NOIR) ;
			default:
				break;
				//~ return FALSE;
		}//end switch
	}//end for
}

void lancer_tour_ia(COUL coul, int ig){
	
}
