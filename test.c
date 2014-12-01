#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

/**
 * \file test.c
 * \brief fichier ou l'on fait des tests unitaires des fonctions par affichage 
 * */



int main()
{
	//test pour l'affichage du tableau de cartes : void affiche_tab(short mat[52])
		printf("\n\n************************************test d'affichage du tableau cartes************************************\n");
		printf("\n\nvoici le tableau de cartes vide\n");
		affiche_tab(cartes); // on fait appel à la fonction pour vérifier que les 52 cases du tableau cartes s'affichent correctement
			     // N.B: les 52 cases sont initialisés à 0 par défault
	
	
	//test pour le tirage aléatoire d'une carte : short tirer_carte(short player)
		printf("\n\n************************************test tirage carte et association au joueur************************************\n");
		int player; // joueur qui va recevoir la carte 
		int carte; // variable qui reçoit la carte tirée au hazard
		
		do
		{	
			printf("\n---------------------------------------------------------------------------------------------------------------");
			do
			{
				printf("\n\nquel joueur doit reçevoir une carte , JOUEUR(2), BANQUE(1) ou BANQUE_CACHEE(3) ? sortir(4) ");
				scanf("%i",&player);
				if(player!=1&&player!=2&&player!=3&&player!=4)
					printf("\n erreur de saisie !!");
			}while(player!=1&&player!=2&&player!=3&&player!=4);
			
			if(player!=4)
			{
				carte = tirer_carte(player); // on tire une carte pour le joueur choisi
				printf(" \nvoici la carte tirée %i \n",carte);
				affiche_tab(cartes);// on affiche le tableau cartes pour verifier que le joueur choisis a bien été associé à la carte
			}
			
		}while(player!=4);
		printf("\n\n");
	
	
	
	//test pour l'affichage de la couleur et la valeur d'une carte : void afficher_carte(short num)
		printf("\n\n************************************test affichage valeur et couleur carte************************************\n");
		int num_carte; // variable qui reçoit le numéro de la carte à afficher
		do
		{	
			printf("\n---------------------------------------------------------------------------------------------------------------");
			do
			{
				printf("\n\nquelle carte souhaitez vous affiher ? sortir(52) ");
				scanf("%i",&num_carte);
				if(num_carte<0||num_carte>52)
					printf("\nerreur de saisie !! saisir un entier compris entre 0 et 52");
			}while(num_carte<0||num_carte>52);
			
			if(num_carte!=52)
				printf("\n");
				afficher_carte(num_carte);
		
		}while(num_carte!=52);
		printf("\n\n");
		
	
	
	//test pour l'affichage d'une main d'un joueur : void afficher_mains(short player)
		printf("\n\n************************************test affichage main d'un joueur************************************\n");
		int player1; // joueur pour qui on veut afficher la main
		
		do
		{	
			printf("\n---------------------------------------------------------------------------------------------------------------");
			do
			{
				printf("\n\npour quel joueur souhaitez vous afficher la main , JOUEUR(2), BANQUE(1) ? sortir(4) ");
				scanf("%i",&player1);
				if(player1!=1&&player1!=2&&player1!=4)
					printf("\n erreur de saisie !!");
			}while(player1!=1&&player1!=2&&player1!=4);
			
			if(player1!=4)
			{
				affiche_tab(cartes);
				afficher_mains(player1); // on affiche la main du joueur choisi
			}
			
		}while(player1!=4);
		printf("\n\n");
		
	
	
	//test pour l'affichage de la main du banquier y compris la carte cachée : void afficher_mains_cachee(void)
		printf("\n\n************************************test affichage main du banquier avec la carte cachée************************************\n");
		affiche_tab(cartes);
		printf("\nvoici la main du banquier avec la carte cachée \n\n");
		afficher_mains_cachee();
		printf("\n\n");
		
		
					
	//test pour le calcul de la valeur d'une carte : donner_valeur_carte(short player, short carte, short score)	
		printf("\n\n************************************test valeur carte************************************\n");
		int carte1,score,player2,val;
		int arret;
		
		do
		{	
			printf("\n---------------------------------------------------------------------------------------------------------------");
			printf(" \n\npour quelle carte souhaitez vous afficher la valeur (entre 0 et 51) ? ");
			scanf("%i",&carte1);
			printf(" \nquel est le score du joueur ? ");
			scanf("%i",&score);
			printf(" \nde quel joueur il s'agit JOUEUR(2) BANQUE(1) ? ");
			scanf("%i",&player2);
		
			val=donner_valeur_carte(player2, carte1, score);
		
			printf(" \nla valeur de la carte est : %i ",val);
			if(player2==JOUEUR)
				printf(" \n\nle nombre d'as du joueur est : %i ",nb_as_joueur);
			if(player2==BANQUE)
				printf(" \n\nle nombre d'as de la banque est : %i ",nb_as_banque);
			
			printf(" \n\nsouhaitez vous arreter le test ? oui (1), non (0) ");
			scanf("%i",&arret);
		
		}while(arret!=1);
		printf("\n\n");
		
	//test pour la mise à jour du score d'un joueur : short evaluer_score(short player, short carte_recue, short *score)	
		printf("\n\n************************************test mise à jour score************************************\n");
		int carte2,player3,arret1;
		short score1;
		
		do
		{	
			printf("\n---------------------------------------------------------------------------------------------------------------");
			printf(" \n\nquelle est la carte reçue par le joueur (entre 0 et 51) ? ");
			scanf("%i",&carte2);
			printf(" \nquel est le score du joueur ? ");
			scanf("%hd",&score1);
			printf(" \nde quel joueur il s'agit JOUEUR(2) BANQUE(1) ? ");
			scanf("%i",&player3);
		
			score1 = evaluer_score(player3, carte2, &score1);	
		
			if(player3==JOUEUR)
			{
				printf(" \n\nle nouveau score du joueur est : %i ",score1);
				printf(" \n\nle nombre d'as du joueur est : %i ",nb_as_joueur);
			}
			if(player3==BANQUE)
			{
				printf(" \n\nle nouveau score de la banque est : %i ",score1);
				printf(" \n\nle nombre d'as de la banque est : %i ",nb_as_banque);
			}
			
			printf(" \n\nsouhaitez vous arreter le test ? oui (1), non (0) ");
			scanf("%i",&arret1);
		
		}while(arret1!=1);
		printf("\n\n");
		
	return 0;
}
