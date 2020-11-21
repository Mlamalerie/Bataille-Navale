#include "tir.h"

int tir(int int_i, int int_j, int int_n, int int_m, BATEAU grille[int_n][int_m]){
    int toucher = 1;
    
    
    grille[int_i][int_j].touche = 1;
    
    // la case est vide alors pas touché
    if (grille[int_i][int_j].val == -1) toucher = 0;
    
    return toucher; 
}

int SaisieTir(int int_modeia,int int_choix_levelia, int int_joueur,int *booldie, int int_n, int int_m, BATEAU grille1[int_n][int_m], BATEAU grille2[int_n][int_m],int *int_nb_porteavion, int *int_nb_croiseur, int *int_nb_sousmarin, int *int_nb_torpilleur,int *a2, int *b2, int *c2, int *d2, int *i0, int *j0, int *cas, int *touche0) {
    int int_y;
    int int_x;char char_x1;
    int ok;
    int tuer; // booléen 
    int deja; // booléen
    int uncouler = 0; // valeur du bateaux coulé
 
	do {
		deja = 0;
		// si le joueur est un IA
		if ((int_modeia == 2)&&(int_joueur == 2)){ TirIA(int_choix_levelia,&int_y,&int_x,i0,j0,cas,touche0,int_n,int_m,grille1);}
		
		// sinon demander coornée de tir
		else{
		printf(" colonne > "); scanf("%c",&char_x1); viderBuffer();
		int_x = char2int(char_x1);		
		printf(" ligne > "); scanf("%d",&int_y); viderBuffer();
		
		}
		if ((int_y > int_n-1) || (int_x > int_m-1) || (char_x1 < 65)) printf(" /!""\" ERREUR (Saisissez des coordonnées valables) \n");
		
		// si déja touché
		switch (int_joueur) {case 1 :   if (grille2[int_y][int_x].touche == 1) deja = 1;break; case 2 :   if (grille1[int_y][int_x].touche == 1) deja = 1;break;};
		
		if (deja == 1) printf("/! ERREUR (Case déjà touché : saisissez en une autre) \n");
	
	} while ((int_y > int_n-1) || (int_x > int_m-1) || (int_y < 0) || (int_x < 0) || (deja == 1)); // tant que les coordonnée ssont pas valables alors resaisir
	
/* TIRER */ 
	switch (int_joueur) { 
		case 1 : ok = tir(int_y,int_x,int_n,int_m,grille2); tuer = yfotuer(int_y,int_x,int_n,int_m,grille2); // si tuer = 1 alors le bateaux est coulé		
		break; 
		case 2 : ok = tir(int_y,int_x,int_n,int_m,grille1); tuer = yfotuer(int_y,int_x,int_n,int_m,grille1);		
		break;  
	}
	
	*booldie = tuer; // recup le booléen tuer

/* COULER UN BATEAU */
    switch (int_joueur) { 
        case 1 :
        if (tuer == 1) {dead(int_y,int_x,int_n,int_m,grille2); uncouler = grille2[int_y][int_x].val;}
        break;
        
        case 2 :
        if (tuer == 1) {dead(int_y,int_x,int_n,int_m,grille1); uncouler = grille1[int_y][int_x].val; }
        break;   
    }
    
/* DECREMENTER LE NOMRE DE BATEAUX RESTANT */ 
    switch (uncouler) {
            case 6 : if (int_joueur == 2) {*int_nb_porteavion = *int_nb_porteavion - 1; printf("J1 Il vous reste %d PORTE-AVIONS \n",*int_nb_porteavion);}; if (int_joueur == 1) {*a2 = *a2 - 1;printf("J2 Il vous reste %d PORTE-AVIONS \n",*a2);} break;
            case 4 : if (int_joueur == 2) {*int_nb_croiseur = *int_nb_croiseur - 1; printf("J1 Il vous reste %d //// \n",*int_nb_croiseur);}         if (int_joueur == 1)  {*b2 = *b2 - 1 ;printf("J2 Il vous reste %d //// \n",*b2);} break;
            case 3 : if (int_joueur == 2) {*int_nb_sousmarin = *int_nb_sousmarin - 1; printf("J1 Il vous reste %d /// \n",*int_nb_sousmarin);}         if (int_joueur == 1)  {*c2 = *c2 - 1;printf("J2 Il vous reste %d /// \n",*c2);} break;
            case 2 : if (int_joueur == 2) {*int_nb_torpilleur = *int_nb_torpilleur - 1; printf("J1 Il vous reste %d // \n",*int_nb_torpilleur);}           if (int_joueur == 1)  {*d2 = *d2 - 1;printf("J2 Il vous reste %d // \n",*d2);}  break;
        }
    
    return ok;
}