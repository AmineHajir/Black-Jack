#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "fonction.h"


/**
 * \file fonction.c
 * \brief ce fichier source contient les définitions des fonctions qui seront appelés par le programme principale situé dans le fichier source bj.c
 * */

/**
 * \fn affiche_tab(short mat[52])
 * \brief procédure qui affiche le tableau cartes
 * \param mat[52] tableau cartes à 52 cases
*/
void affiche_tab(short mat[52])
{
	int i;
	
	printf("\n");
	for(i=0;i<52;i++)
		printf("%i ",mat[i]);
	
	printf("\n\n");
}

/**
 * \fn short tirer_carte(short player)
 * \brief cette fonction tire aléatoirement un entier entre 0 et 51 qui correspond à une carte 
 * \brief elle associe le player passé en paramètre (banque,joueur,banque_cachee) à cette carte dans le tableau cartes
 * \param player joueur qui sera associé à la carte tirée au hazard
 * \return l'entier (ou la carte) tiré au hazard
*/
short tirer_carte(short player)
{
	int x; /**<variable qui va recevoir le numéro de la carte tirée aléatoirement*/
	
	srand(time(NULL)); //initialisation de la fonction rand() grace à la fonction time(NULL)
			   //time(NULL) donne le nombre de secondes écoulées depuis le premier janvier 1970
	
	x=rand()%52; //rand()%52 génère un entier compris 0 et 51
	while((x<0||x>51)||(cartes[x]!=0)) //on test si rand()%52 renvoi bien un entier compris entre 0 et 51 et on vérifie si cette carte a déjà été tirée
	{
		x=rand()%52;
	}
	
	cartes[x]=player; //on associe player (joueur, banque ou banque cachée) à la carte tirée au hazard
	return x;
}

/**
 * \fn void afficher_carte(short num)
 * \brief procédure qui affiche la valeur et la couleur d'une carte à partir de son positionnement dans le tableau cartes 
 * \param num numéro correspondant à une carte dans le tableau cartes
*/
	
	
void afficher_carte(short num)
{
	int x=num%13; /*!< x reçoit le numéro de la carte ( compris entre 0 et 12 ) à afficher */

	if((num>=DEB_COEURS)&&(num<=FIN_COEURS))
	{
		switch (x)
		{
			case 0 : printf(" As de coeur  ");break;
			case 10 : printf(" Valet de coeur ");break;
			case 11 : printf(" Dame de coeur  ");break;
			case 12 : printf(" Roi de coeur  ");break;
			default : printf(" %i de coeur  ",x+1);
		}
	}
	if((num>=DEB_CARREAUX)&&(num<=FIN_CARREAUX))
	{
		switch (x)
		{
			case 0 : printf(" As de carreaux  ");break;
			case 10 : printf(" Valet de carreaux  ");break;
			case 11 : printf(" Dame de carreaux  ");break;
			case 12 : printf(" Roi de carreaux   ");break;
			default : printf(" %i de carreaux  ",x+1);
		}
	}
	if((num>=DEB_PIQUES)&&(num<=FIN_PIQUES))
	{
		switch (x)
		{
			case 0  : printf(" As de piques  ");break;
			case 10 : printf(" Valet de piques  ");break;
			case 11 : printf(" Dame de piques  ");break;
			case 12 : printf(" Roi de piques   ");break;
			default : printf(" %i de piques  ",x+1);
		}
		
	}
	if((num>=DEB_TREFLES)&&(num<=FIN_TREFLES))
	{
		switch (x)
		{
			case 0  : printf(" As de trefles  ");break;
			case 10 : printf(" Valet de trefles  ");break;
			case 11 : printf(" Dame de trefles  ");break;
			case 12 : printf(" Roi de trefles   ");break;
			default : printf(" %i de trefles  ",x+1);
		}
	}
}

/**
 * \fn void afficher_mains(short player)
 * \brief procédure qui affiche la main d'un joueur ( banque ou joueur ) passé en paramètre sans afficher la carte cahée de la banque
 * \param player le joueur dont on veut afficher la main 
*/

void afficher_mains(short player)
{
	int i;
	
	if(player!=BANQUE_CACHEE)
	{
		for(i=0;i<52;i++)
		{
			if(cartes[i]==player)
				afficher_carte(i);
		}
	}
}
	

/**
 * \fn void afficher_mains_cachee()
 * \brief procédure qui affiche la main de la banque y compris la mains cachée
*/

void afficher_mains_cachee()
{
	int i;
	
	for(i=0;i<52;i++)
	{
		if(cartes[i]==BANQUE||cartes[i]==BANQUE_CACHEE)
			afficher_carte(i);
	}
}

/**
 * \fn short donner_valeur_carte(short player, short carte)
 * \brief fonction qui calcule et retourne la valeur du numéro d'une carte passée en paramètre 
 * \brief elle incrémente le nombre d'as du joueur passé en paramètre si elle reçoit un as comme carte
 * \brief dans le cas ou la carte reçue est un as cette fonction retourne 1 si le score<10 et retourne 11 sinon
 * \param player joueur ( banque ou joueur ) pour lequel le nombre d'as sera incrémenté si cette fonction reçoit un as
 * \param carte numéro qui représente une carte dans le tableau cartes
 * \param score le score du joueur ( banque ou joueur )
 * \return la valeur de la carte reçu par cette fonction 
*/
short donner_valeur_carte(short player, short carte, short score)
{
	int x=carte%13; /**< la variable x reçoit le numéro de la carte ( compris entre 0 et 12 ) pour laquelle on souahite calculer la valeur*/
	 
	switch (x)
	{
		case 0 : 
		{
			if(player == JOUEUR && score>10) 
			{
				nb_as_joueur++;
				return 1;
			}
			if(player == JOUEUR && score<=10)
			{
				nb_as_joueur++;
				return 11;
			}
			if(player == BANQUE && score>10)
			{
				nb_as_banque++;
				return 1;
			}
			if(player == BANQUE && score<=10)
			{
				nb_as_banque++;
				return 11;
			}
		}break;
		
		case 9  :
		case 10 :
		case 11 :
		case 12 :
		{
			return 10;
		}break;
		
		default : return x+1;break;
	}
	return 0;
}

/**
 * \fn short evaluer_score(short player, short carte_recue, short *score)
 * \brief fonction qui met à jour le score du joueur ( banque ou joueur ) passé en paramètre en fonction de la carte reçue
 * \param player joueur ( banque ou joueur ) pour lequel en mettra à jour le score
 * \param carte_reçue numéro qui représente une carte dans le tableau cartes
 * \return le nouveau score du joueur
*/

short evaluer_score(short player, short carte_recue, short *score)
{
	int val = donner_valeur_carte(player, carte_recue, *score);
	
	
	(*score)=(*score)+val;
	
	
	return (*score);
}
