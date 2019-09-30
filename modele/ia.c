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

NUMBOX* recup_numbox_licorne_en_danger(COUL ia){
	NUMBOX* licorne =(NUMBOX*) malloc(sizeof(NUMBOX));
	BOX* box;
	int c,l;
	
	for (c = 0; c<NB_BOX_PLATEAU; c++){
		for (l = 0; l<NB_BOX_PLATEAU; l++){
			box = getBox(c,l);
			if ( box->coulP == ia && box->typeP == LICORNE){
				licorne->c = c; licorne->l = l;
				if (va_mourir(*licorne,ia)) return licorne;
				else return NULL;
			}
		}
	}
	
	return NULL;
}

BOOL va_mourir(NUMBOX licorne,COUL ia){
	
	COUL joueur = BLANC;
	if (ia == BLANC) joueur = NOIR;
	
	//recup les positions d'accessible de l'adversaire
	BOX* box;
	BOX* box1;
	int c,l,c1,l1;
	
	
	for (c = 0; c<NB_BOX_PLATEAU; c++){
		for (l = 0; l<NB_BOX_PLATEAU; l++){
			box = getBox(c,l);
			if ( box->typeP == PALADIN && box->coulP == joueur ){
				parcourt_plusieurs_cases(c, l, box->coulP, box->typeP, box->lisere);
			}
		}
	}
	
	for (c1 = 0; c1<NB_BOX_PLATEAU; c1++){
		for (l1 = 0; l1<NB_BOX_PLATEAU; l1++){
			box1 = getBox(c1,l1);
			if ( box1->status == ACCESSIBLE && c1 == licorne.c && l1 == licorne.l ){
				return TRUE;
			}
			
		}
	}
	
	return FALSE;
	

	
	
}

NUMBOX recup_numbox_origine(NUMBOX destination, int nbtabBoxSelect,NUMBOX tabBoxSelect[38] ){
	
	int c,l,i = 0;
	BOX* box;
	NUMBOX b,origine;
	
	for (i = 0; i < nbtabBoxSelect;i++){
		b = tabBoxSelect[i];
		box = getBox(b.c,b.l);
		parcourt_plusieurs_cases(b.c, b.l, box->coulP, box->typeP, box->lisere) ;
		for (c = 0; c<NB_BOX_PLATEAU; c++){
			for (l = 0; l<NB_BOX_PLATEAU; l++){
				box = getBox(c,l);
				if ( box->status == ACCESSIBLE && c == destination.c && l == destination.l ){
					origine.c = b.c;
					origine.l= b.l;
					return origine;
				}
				
			}
		}
	}
	return destination; 
}


BOOL recup_meilleur_deplacement_ia(NUMBOX* dest, NUMBOX* origine, COUL ia, TYPE caseType, int ig){
	NUMBOX b;
	NUMBOX tabBoxAccessible[36];
	NUMBOX tabBoxSelect[36];
	int nbtabBoxAccessible = 0,nbtabBoxSelect = 0,i = 0;
	b.c = 0; b.l = 0;
	
	//recup les positions d'origine possible
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
	//si pas de pion d'origine
	if (nbtabBoxSelect == 0){
		printf("PAS DE CASE SELECTIONNABLE");
		return FALSE;
	}
	
	//premier parcours des cases accessibles si peux gagner gagne
	for (c = 0; c<NB_BOX_PLATEAU; c++){
		for (l = 0; l<NB_BOX_PLATEAU; l++){
			box = getBox(c,l);
			if ( box->status == ACCESSIBLE ){
				if (box->typeP == LICORNE){
					init_status();
					dest->c = c; dest->l = l;
					*origine = recup_numbox_origine(*dest,nbtabBoxSelect,tabBoxSelect);
					if(origine) return TRUE;
					else return FALSE;
				}else{
					b.c = c; b.l =l;
					tabBoxAccessible[nbtabBoxAccessible] = b;
					nbtabBoxAccessible++;
				}
			}
		}
	}
	init_status();
	//Pion bloquer
	if (nbtabBoxAccessible == 0){
		printf("PAS DE CASE ACCESSIBLE\n");
		return FALSE;
	}
	
	//Parcour si licorne en danger
	NUMBOX* licorne = recup_numbox_licorne_en_danger(ia);
	if (licorne != NULL){
		box = getBox(licorne->c,licorne->l);
		for (i = 0; i < nbtabBoxSelect;i++){
			if (tabBoxSelect[i].c == licorne->c && tabBoxSelect[i].l == licorne->l){
				printf("Je peux le deplacer\n");
				*origine = tabBoxSelect[i];
				init_status();
				parcourt_plusieurs_cases(tabBoxSelect[i].c, tabBoxSelect[i].l, box->coulP, box->typeP, box->lisere);
				for (c = 0; c<NB_BOX_PLATEAU; c++){
					for (l = 0; l<NB_BOX_PLATEAU; l++){
						box = getBox(c,l);
						if ( box->status == ACCESSIBLE ){
							dest->c = c; 
							dest->l = l;
							return TRUE;
						}
					}
				}
			}
		}
		printf("la licorne est en danger !\n");
	}
	init_status();
	
	//dexieme parcours des coups possible pour les case accessibles
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
						*origine = recup_numbox_origine(*dest,nbtabBoxSelect,tabBoxSelect);
						if(origine) return TRUE;
						else return FALSE;
					}
				}
			}
		}
		init_status();
	}
	
	//Si aucun coups gagnant ou defensif trouver choisi un tire aléatoire
	i = rand()%nbtabBoxAccessible;
	dest->c = tabBoxAccessible[i].c; dest->l = tabBoxAccessible[i].l;
	*origine = recup_numbox_origine(*dest,nbtabBoxSelect,tabBoxSelect);
	if(origine) return TRUE;
	else return FALSE;
}

NUMBOX recup_meilleur_placement_ia(COUL ia, TYPE caseType, int ig){
	NUMBOX box;
	box.c = 0; box.l = 0;
	
	return box;
}
