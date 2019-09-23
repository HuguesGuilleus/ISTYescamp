#include "menu.h"

/***** MENU *****/

BOOL est_dans_bouton_quitter(POINT clic){
	return (clic.y >= 50 && clic.y <= 150 && clic.x <= (L_FENETRE-50) && clic.x >= 50);
}

BOOL est_dans_bouton_JvsJ(POINT clic){
	return (clic.y >= 350 && clic.y <= 450 && clic.x <= (L_FENETRE-50) && clic.x >= 50);
}

BOOL est_dans_bouton_JvsIA(POINT clic){
	return (clic.y >= 200 && clic.y <= 300 && clic.x <= (L_FENETRE-50) && clic.x >= 50);

}

BOOL est_dans_bouton_valider(POINT clic){
	return (clic.y >= 350 && clic.y <= 450 && clic.x <= (L_FENETRE-50) && clic.x >= 50);
}

BOOL est_dans_bouton_ig(POINT clic){
	return (clic.y >= 200 && clic.y <= 450 && clic.x <= (L_FENETRE-50) && clic.x >= 50);
}

BOOL est_dans_bouton_coul(POINT clic){
	return (clic.y >= 150 && clic.y <= 250 && clic.x <= 100 && clic.x >= 50);
}
