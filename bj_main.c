#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

int main()
{
	/*short carte_cachee,carte_banque,carte1_joueur,carte2_joueur,carte_recue;
	short score_joueur=0;
	short score_banque=0;
	nb_as_joueur=0;
	nb_as_banque=0;
	int continue_banque=1;
	int continue_joueur=1;
	short valeur_carte_cachee,valeur_carte_banque,valeur_carte1_joueur,valeur_carte2_joueur;
	int choix_joueur,choix_banque,i,j;
	
	carte_cachee = tirer_carte(BANQUE_CACHEE);
	carte_banque = tirer_carte(BANQUE);
	carte1_joueur = tirer_carte(JOUEUR);
	carte2_joueur = tirer_carte(JOUEUR);
	
	valeur_carte_cachee = donner_valeur_carte(BANQUE, carte_cachee,score_banque);
	evaluer_score(BANQUE, carte_recue, &score_banque)
	valeur_carte_banque = donner_valeur_carte(BANQUE, carte_banque,score,score_banque);
	valeur_carte1_joueur = donner_valeur_carte(JOUEUR, carte1_joueur);
	valeur_carte2_joueur = donner_valeur_carte(JOUEUR, carte2_joueur);
	
	if(nb_as_joueur==2)
		score_joueur = 12;
	else
		score_joueur = valeur_carte1_joueur + valeur_carte2_joueur;
	if(nb_as_banque==2)
		score_banque = 12;
	else
		score_banque = valeur_carte_cachee + valeur_carte_banque;
	
	
	printf("\n\n ********** main du joueur ********** \n\n");
	afficher_mains(JOUEUR);
	printf(" score : %i ",score_joueur);
	if(score_joueur==21&&score_banque!=21)
	{	
		
		printf("\n\n ********** main du banquier ********** \n\n");
		afficher_mains_cachee();
		printf(" score : %i ",score_banque);
		printf(" \n\njoueur fait un black jack naturel joueur a donc gagné \n\n");
	}
	if(score_joueur!=21&&score_banque==21)
	{
		printf("\n\n ********** main du banquier ********** \n\n");
		afficher_mains_cachee();
		printf(" score : %i ",score_banque);
		printf("\n\n le banquier fait un black jack naturel le banquier a donc gagné \n\n");
	}
	if(score_joueur==21&&score_banque==21)
	{	
		printf("\n\n ********** main du banquier ********** \n\n");
		afficher_mains_cachee();
		printf(" score : %i ",score_banque);
		printf("\n\n vous faites tout les deux un black jack naturel, partie nulle \n\n");
	}
	if(score_joueur!=21&&score_banque!=21)
	{	
		printf("\n\n ********** main du banquier ********** \n\n");
		afficher_mains(BANQUE);
		printf("     carte cachée");
		do
		{	
			i=1;
			j=1;
			if(continue_joueur==1)
			{
				printf(" \n\njoueur voulez vous tirer une nouvelle carte (saisir 1) ou souhaitez vous arreter (saisir 0) ? ");
				scanf("%i",&choix_joueur);
				if(choix_joueur==1)
				{
					carte_recue = tirer_carte(JOUEUR);
					score_joueur = evaluer_score(JOUEUR, carte_recue, &score_joueur);
					if(score_joueur>21&&nb_as_joueur!=0)
					{
						while(score_joueur>21&&i<=nb_as_joueur)
						{
							score_joueur=score_joueur-10;
							i++;
						}
					}
					printf("\n\n ********** nouvelle main du joueur ********** \n\n");
					afficher_mains(JOUEUR);
					printf(" score : %i ",score_joueur);
				}
				if(choix_joueur==0)
				{	
					printf("\n\nle joueur décide de s'arreter");
					continue_joueur=0;
				}
			}
			if(continue_banque==1)
			{
				printf(" \n\nbanquier voulez vous tirer une nouvelle carte (saisir 1) ou souhaitez vous arreter (saisir 0) ? ");
				if(choix_joueur==0)
				{
					if(score_banque>score_joueur)
						choix_banque=0;
					if(score_banque<=score_joueur)
					{
						if(score_banque<17)
							choix_banque=1;
						if(score_banque>=17)
							choix_banque=0;
					}
				}
				if(choix_joueur==1)
				{
					if(score_banque<17)
						choix_banque=1;
					if(score_banque>=17)
						choix_banque=0;
				}
				if(choix_banque==1)
				{
					carte_recue = tirer_carte(BANQUE);
					score_banque = evaluer_score(BANQUE, carte_recue, &score_banque);
					if(score_banque>21&&nb_as_banque!=0)
					{
						while(score_joueur>21&&j<=nb_as_joueur)
						{
							score_joueur=score_joueur-10;
							j++;
						}
					}
					printf("\n\n ********** nouvelle main du banquier ********** \n\n");
					afficher_mains(BANQUE);
					printf("    carte cachée");
				}
				if(choix_banque==0)
				{	
					printf("\n\nle banquier décide de s'arreter");
					continue_banque=0;
				}
			}
		}while((choix_banque!=0||choix_joueur!=0)&&(score_joueur<21)&&(score_banque<21));
		
		printf("\n\n\n\n -------------------------------RESULTAT DE LA PARTIE---------------------------------------");
		printf("\n\n ********** nouvelle main du joueur ********** \n\n");
		afficher_mains(JOUEUR);
		printf(" score : %i ",score_joueur);
		
		printf("\n\n ********** nouvelle main du banquier ********** \n\n");
		afficher_mains_cachee();
		printf(" score : %i ",score_banque);
				
		if(score_joueur==21&&score_banque==21)		
			printf("\n\n black jack pour les deux joueurs , personne n'a gagné");
		if(score_joueur==21&&score_banque!=21)
			printf("\n\n le joueur fait un black jack, il gagne donc la partie");
		if(score_joueur!=21&&score_banque==21)
			printf("\n\n le banquier fait un black jack, il gagne donc la partie");
		if(score_joueur!=21&&score_banque!=21)
		{
			if(score_joueur<21&&score_banque<21)
			{
				if(score_joueur<score_banque)
						printf("\n\n score du joueur est inférieur à celui du banquier donc le banquier a gagné");
				if(score_banque<score_joueur)
						printf("\n\n score du banquier est inférieur à celui du joueur donc le joueur a gagné");
				if(score_banque==score_joueur)
						printf("\n\n égalité, personne n'a gagné");
			}
			if(score_joueur<21&&score_banque>21)
				printf("\n\n le joueur gagne , le banquier a dépassé 21");
			if(score_joueur>21&&score_banque<21)
				printf("\n\n le banquier gagne , le joueur a dépassé 21");
		}
		
	}			
	printf("\n\n");*/
	
	
	return 0;	
}