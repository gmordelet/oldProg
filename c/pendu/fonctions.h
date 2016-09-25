//fonctions.h

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 
#define TAILLE 30

char retour_clavier();
void initialisation(int *debut, char mot[TAILLE], char mot_cache[TAILLE]);
void tour_pendu(int *debut, int coups, int *fin);
void rand_dico(char mot[TAILLE]);


