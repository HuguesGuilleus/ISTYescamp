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

BOOL lancer_tour_ia(COUL ia, int lisere, int ig){
	selectionne_pion(ia, lisere, NULL);
	NUMBOX dest,origine;
	
	if (recup_meilleur_deplacement_ia(&dest,&origine,ia,PALADIN,ig)){
		if (est_licorne_adverse(dest, ia)){
			deplacement_simple(origine,dest);
			return TRUE;
		}else{
			deplacement_simple(origine,dest);
		}
	}

	return FALSE;

}

BOOL recup_meilleur_deplacement_ia(NUMBOX* dest, NUMBOX* origine, COUL ia, TYPE caseType, int ig){
	NUMBOX b,tabBox[18];
	int nbTabBox = 0,i = 0;
	b.c = 0; b.l = 0;
	
	BOX* box;
	int c,l;
	for (c = 0; c<NB_BOX_PLATEAU; c++){
		for (l = 0; l<NB_BOX_PLATEAU; l++){
			box = getBox(c,l);
			if ( box->status == VALIDE ){
				parcourt_plusieurs_cases(c, l, box->coulP, box->typeP, box->lisere) ;
			}
		}
	}
	
	//premier parcours
	for (c = 0; c<NB_BOX_PLATEAU; c++){
		for (l = 0; l<NB_BOX_PLATEAU; l++){
			box = getBox(c,l);
			if ( box->status == ACCESSIBLE ){
				if (box->typeP == LICORNE){
					dest->c = c; dest->l = l;
					origine->c = 0; origine->l=0;
					return TRUE; 
				}else{
					tabBox[nbTabBox] = (NUMBOX){c:c,l:l};
					nbTabBox++;
				}
			}
		}
	}
	init_status();
	
	//dexieme parcours
	for (i = 0; i<nbTabBox; i++){
		box = getBox(c,l);
		parcourt_plusieurs_cases(tabBox[i].c, tabBox[i].l, box->coulP, box->typeP, box->lisere);
		
		for (c = 0; c<NB_BOX_PLATEAU; c++){
			for (l = 0; l<NB_BOX_PLATEAU; l++){
				box = getBox(c,l);
				if ( box->status == ACCESSIBLE ){
					if (box->typeP == LICORNE){
						dest->c = tabBox[i].c; dest->l = tabBox[i].l;
						origine->c = 0; origine->l=0;
						return TRUE; 
					}
				}
			}
		}
		init_status();
	}
	
	dest->c = 0; dest->l = 0;
	origine->c = 0; origine->l=0;
	return FALSE;
}

NUMBOX recup_meilleur_placement_ia(COUL ia, TYPE caseType, int ig){
	NUMBOX box;
	box.c = 0; box.l = 0;
	
	return box;
}
