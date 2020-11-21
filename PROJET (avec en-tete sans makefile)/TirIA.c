#include "TirIA.h"

int TirIA(int level, int *i, int *j, int *int_imem0, int *int_jmem0, int *cas, int *int_bool_touchefind, int int_n, int int_m, BATEAU grille[int_n][int_m]){
    int ok;
    int ehfaitdanslautresens;
    int l;
    int coule;

printf("---------- DEBUT TirIA \n");
    printf(" _ 0[%d][%d] \n",*int_imem0,*int_jmem0);
    printf("cas : %d \n",*cas);
    printf("touche0 : %d \n",*int_bool_touchefind);


/*** NIVEAU 1 ***/

    /* Tir aléatoire au niveau1 ou si aucun navires trouvé */
    if ((level == 1) || ((level !=1)&&(*int_bool_touchefind == 0))) {
		printf("*\n");
		// saisie random
        *i = randomval(0,int_n-1);*j = randomval(0,int_m-1);
        
        // si touché alors a trouvé un navire, et on garde en mémoire le point
        if (grille[*i][*j].val != -1) {
            *int_bool_touchefind = 1;
            *int_jmem0 = *j; *int_imem0 = *i;
            *cas = 1; // on initialiase, le prochain cas à faire, à 1;
         
        }
        
    }
/*** NIVEAU 2 ***/
    else if (level > 1) {
        /* Tir autour (ici on va tirer en haut en bas en gauche à droite afin de trouver la suite du navire */
     if (*int_bool_touchefind == 1) {
	     printf("**\n");
	     do {
	         ok = 1;
	         // ici on teste tout
            switch (*cas) {
                case 1 : //nord
                *i = *int_imem0-1; 
                *j = *int_jmem0;
                if (*i < 0) ok = 0;
                if (grille[*i][*j].touche == 1 ) ok = 0;
                printf("no\n");
                break;
                case 2 : //sud
                *i = *int_imem0+1; 
                *j = *int_jmem0;
                if (*i > int_n-1) ok = 0;
                if (grille[*i][*j].touche == 1 ) ok = 0;
                printf("su\n");
                
                break;
                case 3 : //ouest
                *i = *int_imem0; 
                *j = *int_jmem0-1;
                if (*j < 0) ok = 0;
                if (grille[*i][*j].touche == 1 ) ok = 0;
                printf("oues\n");
                break;
                case 4 : //est
                *i = *int_imem0; 
                *j = *int_jmem0+1;
                if (*j > int_n-1) ok = 0;
                if (grille[*i][*j].touche == 1 ) ok = 0;
                printf("est\n");
                break;
            }
            
            // si la case existe pas alors passer au cas suivant
            if (ok == 0) *cas = *cas + 1;
            
        } while (ok != 1); // fin boucle pour les cas
        
            // si touché alors prévision du prochain coup
            if (grille[*i][*j].val != -1) {
                // cas 1  : chercher partout à lhorizontal; cas 2 : chercher partout à la verticale
                if (level > 2) {
                printf("touche0find2\n");
                *int_bool_touchefind = 2;
                switch (*cas) { case 1 : *cas = 1;break;case 2 : *cas = 1;break;case 3 :*cas = 2;break; case 4 : *cas = 2;break;}
                }
                else {*int_bool_touchefind = 0;}
            }

            // si il touche pas alors passer au cas suivant, et quand les 4 cas sont fait
            else {printf("si il touche pas alors passer au cas suivant, et quand les 4 cas sont fait\n");
                 *cas = *cas + 1;// if (*cas > 4)  *cas = -1;
                //touche0 = 0;
            }
            
            
            coule = yfotuer(*i,*j,int_n,int_m,grille);
            printf("[%d][%d] coule%d \n",*i,*j,coule);
            if (coule == 1) {
                int_bool_touchefind = 0;
            }
    }
            
    }
    else if (level > 2) {
        printf("level 3");
    
    }
/*** NIVEAU 3 ***/
        /* Tir le long */
  
    
       printf("---------- CHOIX TIR ");
    printf(">>> [%d][%d] \n",*i,*j);  
    if (grille[*i][*j].val != -1) printf(" #TOUCHE \n");
    printf("---------- FIN TirIA \n");
    printf(" _ 0[%d][%d] \n",*int_imem0,*int_jmem0);
    printf("cas : %d    . %d\n",*cas,ehfaitdanslautresens);
    printf("touche0 : %d \n",*int_bool_touchefind);
    return ok;
}

