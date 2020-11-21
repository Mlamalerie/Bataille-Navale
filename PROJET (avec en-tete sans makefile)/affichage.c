#include "affichage.h"


void affichage(int int_g, int n, int int_m, BATEAU grille[n][int_m]) {
    int int_i,int_j;
    
    // Colonne LETTRE 
    printf("   ");for (int_j = 0 ; int_j < int_m ; int_j++) {  couleur_char(BLANC);printf("  %c",int_j+65);couleur_char(BLEU); if (int_j < 10) printf(" "); }printf("\n");
    
    for (int_i = 0 ; int_i < n ; int_i++) { 
        printf("   +"); for (int_j = 0 ; int_j < int_m ; int_j++) {printf("---+");}printf("\n"); // Traits (estétique)
        
        // Ligne CHIFFRE
        couleur_char(BLANC);if (int_i < 10) {printf(" ");} // si le numéro inf à 10 mettre un espace (estétique) 
        printf("%d ",int_i);couleur_char(BLEU); 
        
        /* DANS LA CASE */
        printf("|"); 
        for (int_j = 0 ; int_j < int_m ; int_j++) {
            
            if (grille[int_i][int_j].mort == 1){couleur_char(MAGENTA);printf(" $ ");couleur_char(BLEU);printf("|");} // si mort 
            else if ((grille[int_i][int_j].touche) && (grille[int_i][int_j].val != -1 )) {couleur_char(ROUGE);printf(" X ");couleur_char(BLEU);printf("|");} // si touché
            else if ((grille[int_i][int_j].touche)){couleur_char(BLANC); printf(" x ");couleur_char(BLEU);printf("|");} // si raté
			else if (grille[int_i][int_j].val != -1) {
                if (grille[int_i][int_j].val == 6){ couleur_char(ORANGE);printf(" P ");couleur_char(BLEU);printf("|");} 
                if (grille[int_i][int_j].val == 4){ couleur_char(ORANGE);printf(" C ");couleur_char(BLEU);printf("|");}
                if (grille[int_i][int_j].val == 3) {couleur_char(ORANGE);printf(" S ");couleur_char(BLEU);printf("|");}
                if (grille[int_i][int_j].val == 2) {couleur_char(ORANGE);printf(" T ");couleur_char(BLEU);printf("|");}
            }
            
            else if (grille[int_i][int_j].bip == 1){ couleur_char(CYAN);printf(" ~ ");couleur_char(BLEU);printf("|");}// couloir d'eau
            else if (grille[int_i][int_j].val == -1){ printf("   |");}
        }
        printf("\n");
    }
    printf("   +"); for (int_j = 0 ; int_j < int_m ; int_j++) {printf("---+");}printf("\n"); // Traits (estétique)
    couleur_char(BLANC);
}

void affichage2(int n, int int_m, BATEAU grille[n][int_m]) {
    int int_i; int int_j;
    printf("   ");for (int_j = 0 ; int_j < int_m ; int_j++) { couleur_char(BLANC);printf("  %c",int_j+65);couleur_char(BLEU);  if (int_j < 10) printf(" "); }printf("\n"); // numéro (estétique) 
    
    for (int_i = 0 ; int_i < n ; int_i++) { 
        
        
        printf("   +"); for (int_j = 0 ; int_j < int_m ; int_j++) {printf("---+");}printf("\n"); // Traits (estétique)
        
        couleur_char(BLANC);if (int_i < 10) {printf(" ");} // si le numéro inf à 10 mettre un espace (estétique) 
         printf("%d ",int_i);couleur_char(BLEU); 
        
        printf("|"); for (int_j = 0 ; int_j < int_m ; int_j++) {
            
            if ((grille[int_i][int_j].mort == 1) && (grille[int_i][int_j].touche == 1)) {couleur_char(MAGENTA);printf (" $ ");couleur_char(BLEU);printf("|");}// si mort
            
            else if ((grille[int_i][int_j].touche == 1) && (grille[int_i][int_j].val != -1)){couleur_char(ROUGE); printf(" X ");couleur_char(BLEU);printf("|");} // si touché
            else if (grille[int_i][int_j].touche == 1) {couleur_char(CYAN); printf(" x ");couleur_char(BLEU);printf("|");} // si raté
            
           else printf("   |");
        }
        printf("\n");
    }
    printf("   +"); for (int_j = 0 ; int_j < int_m ; int_j++) {printf("---+");}printf("\n"); // Traits (estétique) 
    couleur_char(BLANC);
}