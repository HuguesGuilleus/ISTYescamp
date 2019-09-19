//Maxime VINCENT, Hugues GUILLEUS

#include "vue.h"

// Affiche les boxs du plateau, les paladins et les licornes.
// Prend en paramètre un entier 1 ou 2, pour l'interface graphique (rotation
// du plateau).
void afficher_plateau(int ig){
	int x,y;

	POINT pBDBox;
	NUMBOX box;

	for(x=0;x<NB_BOX_PLATEAU;x++){
		for(y=0;y<NB_BOX_PLATEAU;y++){
			box.l = y; box.c = x;
			if (ig == 1)
				pBDBox = numBoite_to_pointBG_ig1(box);
			else
				pBDBox = numBoite_to_pointBG_ig2(box);

			afficher_lisere(pBDBox, plateau[x][y].lisere,box);

			switch (plateau[x][y].typeP){
				case LICORNE:
					afficher_licorne(pBDBox, plateau[x][y].coulP);
					break;
				case PALADIN:
					afficher_paladin(pBDBox, plateau[x][y].coulP);
					break;
				default:
					break;
			}
		}
	}
	affiche_all();
}


//Affiche le panneau droit avec les informations
void afficher_panneau_info(){
	POINT pBG,pHD;

	pBG.x = H_FENETRE ; pBG.y = 0 ;
	pHD.x = L_FENETRE ; pHD.y = H_FENETRE ;

	draw_fill_rectangle(pBG,pHD,blanc);
	affiche_all();
}

//Affiche le panneau de jeu avec le plateau de jeu et les pions
void afficher_panneau_jeu(int ig){
	POINT pBG, pHD;

	pBG.x = 0 ; pBG.y = 0;
	pHD.x = H_FENETRE ; pHD.y = H_FENETRE ;
	draw_fill_rectangle(pBG, pHD, couleur_RGB(232,210,160));

	pBG.x += (H_FENETRE-TAILLE_PLATEAU)/2-25;
	pBG.y += (H_FENETRE-TAILLE_PLATEAU)/2-25;
	pHD.x -= (H_FENETRE-TAILLE_PLATEAU)/2-20;
	pHD.y -= (H_FENETRE-TAILLE_PLATEAU)/2-20;

	draw_fill_rectangle(pBG, pHD, couleur_RGB(129,116,98));

	afficher_legende_plateau(ig);

	afficher_plateau(ig);
}

// Affiche la légende autour du plateau (chiffres et lettres)
// Prend en paramètre un entier pour l'interface graphique.
void afficher_legende_plateau(int ig){
	int i, chiffre = 0 ;
	POINT pLettre, pChiffre;
	char lettre[2];
	int largeur_box = (TAILLE_PLATEAU/NB_BOX_PLATEAU);

	for(i=0;i<NB_BOX_PLATEAU;i++){
		lettre[0] = ('A'+i);

		if (ig == 1) {
			pLettre.x = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_box)+largeur_box/2-3;
			pChiffre.y = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_box)+largeur_box/2+6;

			pLettre.y = (H_FENETRE-TAILLE_PLATEAU)/2-6;
			pChiffre.x = (H_FENETRE-TAILLE_PLATEAU)/2-18;
			chiffre = (i+1);

		} else if (ig == 2) {
			pLettre.y = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_box)+largeur_box/2+6;
			pChiffre.x = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_box)+largeur_box/2-3;

			pLettre.x = (H_FENETRE-TAILLE_PLATEAU)/2-18;
			pChiffre.y = (H_FENETRE-TAILLE_PLATEAU)/2-6;
			chiffre = (NB_BOX_PLATEAU-i);
		}
		aff_pol(lettre, 12, pLettre, blanc);
		aff_int(chiffre, 12, pChiffre, blanc);

		if (ig == 1) {
			pLettre.y = H_FENETRE-(H_FENETRE-TAILLE_PLATEAU)/2+20;
			pChiffre.x = H_FENETRE-(H_FENETRE-TAILLE_PLATEAU)/2+5;
		} else if (ig == 2) {
			pLettre.x = H_FENETRE-(H_FENETRE-TAILLE_PLATEAU)/2+5;
			pChiffre.y = H_FENETRE-(H_FENETRE-TAILLE_PLATEAU)/2+20;
		}
		aff_pol(lettre, 12, pLettre, blanc);
		aff_int(chiffre, 12, pChiffre, blanc);
	}
}

// prend en paramètre un point bas gauche et une COUL (joueur)
//affiche une licorne
void afficher_licorne(POINT bg, COUL coul){
	COULEUR pCouleur = noir;
	int i;

	if (coul == BLANC)
		pCouleur = blanc-(0x646464);
	else if(coul == NOIR)
		pCouleur = noir;

	bg.x += (TAILLE_PLATEAU/NB_BOX_PLATEAU)/2;
	bg.y += (TAILLE_PLATEAU/NB_BOX_PLATEAU)/2;

	for(i = 20;i>5;i--){
		pCouleur += 0x050505;
		bg.y += 2;
		if (i%2 == 0)
			bg.x += 2;
		draw_fill_circle(bg,i, pCouleur);
	}
}

// prend en paramètre un point bas gauche et une COUL (joueur)
//affiche un paladin
void afficher_paladin(POINT bg, COUL coul){
	COULEUR pCouleur = noir;
	int i;

	if (coul == BLANC)
		pCouleur = blanc-0x747474;
	else if(coul == NOIR)
		pCouleur = noir;

	bg.x += (TAILLE_PLATEAU/NB_BOX_PLATEAU)/2;
	bg.y += (TAILLE_PLATEAU/NB_BOX_PLATEAU)/2;

	for(i = 15;i>10;i--){
		pCouleur += 0x0F0F0F;
		bg.y += 2;
		if (i%2 == 0)
			bg.x += 2;
		draw_fill_circle(bg,i, pCouleur);
	}
}

//prend en paramètre un point bas gauche et un nombre de lisère
//affiche les liseres d'une case
void afficher_lisere(POINT bg, int nbLisere,NUMBOX box){
	int cercle;
	int rayon_box = (TAILLE_PLATEAU/NB_BOX_PLATEAU)/2;

	draw_fill_rectangle(bg,(POINT){
		x: bg.x+rayon_box*2,
		y: bg.y+rayon_box*2,
	}, couleur_RGB(129,116,98));

	bg.x += rayon_box;
	bg.y += rayon_box;
	
	if(plateau[box.c][box.l].status == VALIDE)
		draw_fill_circle(bg, rayon_box, bleumarine);
	else if(plateau[box.c][box.l].status == SELECT)
		draw_fill_circle(bg, rayon_box, rouge);

	for (cercle = 0;cercle < nbLisere;cercle++){
		draw_circle(bg, rayon_box-(cercle*4), blanc);
	}
	
	
}

//prend en paramètre une box et une interface graphique
//affiche une lisère et le pion associer
void afficher_lisere_pion(int ig, NUMBOX box){
	POINT pBGBox;

	if (ig ==1)
		pBGBox = numBoite_to_pointBG_ig1(box);
	else if(ig == 2)
		pBGBox = numBoite_to_pointBG_ig2(box);

	afficher_lisere(pBGBox,plateau[box.c][box.l].lisere,box);

	switch (plateau[box.c][box.l].typeP){
		case LICORNE:
			afficher_licorne(pBGBox, plateau[box.c][box.l].coulP);
			break;
		case PALADIN:
			afficher_paladin(pBGBox, plateau[box.c][box.l].coulP);
			break;
		default:
			break;
	}
}


/***********MENU************/

//prend en paramètre un un point, une couleur et un texte
//Affiche un bouton
void afficher_btn(POINT bg, COULEUR couleur, char* text){
	POINT hd;
	hd.x = bg.x+(L_FENETRE-(bg.x*2));
	hd.y = bg.y+100;
	
	draw_fill_rectangle(bg,hd,couleur);
	hd.x -= 20;
	hd.y -= 20;
	bg.x += 20;
	bg.y += 20;
	draw_fill_rectangle(bg,hd,couleur_RGB(80,75,70));
	
	bg.y += 42;
	bg.x += 39;
	aff_pol(text, 18, bg, blanc);

}

void afficher_menu(){
	fill_screen(couleur_RGB(129,116,98));
	POINT pBtn;
	pBtn.x = 50;
	pBtn.y = 50;
	
	afficher_btn(pBtn,couleur_RGB(40,40,40),"Quitter");
	pBtn.y += 150;
	afficher_btn(pBtn,couleur_RGB(40,40,40),"Joueur VS IA");
	pBtn.y += 150;
	afficher_btn(pBtn,couleur_RGB(40,40,40),"Joueur VS joueur");
	pBtn.y += 200;
	pBtn.x += (L_FENETRE/2)-160;
	aff_pol("ESCAMPE", 48, pBtn, blanc);


	
	affiche_all();
}


