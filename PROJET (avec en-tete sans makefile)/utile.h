#ifndef __UTILE

#define __UTILE
 
#define NOIR      1
#define ROUGE     2
#define VERT      3
#define ORANGE    4
#define BLEU      5
#define MAGENTA   6
#define CYAN      7
#define BLANC     8
#define JAUNE     9 
 
#include <stdio.h>
#include <stdlib.h>

void couleur_char(char c);
float pourcentage(int n, int m, BATEAU t[n][m]); 
void viderBuffer();
void clrscr();
int saisie1int(int *a, int int_x, int int_y);
int char2int(char char_x);


#endif