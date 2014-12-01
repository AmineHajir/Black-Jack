#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

/**
 *\file bj.c
 *\brief Jeu du Black Jack simplifié
 *\author Hajir Mohammed Amine
 *\author Yamni Youssef
 *\author Okach Ayas
 *\version 1.0
 *\date 25 Novembre 2014
 */


/**
 * \fn int main()
 * \brief programme principal qui fait appel à toute les fonctions et variables définies dans le fichier source fonction.c  
 */
int main()
{
	//variables pour manipuler les cartes, le score et le choix de la banque 
	short carte_cachee; //!< permet de stocker un entier compris entre 0 et 51 généré aléatoirement qui représente la carte tirée par la banque 
			    //!< cette carte n'est pas visible par le joueur
	
	short carte_banque; //!< permet de stocker un entier compris entre 0 et 51 généré aléatoirement qui représente la carte tirée par la banque 
			    //!< cette carte est visible par le joueur
	
	short score_banque=0; //!< variable qui stocke le score de la banque
			      //!< a chaque tirage d'une nouvelle carte, le score de la banque est mis à jour et stocké dans la variable score_banque	
	
	int choix_banque=1; //!< variable qui indique le choix de la banque
			    //!< cette variable vaut 1 si le joueur décide de poursuivre le jeu et vaut 0 s'il souhaite s'arreter
	
	//variables pour manipuler les cartes le score et le choix du joueur
	short carte_joueur; //!< permet de stocker un entier compris entre 0 et 51 généré aléatoirement qui représente la carte tirée par le joueur
	
	short score_joueur=0; //!< variable qui stocke le score du joueurs
			      //!< a chaque tirage d'une nouvelle carte, le score du joueur est mis à jour et stocké dans la variable score_joueur	
	
	int choix_joueur=1; //!< variable qui indique le choix du joueurs
			    //!< cette variable vaut 1 si le joueur décide de poursuivre le jeu et vaut 0 s'il souhaite s'arreter
	
	
	// début du jeu et distribution de deux cartes pour chaque joueur dont une cachée pour le banquier
	
	carte_cachee = tirer_carte(BANQUE_CACHEE); // distribution de la première carte au banquier. il s'agit de la carte cachée
	/*printf(" \n\n  carte cachée : %hd",carte_cachee);
	afficher_carte(carte_cachee);*/
	score_banque = evaluer_score(BANQUE,carte_cachee,&score_banque);// initialisation du score du banquier après réception de la première carte
	/*printf(" \n\n  nbre as banque : %hd",nb_as_banque);
	printf(" \n\n  score banque : %hd",score_banque);*/
	
	carte_banque = tirer_carte(BANQUE); // distribution de la deuxième carte au banquier. cette carte est visible
	/*printf(" \n\n  carte visible : %hd",carte_banque);
	afficher_carte(carte_banque);*/
	score_banque = evaluer_score(BANQUE,carte_banque,&score_banque);// mise à jour du score du banquier après réception de la deuxième carte
	/*printf(" \n\n  nbre as banque : %hd",nb_as_banque);
	printf(" \n\n  score banque : %hd",score_banque);*/
	
	carte_joueur = tirer_carte(JOUEUR); // distribution de la première carte au joueur
	/*printf(" \n\n  première carte joueur : %hd",carte_joueur);
	afficher_carte(carte_joueur);*/
	score_joueur = evaluer_score(JOUEUR,carte_joueur,&score_joueur); // initialisation du score du joueur après réception de la première carte 
	/*printf(" \n\n  nbre as joueur : %hd",nb_as_joueur);
	printf(" \n\n  score joueur : %hd",score_joueur);*/
	
	carte_joueur = tirer_carte(JOUEUR); // distribution de la deuxième carte au joueur
	/*printf(" \n\n  deuxième carte joueur : %hd",carte_joueur);
	afficher_carte(carte_joueur);*/
	score_joueur = evaluer_score(JOUEUR,carte_joueur,&score_joueur); // mise à jour du score du joueur après réception de la deuxième carte 
	/*printf(" \n\n  nbre as joueur : %hd",nb_as_joueur);
	printf(" \n\n  score joueur : %hd",score_joueur);*/
	
	// on dit qu'un joueur fait un black jack naturel s'il fait un score de 21 dès le début du jeu 
	// c'est à dire à la reception des deux premières cartes du jeu le score du joueur est 21
	// on vérifie si l'un des deux joueurs (ou les deux) fait un black jack naturel 
	
	if(score_joueur == 21 || score_banque == 21)
	{	
		// s'il y a black jack naturel on affiche toutes les cartes y compris la carte cachée du banquier car la partie est déjà finie
		printf("\n\n\n----------------------------------------------------------------------------------------------------------------------------");
		printf("\n\n****************************** MAIN JOUEUR ******************************\n\n");
		afficher_mains(JOUEUR);
		printf(" \n\n  score joueur : %hd",score_joueur);
		printf("\n\n****************************** MAIN BANQUE ******************************\n\n");
		afficher_mains_cachee();
		printf(" \n\n  score banque : %hd",score_banque);
		printf("\n\n----------------------------------------------------------------------------------------------------------------------------");
		// on affiche le résultat de la partie 
		printf("\n\n\n\n----------------------------------------------------------------------------------------------------------------------------");
		printf("\n\n****************************** RESULTAT DE LA PARTIE ******************************\n\n");
		if(score_joueur == 21 && score_banque == 21) // cas ou les deux joueurs font un black jack naturel
			printf("\n  les deux joueurs font un black jack naturel, il y a donc égalité");
		if(score_joueur == 21 && score_banque != 21) // cas ou le joueur seul fait un black jack naturel
			printf("\n  le joueur fait un black jack naturel, il a donc gagné");
		if(score_joueur != 21 && score_banque == 21) // cas ou le banquier seul fait un black jack naturel
			printf("\n  le banquier fait un black jack naturel, il a donc gagné");
		printf("\n\n----------------------------------------------------------------------------------------------------------------------------");
	}
	
	// dans le cas ou il n'y a pas de black jack naturel on poursuit le jeu
	
	if(score_joueur != 21 && score_banque != 21)
	{
		// s'il n'y a pas de black jack naturel on affiche les mains des deux joueurs sans afficher la carte cachée du banquier ni son score
		printf("\n\n\n\n----------------------------------------------------------------------------------------------------------------------------");
		printf("\n\n****************************** MAIN JOUEUR ******************************\n\n");
		afficher_mains(JOUEUR);
		printf(" \n\n  score joueur : %hd",score_joueur);
		printf("\n\n****************************** MAIN BANQUE ******************************\n\n");
		afficher_mains(BANQUE);
		printf("  ?????????\n\n");
		printf("----------------------------------------------------------------------------------------------------------------------------");
		// une fois les deux mains affichées, on demande au joueur s'il souhaite poursuivre le jeu ou s'arreter
		do
		{
			if(choix_joueur!=0) // 
			{
				printf("\n\n\n\n----------------------------------------------------------------------------------------------------------------------------");
				printf("\n\n****************************** CHOIX JOUEUR ******************************\n\n");
				do
				{
					printf("  joueur, voulez vous tirer une nouvelle carte saisir(1) ou souhaitez-vous arreter saisir(0) ? ");
					scanf("%i",&choix_joueur);
				}while(choix_joueur != 1 && choix_joueur != 0); // controle du choix du joueur
		
				if(choix_joueur == 0)
				{
					printf("\n  le joueur décide de s'arreter \n");
					printf("\n----------------------------------------------------------------------------------------------------------------------------");
				}
				if(choix_joueur == 1)
				{
					printf("\n  le joueur décide de tirer une nouvelle carte \n");
					carte_joueur = tirer_carte(JOUEUR); // distribution d'une nouvelle carte au joueur
					printf("\n  la nouvelle carte reçue par le joueur est");
					afficher_carte(carte_joueur);
					printf("\n\n----------------------------------------------------------------------------------------------------------------------------\n\n");
					/*printf(" \n\n  nouvelle carte joueur : %hd",carte_joueur);*/
					score_joueur = evaluer_score(JOUEUR,carte_joueur,&score_joueur); // mise à jour du score du joueur après réception de la nouvelle carte 
					/*printf(" \n\n  nbre as joueur : %hd",nb_as_joueur);
					printf(" \n\n  score joueur : %hd",score_joueur);*/
					if(score_joueur >= 21) // si le score du joueur devient supérieur ou égale à 21 après le tirage de la nouvelle carte, je jeu est arrété
						break;
					
					// quand le joueur reçoit une nouvelle carte, on affiche sa nouvelle main au banquier pour que ce dernier puisse faire un choix à son tour
					printf("\n\n\n\n----------------------------------------------------------------------------------------------------------------------------");
					printf("\n\n****************************** NOUVELLE MAIN JOUEUR ******************************\n\n");
					afficher_mains(JOUEUR);
					printf(" \n\n  score joueur : %hd",score_joueur);
					printf("\n\n----------------------------------------------------------------------------------------------------------------------------");
				}
			}
		
			//après que le joueur ait fait son choix, on déterminera le choix du banquier en fonction du choix du joueur, du score du joueur et du score du banquier
			if( (choix_banque!=0) && (score_joueur<21) )
			{
				printf("\n\n\n\n----------------------------------------------------------------------------------------------------------------------------");
				printf("\n\n****************************** CHOIX BANQUE ******************************\n\n");
				if(score_banque >= 17) // le banquier décidera de s'arreter si son score est supérieur ou égale à 17 quelque soit le score et le choix du joueur
					choix_banque = 0;
				if(score_banque < 17)
				{
					if( (score_banque > score_joueur) && (choix_joueur == 0) )
						choix_banque = 0; // si le score du banquier est inférieur à 17 mais supérieur à celui du joueur 
								  // si en plus le joueur décide de s'arreter alors le banquier décidera de s'arreter également
					choix_banque = 1; // le banquier demandera une nouvelle carte dans tous les autres cas 
				}
		
				if(choix_banque == 0)
				{
					printf("  le banquier décide de s'arreter \n\n");
					printf("----------------------------------------------------------------------------------------------------------------------------");
				}
		
				if(choix_banque == 1)
				{
					printf("  le banquier décide de tirer une nouvelle carte \n");
					carte_banque = tirer_carte(BANQUE); // distribution d'une nouvelle carte visible au banquier. 
					printf("\n  la nouvelle carte reçue par le banquier est");
					afficher_carte(carte_banque);
					printf("\n\n----------------------------------------------------------------------------------------------------------------------------\n\n");
					/*printf(" \n\n  carte visible : %hd",carte_banque);*/
					score_banque = evaluer_score(BANQUE,carte_banque,&score_banque);// mise à jour du score du banquier après réception de la nouvelle carte
					/*printf(" \n\n  nbre as banque : %hd",nb_as_banque);
					printf(" \n\n  score banque : %hd",score_banque);*/
					if(score_banque >= 21) //si le score du banquier devient supérieur ou égale à 21 après le tirage de la nouvelle carte, je jeu est arrété
						break;
			
					// quand le joueur reçoit une nouvelle carte, on affiche sa nouvelle main au banquier pour que ce dernier puisse faire un choix à son tour
					printf("\n\n\n\n----------------------------------------------------------------------------------------------------------------------------");
					printf("\n\n****************************** NOUVELLE MAIN BANQUIER ******************************\n\n");
					afficher_mains(BANQUE);
					printf("  ?????????\n\n");
					printf("----------------------------------------------------------------------------------------------------------------------------");
				}
			}
		}while( (score_joueur < 21) && (score_banque < 21) && ( (choix_joueur != 0) || (choix_banque != 0) ) );
		
		
		printf("\n\n\n----------------------------------------------------------------------------------------------------------------------------");
		printf("\n\n****************************** MAIN FINALE JOUEUR ******************************\n\n");
		afficher_mains(JOUEUR);
		printf(" \n\n  score joueur : %hd",score_joueur);
		printf("\n\n****************************** MAIN FINALE BANQUE ******************************\n\n");
		afficher_mains_cachee();
		printf(" \n\n  score banque : %hd",score_banque);
		printf("\n\n----------------------------------------------------------------------------------------------------------------------------");
		
		printf("\n\n\n\n----------------------------------------------------------------------------------------------------------------------------");
		printf("\n\n****************************** RESULTAT DE LA PARTIE ******************************\n\n");
		if(score_joueur == 21) // cas ou le joueur fait un black jack 
			printf("\n  le joueur fait un black jack, il gagne donc la partie");
		if(score_banque == 21) // cas ou le banquier fait un black jack 
			printf("\n  le banquier fait un black jack, il gagne donc la partie");
		if(score_joueur > 21)
			printf("\n le joueur brule car son score a dépassé 21, le banquier gagne donc la partie");
		if(score_banque > 21)
			printf("\n le banquier brule car son score a dépassé 21, le joueur gagne donc la partie");
		
		if(choix_joueur == 0 && choix_banque == 0)
		{
			if(score_joueur > score_banque)
				printf("\n  le score du joueur est supérieur à celui du banquier, le joueur gagne donc la partie");
			if(score_joueur < score_banque)
				printf("\n  le score du banquier est supérieur à celui du joueur, le banquier gagne donc la partie");
			if(score_joueur == score_banque)
				printf("\n  le score du banquier est égale à celui du joueur, aucun gagnant !");
		}
		printf("\n\n----------------------------------------------------------------------------------------------------------------------------");
			
	}
		
	printf("\n\n\n");
	return 0;
}
