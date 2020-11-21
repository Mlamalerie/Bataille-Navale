#ifndef __TIR

#define __TIR

#include "ini0.h"
#include <stdio.h>
#include "TirIA.h"
#include "utile.h"
#include "yfotuer.h" 
#include "dead.h" 

int tir(int int_i, int int_j, int int_n, int int_m, BATEAU grille[int_n][int_m]);
int SaisieTir(int int_modeia,int int_choix_levelia, int int_joueur,int *booldie, int int_n, int int_m, BATEAU grille1[int_n][int_m], BATEAU grille2[int_n][int_m],int *int_nb_porteavion, int *int_nb_croiseur, int *int_nb_sousmarin, int *int_nb_torpilleur,int *a2, int *b2, int *c2, int *d2, int *i0, int *j0, int *cas, int *touche0);

#endif