#ifndef __SAVELOAD

#define __SAVELOAD 
 
#include "ini0.h"
#include <stdio.h>
#include <stdlib.h>

void saveGrille( FILE *fic, int int_n, int m, BATEAU grille[int_n][m], int int_a1, int int_b1, int int_c1, int int_d1,int int_tour,int int_choix_modeia);
void loadGrille( FILE *fic, int int_n, int m, BATEAU grille2[int_n][m] , int *int_a1, int *int_b1, int *int_c1, int *int_d1,int *int_tour, int *int_choix_modeia);


#endif