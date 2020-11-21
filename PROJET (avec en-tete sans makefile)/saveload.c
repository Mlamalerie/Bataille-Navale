#include "saveload.h"

void saveGrille( FILE *fic, int int_n, int m, BATEAU grille[int_n][m], int int_a1, int int_b1, int int_c1, int int_d1,int int_tour,int int_choix_modeia) {
    
    // save valeur des bateaux
    for (int int_i = 0; int_i<int_n ; int_i++){
        for (int int_j = 0; int_j<m ; int_j++){
            fprintf(fic,"%d ",grille[int_i][int_j].val);
        }
        fprintf(fic,"\n");
    }
    // save valeur des bateaux
    for (int int_i = 0; int_i<int_n ; int_i++){
        for (int int_j = 0; int_j<m ; int_j++){
             fprintf(fic,"%d ",grille[int_i][int_j].touche);
        }
        fprintf(fic,"\n");
    }
    // save booléen mort des bateaux
    for (int int_i = 0; int_i<int_n ; int_i++){
        for (int int_j = 0; int_j<m ; int_j++){
             fprintf(fic,"%d ",grille[int_i][int_j].mort);
        }
        fprintf(fic,"\n");
    }
    // save booléen bip des bateaux
    for (int int_i = 0; int_i<int_n ; int_i++){
        for (int int_j = 0; int_j<m ; int_j++){
            fprintf(fic,"%d ",grille[int_i][int_j].bip);
        }
        fprintf(fic,"\n");
    } 
    fprintf(fic,"%d ",int_a1);//save nombre de porte avions
    fprintf(fic,"%d ",int_b1);// save nombre de croiseurs
    fprintf(fic,"%d ",int_c1);// save nombre de sous marins
    fprintf(fic,"%d ",int_d1);// save nombre de torpilleurs
    fprintf(fic,"%d ",int_tour);// save le tour du joueur
    fprintf(fic,"%d ",int_choix_modeia); // mode ia
}
void loadGrille( FILE *fic, int int_n, int m, BATEAU grille2[int_n][m] , int *int_a1, int *int_b1, int *int_c1, int *int_d1,int *int_tour, int *int_choix_modeia) {
    // charge valeur des bateaux
    for (int int_i = 0; int_i<int_n ; int_i++){
        for (int int_j = 0; int_j<m ; int_j++){
            fscanf(fic,"%d ",&grille2[int_i][int_j].val);
        }
    }
    // charge valeur des bateaux
    for (int int_i = 0; int_i<int_n ; int_i++){
        for (int int_j = 0; int_j<m ; int_j++){
            fscanf(fic,"%d ",&grille2[int_i][int_j].touche);
        }
    }
    // charge booléen mort des bateaux
    for (int int_i = 0; int_i<int_n ; int_i++){
        for (int int_j = 0; int_j<m ; int_j++){
            fscanf(fic,"%d ",&grille2[int_i][int_j].mort);
        }
    }
    // charge booléen bip des bateaux
    for (int int_i = 0; int_i<int_n ; int_i++){
        for (int int_j = 0; int_j<m ; int_j++){
            fscanf(fic,"%d ",&grille2[int_i][int_j].bip);
        }
    }
    
    fscanf(fic,"%d ",int_a1);//charge nombre de porte avions
    fscanf(fic,"%d ",int_b1);// charge nombre de croiseurs
    fscanf(fic,"%d ",int_c1);// charge nombre de sous marins
    fscanf(fic,"%d ",int_d1);// charge nombre de torpilleurs
    fscanf(fic,"%d ",int_tour);// charge le tour du joueur
    fscanf(fic,"%d ",int_choix_modeia);
}