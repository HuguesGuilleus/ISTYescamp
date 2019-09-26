// Maxime VINCENT, Hugues GUILLEUS

#ifndef IA_H
	#define IA_H 1

	#include <stdlib.h>
	#include <time.h>
	
	#include "modele.h"

	void positionne_pions_ia(COUL coul, int ig);
	BOOL lancer_tour_ia(COUL ia, int lisere, int ig);
	BOOL recup_meilleur_deplacement_ia(NUMBOX* dest, NUMBOX* origine, COUL ia, TYPE caseType, int ig);
	NUMBOX recup_meilleur_placement_ia(COUL ia,TYPE caseType,int ig);
	
#endif
