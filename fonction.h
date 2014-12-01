/**
 * \file fonction.h
 * \brief ce fichier d'en-tete contient les en-tete des fonctions définies dans le fichier source fonction.c
 * \brief ce fichier contient aussi la déclaration des constantes symboliques, des variables globales et des structures de données utilisées (tableau)
 * */

/**
 * \var short cartes[52]
 * \brief structure de données utilisé pour le jeu black jack
 * \brief tableau de 52 cases. chaque case représente une carte de jeu.
 * \brief chaque case du tableau peut avoir 4 valeurs possibles : 0,1,2 ou 3.
 * \brief la valeur d'une case vaut 0 si la carte correspondante n'a toujours pas été tirée
 * \brief la valeur d'une case vaut 1 si la carte correspondante a été tirée par la banque et que cette carte est visible par le joueur
 * \brief la valeur d'une case vaut 2 si la carte correspondante a été tirée par le joueur
 * \brief la valeur d'une case vaut 3 si la carte correspondante a été tirée par la banque et que cette carte n'est pas visible par le joueur
*/
short cartes[52];

/**
 * \var short nb_as_joueur
 * \brief variable qui permet de stocker le nombre d'as du joueur
*/
short nb_as_joueur;

/**
 * \var short nb_as_banque
 * \brief variable qui permet de stocker le nombre d'as de la banque
*/
short nb_as_banque;

/**
 * \def LIBRE
 * \brief représente une carte qui n'a pas été tirée 
 * \brief sa valeur dans le tableau cartes est 0
*/
#define LIBRE		0

/**
 * \def BANQUE
 * \brief représente une carte qui a été tirée par la banque et visible par le joueur 
 * \brief sa valeur dans le tableau cartes est 1
*/
#define BANQUE		1

/**
 * \def JOUEUR
 * \brief représente une carte qui a été tirée par le joueur 
 * \brief sa valeur dans le tableau cartes est 2
*/
#define JOUEUR		2

/**
 * \def BANQUE_CACHEE
 * \brief représente une carte qui a été tirée par la banque et non visible par le joueur 
 * \brief sa valeur dans le tableau cartes est 3
*/
#define BANQUE_CACHEE	3

/**
 * \def DEB_COEURS
 * \brief indice du début des cartes de couleur coeur 
 * \brief permet d'identifier dans quelle case se situe l'as de coeur dans le tableau des cartes
*/
#define DEB_COEURS	0

/**
 * \def FIN_COEURS
 * \brief indice de fin des cartes de couleur coeur 
 * \brief permet d'identifier dans quelle case se situe le roi de coeur dans le tableau des cartes
*/
#define FIN_COEURS	12

/**
 * \def DEB_CARREAUX
 * \brief indice du début des cartes de couleur carreaux 
 * \brief permet d'identifier dans quelle case se situe l'as de carreaux dans le tableau des cartes
*/
#define DEB_CARREAUX	13

/**
 * \def FIN_CARREAUX
 * \brief indice de fin des cartes de couleur carreaux 
 * \brief permet d'identifier dans quelle case se situe le roi de carreaux dans le tableau des cartes
*/
#define FIN_CARREAUX	25

/**
 * \def DEB_PIQUES
 * \brief indice du début des cartes de couleur piques 
 * \brief permet d'identifier dans quelle case se situe l'as de piques dans le tableau des cartes
*/
#define DEB_PIQUES	26

/**
 * \def FIN_PIQUES
 * \brief indice de fin des cartes de couleur piques
 * \brief permet d'identifier dans quelle case se situe le roi de pique dans le tableau des cartes
*/
#define FIN_PIQUES	38

/**
 * \def DEB_TREFLES
 * \brief indice du début des cartes de couleur trefles
 * \brief permet d'identifier dans quelle case se situe l'as de trefles dans le tableau des cartes
*/
#define DEB_TREFLES	39

/**
 * \def FIN_TREFLES
 * \brief indice de fin des cartes de couleur trefles
 * \brief permet d'identifier dans quelle case se situe le roi de trefles dans le tableau des cartes
*/
#define FIN_TREFLES	51


short tirer_carte(short player);
void affiche_tab(short mat[52]);
void afficher_carte(short num);
void afficher_mains(short player);
void afficher_mains_cachee(void);
short donner_valeur_carte(short player, short carte, short score);
short evaluer_score(short player, short carte_recue, short *score);
