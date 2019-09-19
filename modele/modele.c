#include "modele.h"

void init_plateau() {
	int x,y ;
	for (x = 0; x < 6; x++) {
		for (y = 0; y < 6; y++) {
			plateau[x][y].lisere = 1 ;
			plateau[x][y].typeP = VIDE ;
			plateau[x][y].coulP = BLANC ;
		}
	}

	plateau[0][0].lisere = 3 ;
	plateau[1][1].lisere = 3 ;
	plateau[2][2].lisere = 3 ;
	plateau[3][1].lisere = 3 ;
	plateau[4][0].lisere = 3 ;
	plateau[4][4].lisere = 3 ;

	plateau[1][0].lisere = 2 ;
	plateau[2][0].lisere = 2 ;
	plateau[5][0].lisere = 2 ;
}
