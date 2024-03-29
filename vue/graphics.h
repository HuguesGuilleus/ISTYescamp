// ############################################
//                    ISTY
//
// CPI 1ere annee - IN2001
//
// Laurence PILARD -- Laurence.Pilard@prism.uvsq.fr
// Version de janvier 2012
//
// Concu par Franck Quessette
//
// SOMMAIRE
//
// 1. TYPES, VARIABLES, CONSTANTES ... ligne  39
// 2. AFFICHAGE ...................... ligne  76
// 3. GESTION D'EVENEMENTS ........... ligne  99
// 4. DESSIN D'OBJETS ................ ligne 135
// 5. ECRITURE DE TEXTE .............. ligne 180
// 6. LECTURE D'ENTIER ............... ligne 210
// 7. GESTION DU TEMPS ............... ligne 219
// 8. VALEUR ALEATOIRES .............. ligne 241
// 9. DIVERS ......................... ligne 252
// #############################################

#ifndef GRAPHICS_H
#define GRAPHICS_H 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <SDL.h>

// A decommentr si on fonctionne en local, sinon sur un terminal
// on a des lenteurs
// #define EN_LOCAL

// ###############################
// 1. TYPES, VARIABLES, CONSTANTES
// ###############################

// 1.1 TYPES

	// Définition du type POINT
	typedef struct point {int x,y;} POINT;

	// Définition du type COULEUR
	typedef Uint32 COULEUR;

	// Les booléens
	typedef int BOOL;

// 1.2 VARIABLES
	// Taille de l'affichage
	int WIDTH;
	int HEIGHT;

// 1.3 CONSTANTES

	// Déplacement minimal lorsque l'on utilise les flèches.
	#define MINDEP 1

	// Constantes de couleur
	#include "couleur.h"

	// Constantes booléennes
	#define TRUE 1
	#define True 1
	#define true 1
	#define FALSE 0
	#define False 0
	#define false 0


// ############
// 2. AFFICHAGE
// ############

	// 2.1 Initialisation de la fenêtre sur laquelle on dessine
	void init_graphics(int W, int H);

	// 2.2 Affichage automatique ou manuel
	// Si l'affichage est automatique, chaque objet dessiné
	// est automatiquement affiché.
	// Sinon, il faut explicitement appeler la fonction
	// affiche_all() pour afficher les objets
	// synchro() est identique à affiche_all()
	void affiche_auto_on();
	void affiche_auto_off();
	void affiche_all();
	void synchro();

	// 2.3 Création de couleur
	// r g et b dans l'intervalle 0 .. 255
	COULEUR couleur_RGB(int r, int g, int b);

	void souris_visible();
	void souris_invisible();

// #######################
// 3. GESTION D'EVENEMENTS
// #######################

	// 3.1 Renvoie le ou les fleches appuyees
	// sous forme d'un déplacement en
	// x négatif = nombre d'appuis sur la flèche gauche
	// x positif = nombre d'appuis sur la flèche droite
	// y négatif = nombre d'appuis sur la flèche bas
	// y positif = nombre d'appuis sur la flèche haut
	// Instruction non bloquante, si aucune flèche n'a été
	// appuyée les champs x et y vaudront 0.
	POINT get_arrow();

	// 3.2 Renvoie deplacement de souris
	// Meme sémantique que get_arrow()
	// Instruction non bloquante, si la souris n'a pas bouge,
	// les champs x et y vaudront 0.
	POINT get_mouse();

	// 3.3 Attend que l'on tape Echap et quitte
	// Instruction bloquante
	void wait_escape();

	// 3.4 Attend que l'utilisateur clique avec le bouton gauche
	// Renvoie les coordonnees du point clique
	// Instruction bloquante
	POINT wait_clic();

	// 3.5 Attend que l'on clique et renvoie dans button le bouton clique :
	// *button vaut soit 'G' (pour Gauche), soit 'M' (pour milieu),
	// soit 'D' (pour Droit) en fonction du bouton clique
	// Instruction bloquante
	POINT wait_clic_GMD(char *button);


// ##################
// 4. DESSIN D'OBJETS
// ##################

	// 4.1 Remplissage de tout l'écran
	void fill_screen(COULEUR color);

	// 4.2 Dessine un pixel
	void draw_pixel(POINT p, COULEUR color);

	// 4.3 Dessine un segment
	void draw_line(POINT p1, POINT p2, COULEUR color);

	// 4.4 Dessine un rectangle non rempli
	// Les deux points sont deux points quelconques
	// non adjacents du rectangle
	void draw_rectangle(POINT p1, POINT p2, COULEUR color);

	// 4.5 Dessine un rectangle rempli
	// Les deux point sont deux points quelconques
	// non adjacents du rectangle
	void draw_fill_rectangle(POINT p1, POINT p2, COULEUR color);

	// 4.6 Dessine un cercle non rempli
	void draw_circle(POINT centre, int rayon, COULEUR color);

	// 4.7 Dessine un cercle rempli
	void draw_fill_circle(POINT centre, int rayon, COULEUR color);

	// 4.8 Dessine des quarts de cercle
	void draw_circle_HD(POINT centre, int rayon, COULEUR color);
	void draw_circle_BD(POINT centre, int rayon, COULEUR color);
	void draw_circle_HG(POINT centre, int rayon, COULEUR color);
	void draw_circle_BG(POINT centre, int rayon, COULEUR color);

	// 4.9 Dessine une ellipse remplie
	void draw_fill_ellipse(POINT F1, POINT F2, int r, COULEUR color);

	// 4.10 Dessine un triangle
	void draw_triangle(POINT p1, POINT p2, POINT p3, COULEUR color);

	// 4.11 Dessine un triangle rempli
	void draw_fill_triangle(POINT p1, POINT p2, POINT p3, COULEUR color);


// ####################
// 5. ECRITURE DE TEXTE
// ####################

// L'affichage se fait dans la fenetre graphique si SDL_ttf est install.
// Sinon il se fait dans dans la fenetre shell

	// 5.1 Affiche du texte avec
	// Le texte est pass dans l'argument "a_ecrire"
	// la police est celle définie par la constante POLICE_NAME
	//           dans graphics.c
	// la taille est passe en argument
	// l'argument p de type POINT est le point en haut  gauche
	//  partir duquel le texte s'affiche
	// la COULEUR C passée en argument est la couleur d'affichage
	void aff_pol(char *a_ecrire, int taille, POINT p, COULEUR C);

	// 5.2 Affiche un entier
	// Meme sémantique que aff_pol()
	void aff_int(int n, int taille, POINT p, COULEUR C);

	// 5.3 Affiche dans la fenetre graphique comme dans une fenetre
	// shell mais sans deroulement. Commence en haut et
	// se termine en bas.
	void write_text(char *a_ecrire);
	void write_int(int n);
	void write_bool(BOOL b);
	void writeln() ;


// ###################
// 6. LECTURE D'ENTIER
// ###################

	// 6.1 Renvoie l'entier tapé au clavier.
	// Cette fonction est bloquante
	int lire_entier_clavier();


// ###################
// 7. GESTION DU TEMPS
// ###################

	// 7.1 Chronometre elementaire
	// Declenchement du chrono
	// Le remet a zero s'il etait deja lance
	void chrono_start();
	// Renvoie la valeur du chrono et ne l'arrete pas
	float chrono_val();

	// 7.2 Attend le nombre de millisecondes passe en argument
	void attendre(int millisecondes);

	// 7.3.1 Renvoie l'heure de l'heure courante
	int heure();
	// 7.3.2 Renvoie le nombre de minutes de l'heure courante
	int minute();
	// 7.3.3 Renvoie le nombre de secondes de l'heure courante
	int seconde();


// ####################
// 8. VALEUR ALÉATOIRES
// ####################

	// 8.1 Renvoie un float dans l'intervalle [0;1[
	float alea_float();
	// 8.2 Renvoie un int dans l'intervalle [0..N[
	// soit N valeurs differentes de 0 a N-1
	int alea_int(int N);


// #########
// 9. DIVERS
// #########

	// 9.1 Renvoie la distance entre deux points
	int distance(POINT P1, POINT P2);

#endif
