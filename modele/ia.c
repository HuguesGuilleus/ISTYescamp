// Maxime VINCENT, Hugues GUILLEUS

#include "ia.h"

NUMBOX recup_numbox_vide_rand(COUL ia, int ig){
	NUMBOX box;
	box.l = 0; box.c = 0;
	
	int minL = 0,minC = 0,maxL = 0,maxC = 0;
	
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
		if (ig == 1){ minL = 4; maxL = 5; minC = 0; maxC = 5;}
		else if (ig == 2){ minL = 0; maxL = 5; minC = 4; maxC = 5;}
		else if (ig == 3){ minL = 0; maxL = 1; minC = 0; maxC = 5;}
		else if (ig == 4){ minL = 0; maxL = 5; minC = 0; maxC = 1;}
		
		do{
			box.l = minL+(rand()%(maxL-minL+1));
			box.c = minC+(rand()%(maxC-minC+1));
		}while (plateau[box.c][box.l].typeP != VIDE );
	}
	
	return box;
}


void positionne_pions_ia(COUL ia, int ig){
	NUMBOX box;
	box.l = 0; box.c = 0;
	
	int i;
	
	for (i=0; i<NB_BOX_PLATEAU-1;i++){
		if (ia == NOIR){
			box = recup_numbox_vide_rand(ia,ig);
		}else{
			//box = recup_meilleur_placement_ia(ia,PALADIN,ig);
			box = recup_numbox_vide_rand(ia,ig);
		}
		plateau[box.c][box.l].typeP = PALADIN;
		plateau[box.c][box.l].coulP = ia;
	}
	
	if (ia == NOIR){
		box = recup_numbox_vide_rand(ia,ig);
	}else{
		//box = recup_meilleur_placement_ia(ia,LICORNE,ig);
		box = recup_numbox_vide_rand(ia,ig);
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
	NUMBOX b;
	NUMBOX tabBoxAccessible[36];
	NUMBOX tabBoxSelect[36];
	int nbtabBoxAccessible = 0,nbtabBoxSelect = 0,i = 0;
	b.c = 0; b.l = 0;
	
	BOX* box;
	int c,l;
	for (c = 0; c<NB_BOX_PLATEAU; c++){
		for (l = 0; l<NB_BOX_PLATEAU; l++){
			box = getBox(c,l);
			if ( box->status == VALIDE ){
				parcourt_plusieurs_cases(c, l, box->coulP, box->typeP, box->lisere) ;
				b.c = c; b.l = l;
				tabBoxSelect[nbtabBoxSelect] = b;
				nbtabBoxSelect++;
			}
		}
	}
	if (nbtabBoxSelect == 0){
		printf("PAS DE CASE SELECTIONNABLE");
		return FALSE;
	}
	
	//premier parcours
	for (c = 0; c<NB_BOX_PLATEAU; c++){
		for (l = 0; l<NB_BOX_PLATEAU; l++){
			box = getBox(c,l);
			if ( box->status == ACCESSIBLE ){
				if (box->typeP == LICORNE){
					init_status();
					dest->c = c; dest->l = l;
					
					//recup box origine
					for (i = 0; i < nbtabBoxSelect;i++){
						b = tabBoxSelect[i];
						box = getBox(b.c,b.l);
						parcourt_plusieurs_cases(b.c, b.l, box->coulP, box->typeP, box->lisere) ;
						for (c = 0; c<NB_BOX_PLATEAU; c++){
							for (l = 0; l<NB_BOX_PLATEAU; l++){
								box = getBox(c,l);
								if ( box->status == ACCESSIBLE && c == dest->c && l == dest->l ){
									origine->c = b.c; origine->l= b.l;
									return TRUE; 
								}
								
							}
						}
					}
					printf("ERREUR IA - 1\n");
					return FALSE; 
				}else{
					b.c = c; b.l =l;
					tabBoxAccessible[nbtabBoxAccessible] = b;
					nbtabBoxAccessible++;
				}
			}
		}
	}
	init_status();
	if (nbtabBoxAccessible == 0){
		printf("PAS DE CASE ACCESSIBLE\n");
		return FALSE;
	}
	
	
	//dexieme parcours
	for (i = 0; i<nbtabBoxAccessible; i++){
		box = getBox(tabBoxAccessible[i].c,tabBoxAccessible[i].l);
		parcourt_plusieurs_cases(tabBoxAccessible[i].c, tabBoxAccessible[i].l, box->coulP, box->typeP, box->lisere);
		
		for (c = 0; c<NB_BOX_PLATEAU; c++){
			for (l = 0; l<NB_BOX_PLATEAU; l++){
				box = getBox(c,l);
				if ( box->status == ACCESSIBLE ){
					if (box->typeP == LICORNE){
						init_status();
						dest->c = tabBoxAccessible[i].c; dest->l = tabBoxAccessible[i].l;
					
						//recup box origine
						for (i = 0; i < nbtabBoxSelect;i++){
							b = tabBoxSelect[i];
							box = getBox(b.c,b.l);
							parcourt_plusieurs_cases(b.c, b.l, box->coulP, box->typeP, box->lisere) ;
							for (c = 0; c<NB_BOX_PLATEAU; c++){
								for (l = 0; l<NB_BOX_PLATEAU; l++){
									box = getBox(c,l);
									if ( box->status == ACCESSIBLE && c == dest->c && l == dest->l ){
										origine->c = b.c; origine->l= b.l;
										return TRUE; 
									}
								}
							}
						}
						printf("ERREUR IA - 2\n");
						return FALSE; 
					}
				}
			}
		}
		init_status();
	}
	i = rand()%nbtabBoxAccessible;
	dest->c = tabBoxAccessible[i].c; dest->l = tabBoxAccessible[i].l;
	
	//recup box origine
	for (i = 0; i < nbtabBoxSelect;i++){
		b = tabBoxSelect[i];
		box = getBox(b.c,b.l);
		parcourt_plusieurs_cases(b.c, b.l, box->coulP, box->typeP, box->lisere) ;
		for (c = 0; c<NB_BOX_PLATEAU; c++){
			for (l = 0; l<NB_BOX_PLATEAU; l++){
				box = getBox(c,l);
				if ( box->status == ACCESSIBLE && c == dest->c && l == dest->l ){
					origine->c = b.c; origine->l= b.l;
					return TRUE; 
				}
				
			}
		}
	}
	printf("ERREUR IA - 3 \n");
	return FALSE;
}

NUMBOX recup_meilleur_placement_ia(COUL ia, TYPE caseType, int ig){
	NUMBOX box;
	box.c = 0; box.l = 0;
	
	return box;
}
