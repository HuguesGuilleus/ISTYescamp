//Maxime VINCENT, Hugues GUILLEUS

#include "vue.h"

// Affiche les boxs du plateau, les paladins et les licornes.
// Prend en paramètre un entier pour l'interface graphique
// (rotation du plateau).
void afficher_plateau(int ig){
	int x,y;

	POINT pBDBox;
	NUMBOX box;

	for(x=0;x<NB_BOX_PLATEAU;x++){
		for(y=0;y<NB_BOX_PLATEAU;y++){
			box.l = y; box.c = x;

			pBDBox = numBoite_to_pointBG_ig(ig,box);
			afficher_lisere(pBDBox, plateau[x][y].lisere, box);

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


void afficher_victoire(COUL joueur){
	POINT pHG;
	char texte[50];

	pHG.x = (H_FENETRE-TAILLE_PLATEAU)/2+(TAILLE_PLATEAU/2)-200;
	pHG.y = (H_FENETRE-TAILLE_PLATEAU)/2+(TAILLE_PLATEAU/2)+44;

	aff_pol("VICTOIRE", 76, pHG, noir);
	pHG.y += 1; pHG.x += 2;
	aff_pol("VICTOIRE", 76, pHG, vert);

	strcpy(texte,"Bravo joueur blanc !");
	if (joueur == NOIR)
		strcpy(texte,"Bravo joueur noir ! ");

	pHG.y -= 86; pHG.x += 34;
	aff_pol(texte, 31, pHG, noir);
	pHG.y += 1; pHG.x += 2;
	aff_pol(texte, 31, pHG, vert);

	affiche_all();
}

void afficher_coups_impossible(){
	POINT pHG;
	pHG.x = (H_FENETRE-TAILLE_PLATEAU)/2+(TAILLE_PLATEAU/2)-245;
	pHG.y = (H_FENETRE-TAILLE_PLATEAU)/2+(TAILLE_PLATEAU/2)+44;

	aff_pol("Pas de coups possible", 44, pHG, noir);
	pHG.y += 1;pHG.x += 2;
	aff_pol("Pas de coups possible", 44, pHG, blanc);

	pHG.y -= 54;pHG.x += 28;
	aff_pol("Cliquer n'importe ou pour continuer", 24, pHG, noir);
	pHG.y += 1;pHG.x += 2;
	aff_pol("Cliquer n'importe ou pour continuer", 24, pHG, blanc);

	affiche_all();
}

//Affiche le panneau droit avec les informations
void afficher_panneau_info(){
	POINT pBG, pHD;

	pBG.x = H_FENETRE ; pBG.y = 0 ;
	pHD.x = L_FENETRE ; pHD.y = H_FENETRE ;
	draw_fill_rectangle(pBG, pHD, COULEUR_PRIMAIRE);

	afficher_btn_info("Quitter", 1);
}

// Affiche le panneau de jeu avec le plateau de jeu et les pions
void afficher_panneau_jeu(int ig){
	POINT pBG, pHD;

	pBG.x = 0 ; pBG.y = 0 ;
	pHD.x = H_FENETRE ; pHD.y = H_FENETRE ;
	draw_fill_rectangle(pBG, pHD, couleur_RGB(232,210,160));

	pBG.x += (H_FENETRE-TAILLE_PLATEAU)/2-25;
	pBG.y += (H_FENETRE-TAILLE_PLATEAU)/2-25;
	pHD.x -= (H_FENETRE-TAILLE_PLATEAU)/2-20;
	pHD.y -= (H_FENETRE-TAILLE_PLATEAU)/2-20;
	draw_fill_rectangle(pBG, pHD, COULEUR_PRIMAIRE);

	afficher_legende_plateau(ig);
	afficher_plateau(ig);
}

// Affiche la légende autour du plateau (chiffres et lettres)
void afficher_legende_plateau(int ig) {
	int i, chiffre = 0 ;
	POINT pLettre, pChiffre;
	char lettre[2];
	int largeur_box = (TAILLE_PLATEAU/NB_BOX_PLATEAU);

	for(i=0;i<NB_BOX_PLATEAU;i++){

		if (ig == 1) {
			pLettre.x = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_box)+largeur_box/2-3;
			pChiffre.y = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_box)+largeur_box/2+6;

			pLettre.y = (H_FENETRE-TAILLE_PLATEAU)/2-6;
			pChiffre.x = (H_FENETRE-TAILLE_PLATEAU)/2-18;
			chiffre = (i+1);
			lettre[0] = ('A'+i);

		} else if (ig == 2) {
			pLettre.y = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_box)+largeur_box/2+6;
			pChiffre.x = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_box)+largeur_box/2-3;

			pLettre.x = (H_FENETRE-TAILLE_PLATEAU)/2-18;
			pChiffre.y = (H_FENETRE-TAILLE_PLATEAU)/2-6;
			chiffre = (NB_BOX_PLATEAU-i);
			lettre[0] = ('A'+i);
		} else if (ig == 3) {
			pLettre.x = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_box)+largeur_box/2-3;
			pChiffre.y = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_box)+largeur_box/2+6;

			pLettre.y = (H_FENETRE-TAILLE_PLATEAU)/2-6;
			pChiffre.x = (H_FENETRE-TAILLE_PLATEAU)/2-18;
			chiffre = NB_BOX_PLATEAU-i;
			lettre[0] = ('F'-i);
		} else if (ig == 4) {
			pLettre.y = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_box)+largeur_box/2+6;
			pChiffre.x = (H_FENETRE-TAILLE_PLATEAU)/2+(i*largeur_box)+largeur_box/2-3;

			pLettre.x = (H_FENETRE-TAILLE_PLATEAU)/2-18;
			pChiffre.y = (H_FENETRE-TAILLE_PLATEAU)/2-6;
			chiffre = i+1;
			lettre[0] = ('F'-i);
		}
		aff_pol(lettre, 12, pLettre, blanc);
		aff_int(chiffre, 12, pChiffre, blanc);

		if (ig == 1) {
			pLettre.y = H_FENETRE-(H_FENETRE-TAILLE_PLATEAU)/2+20;
			pChiffre.x = H_FENETRE-(H_FENETRE-TAILLE_PLATEAU)/2+5;
		} else if (ig == 2) {
			pLettre.x = H_FENETRE-(H_FENETRE-TAILLE_PLATEAU)/2+5;
			pChiffre.y = H_FENETRE-(H_FENETRE-TAILLE_PLATEAU)/2+20;
		} else if (ig == 3) {
			pLettre.y = H_FENETRE-(H_FENETRE-TAILLE_PLATEAU)/2+20;
			pChiffre.x = H_FENETRE-(H_FENETRE-TAILLE_PLATEAU)/2+5;
		} else if (ig == 4) {
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
	}, COULEUR_PRIMAIRE);

	bg.x += rayon_box;
	bg.y += rayon_box;

	if(plateau[box.c][box.l].status == VALIDE)
		draw_fill_circle(bg, rayon_box, bleumarine);
	else if(plateau[box.c][box.l].status == SELECT)
		draw_fill_circle(bg, rayon_box, rouge);
	else if(plateau[box.c][box.l].status == ACCESSIBLE)
		draw_fill_circle(bg, rayon_box, vertclair);
	else if(plateau[box.c][box.l].status == PARCOUR)
		draw_fill_circle(bg, rayon_box, jaune);

	for (cercle = 0;cercle < nbLisere;cercle++){
		draw_circle(bg, rayon_box-(cercle*4), blanc);
	}


}

//prend en paramètre une box et une interface graphique
//affiche une lisère et le pion associer
void afficher_lisere_pion(int ig, NUMBOX box){
	POINT pBGBox;

	pBGBox = numBoite_to_pointBG_ig(ig,box);

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

void afficher_joueur_courant(COUL joueur){
	POINT hg;
	hg.x = H_FENETRE+50;
	hg.y = H_FENETRE-30;

	if (joueur == BLANC){
		aff_pol("Joueur", 24, hg, noir);
		hg.x +=2;hg.y+=2;
		aff_pol("Joueur", 24, hg, blanc);

		hg.x += 150;hg.y-=15;
		draw_fill_circle(hg, 30,blanc);
	}else{
		aff_pol("Joueur", 24, hg, noir);
		hg.x +=2;hg.y+=2;
		aff_pol("Joueur", 24, hg, blanc);

		hg.x += 150;hg.y-=15;
		draw_fill_circle(hg, 30,noir);
	}
}

void afficher_btn_info(char* texte, BOOL etat){
	POINT bg,hd;
	bg.x = H_FENETRE+50;
	bg.y = 50;
	hd.x = (L_FENETRE-50);
	hd.y = bg.y +50;
	if (etat == 0){
		draw_fill_rectangle(bg,hd,rouge);
	}else{
		draw_fill_rectangle(bg,hd,vert);
	}
	bg.x += 68;
	bg.y += 40;
	aff_pol(texte, 18, bg, blanc);
}

void afficher_texte_info(char* texte){
	/*POINT hd;
	hd.x = bg.x+(L_FENETRE-(bg.x*2));
	hd.y = bg.y+100;

	draw_fill_rectangle(bg,hd,red);*/
}
void afficher_pion_info(COUL coul){
	POINT bg;
	bg.x = H_FENETRE+25; bg.y = H_FENETRE/2;
	afficher_paladin(bg, coul);

	bg.x += (L_FENETRE-H_FENETRE)/2;
	afficher_licorne(bg, coul);
}

void afficher_placement_pions(int paladin, int licorne) {
	POINT texteHG,texteBD;
	texteHG.x = H_FENETRE+50; texteHG.y = H_FENETRE/2;

	char text[25];
	COULEUR couleur;

	couleur = blanc;
	if (paladin == 5) {
		couleur = vert;
	} else if (paladin > 5) {
		couleur = rouge;
	}
	texteBD.y = texteHG.y-24; texteBD.x = texteHG.x+(L_FENETRE-H_FENETRE)-30;
	draw_fill_rectangle(texteHG,texteBD,COULEUR_PRIMAIRE);

	sprintf(text,"%d / 5", paladin);
	aff_pol(text, 18, texteHG, noir);
	texteHG.x +=2;texteHG.y +=2;
	aff_pol(text, 18, texteHG, couleur);

	couleur = blanc;
	if (licorne == 1) {
		couleur = vert;
	} else if (licorne > 1) {
		couleur = rouge;
	}
	texteHG.x += (L_FENETRE-H_FENETRE)/2;
	texteBD.y = texteHG.y-24; texteBD.x = texteHG.x+(L_FENETRE-H_FENETRE)-30;

	sprintf(text,"%d / 1", licorne);
	aff_pol(text, 18, texteHG, noir);
	texteHG.x +=2;texteHG.y +=2;
	aff_pol(text, 18, texteHG, couleur);

	if (licorne == 1 && paladin == 5){
		afficher_btn_info("Valider", 1);
	}else{
		afficher_btn_info("Valider", 0);
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


void afficher_btn_select_ig(POINT bg, COULEUR couleur, int ig){
	POINT p2, p3,ptxt;

	bg.y += 50;
	p2.y=bg.y+50;p2.x=bg.x+50;
	p3.y=bg.y-50;p3.x=bg.x+50;
	draw_triangle(bg, p2, p3, noir);

	ptxt.x = L_FENETRE/2-156;
	ptxt.y = bg.y-5;
	aff_int(ig, 18, ptxt, blanc);
	ptxt.y += 18;
	ptxt.x -= 35;
	aff_pol("Interface", 18, ptxt, blanc);
	afficher_plateau_mini(ig);

	bg.x += L_FENETRE-(bg.x*2);
	p2.x = bg.x-50;
	p3.x = bg.x-50;
	draw_triangle(bg, p2, p3, noir);
}


void afficher_btn_select_joueur(POINT bg, COULEUR couleur, COUL joueur){
	POINT p2, p3,centre;

	bg.y += 50;
	p2.y=bg.y+50;p2.x=bg.x+50;
	p3.y=bg.y-50;p3.x=bg.x+50;
	draw_triangle(bg, p2, p3, noir);

	centre.x = L_FENETRE/2;
	centre.y = bg.y;
	if (joueur == BLANC)
		draw_fill_circle(centre,40,blanc);
	else
		draw_fill_circle(centre,40,noir);


	bg.x += L_FENETRE-(bg.x*2);
	p2.x = bg.x-50;
	p3.x = bg.x-50;
	draw_triangle(bg, p2, p3, noir);
}

void afficher_menu(){
	fill_screen(COULEUR_PRIMAIRE);
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

void afficher_menu_select_joueur(COUL joueur,int ig,int mod){
	fill_screen(COULEUR_PRIMAIRE);
	POINT pBtn;
	pBtn.x = 50;
	pBtn.y = 50;

	afficher_btn(pBtn,couleur_RGB(40,40,40),"Valider");
	pBtn.y += 150;
	if (mod == 2){
		afficher_btn_select_joueur(pBtn,couleur_RGB(40,40,40),joueur);
	}
	pBtn.y += 150;
	afficher_btn_select_ig(pBtn,couleur_RGB(40,40,40),ig);

	if (mod == 1){
		pBtn.y += 182;
		pBtn.x += (L_FENETRE/2)-200;
		draw_fill_circle(pBtn,36,noir);
		pBtn.x = (L_FENETRE/2)-270;
		pBtn.y += 18;
		aff_pol("Joueur NOIR selectionnez le sens du plateau :", 24, pBtn, blanc);
	}else{
		pBtn.y += 200;
		pBtn.x = (L_FENETRE/2)-245;
		aff_pol("Selectionnez votre couleur et le plateau :", 24, pBtn, blanc);
	}

	affiche_all();
}

void afficher_plateau_mini(int ig){
	int x,y;
	int cercle;
	int rayon_box = 10;

	POINT pBDBox;
	NUMBOX box;

	for(x=0;x<NB_BOX_PLATEAU;x++){
		for(y=0;y<NB_BOX_PLATEAU;y++){
			box.l = y; box.c = x;
			pBDBox = numBoite_to_pointBG_ig_mini(ig,box);

			pBDBox.x += rayon_box;
			pBDBox.y += rayon_box;

			for (cercle = 0;cercle < plateau[x][y].lisere;cercle++){
				draw_circle(pBDBox, rayon_box-(cercle*3), blanc);
			}
		}
	}
}
