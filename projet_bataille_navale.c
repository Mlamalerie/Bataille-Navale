#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
 
#define NOIR      1
#define ROUGE     2
#define VERT      3
#define ORANGE    4
#define BLEU      5
#define MAGENTA   6
#define CYAN      7
#define BLANC     8
#define JAUNE     9

//
struct BATEAU
{
	int val; // valeur du bateau
	int touche; // booléen touche
	
	int mort; // booléen mort
	int bip; // booléen bip (si bip = 1 alors on ne peut pas poser)
	
};
typedef struct BATEAU BATEAU; 


int chenille(int i, int j, int n, int m, BATEAU t[n][m]);
void dead(int i, int j, int n, int m, BATEAU t[n][m]);
int tir(int i, int j, int n, int m, BATEAU t[n][m]);
void ini0(int n, int m, BATEAU tab0[n][m]);
void affichage(int g, int n, int m, BATEAU tab0[n][m]);
void affichage2(int n, int m, BATEAU tab0[n][m]);
int saisie1int(int *a, int x, int y);
int char2int(char x);
int TirIA(int level, int *i, int *j, int *int_imem0, int *int_jmem0, int *cas, int *int_bool_touchefind, int int_n, int int_m, BATEAU grille[int_n][int_m]);

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
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void ini0(int n, int m, BATEAU tab0[n][m]) {
    
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            
        tab0[i][j].val = -1;
        tab0[i][j].touche = 0;
        tab0[i][j].bip = 0;
        tab0[i][j].mort = 0;//
        }
    }
    
    
}
void clrscr(){
	for (int z=0; z < 4; z++) {
			system ("clear");
			}
    
}
void couleur_char(char c)
{
   switch (c) {
      case NOIR    : printf("\033[30m" ); break;
      case ROUGE   : printf("\033[31m" ); break;
      case VERT    : printf("\033[32m" ); break;
      case ORANGE  : printf("\033[33m" ); break;
      case BLEU    : printf("\033[34m" ); break;
      case MAGENTA : printf("\033[35m" ); break;
      case CYAN    : printf("\033[36m" ); break;
      case BLANC   : printf("\033[37m" ); break;
      case JAUNE   : printf("\033[00m" ); break;
      default      : printf("\ncouleur non répertoriée\n");
   }
}


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


int pose(int genre, int int_taillebat,int int_i, int int_j,int int_hdir, int int_dsens, int n, int int_m, BATEAU t[n][int_m]) {
    int ok = 1; // booléen
    
/* PEUT ON POSER ? */    
	int int_l = 0;
	for (int int_k=0; int_k<int_taillebat;int_k++) {
		
		// Selon la direction 
		switch (int_hdir) {
			case 0 : if ( (int_i+int_l > n-1) || (int_i+int_l < 0) || (t[int_i+int_l][int_j].bip == 1)) ok = 0; 
			break;
			case 1 : if ((int_j+int_l > int_m-1) || (int_j+int_l < 0) || (t[int_i][int_j+int_l].bip == 1)) ok = 0; 
			break;
		}
		// Selon le sens
		switch (int_dsens) {
			case 0 : int_l++; break;
			case 1 : int_l--; break;
			}
	}
    
/*  SI ON PEUT POSER ALORS */    
    if (ok == 1) { 
		
        // Genre de bateaux à poser
        BATEAU bat;
        bat.val = genre;
        bat.mort = 0;
        bat.touche = 0;
        
        int int_l = 0;
        for (int int_k=0;int_k < int_taillebat; int_k++) {
             
            switch (int_hdir) {
                case 0 : t[int_i+int_l][int_j] = bat; //pose
                
                // couloir d'eau
                t[int_i+int_l][int_j].bip = 1;
                if (int_i+int_l-1 >= 0) t[int_i+int_l-1][int_j].bip = 1;
                if ((int_i+int_l-1 >= 0)&&(int_j+1 <= int_m-1)) t[int_i+int_l-1][int_j+1].bip = 1;
                if (int_j+1 <= int_m-1) t[int_i+int_l][int_j+1].bip = 1;
           /**/ if ((int_i+int_l+1 <= n-1)&&(int_j+1 <= int_m-1)) t[int_i+int_l+1][int_j+1].bip = 1;
                if (int_i+int_l+1 <= n-1) t[int_i+int_l+1][int_j].bip = 1;
                if ((int_i+int_l+1 <= n-1)&&(int_j-1 >= 0)) t[int_i+int_l+1][int_j-1].bip = 1;
                if (int_j-1 >= 0) t[int_i+int_l][int_j-1].bip = 1;
                if ((int_i+int_l-1 >= 0)&&(int_j-1 >= 0)) t[int_i+int_l-1][int_j-1].bip = 1;
                
                break;
                
                case 1 : t[int_i][int_j+int_l] = bat; // pose
                
                // couloir d'eau
                t[int_i][int_j+int_l].bip = 1;
                if (int_i-1 >= 0) t[int_i-1][int_j+int_l].bip = 1;
                if ((int_i-1 >= 0)&&(int_j+int_l+1 <= int_m-1)) t[int_i-1][int_j+int_l+1].bip = 1;
                if (int_j+int_l+1 <= int_m-1) t[int_i][int_j+int_l+1].bip = 1;
            /**/if ((int_i+1 <= n-1)&&(int_j+int_l+1 <= int_m-1)) t[int_i+1][int_j+int_l+1].bip = 1;
                if (int_i+1 <= n-1) t[int_i+1][int_j+int_l].bip = 1;
                if ((int_i+1 <= n-1)&&(int_j+int_l-1 >= 0)) t[int_i+1][int_j+int_l-1].bip = 1;
                if (int_j+int_l-1 >= 0) t[int_i][int_j+int_l-1].bip = 1;
                if ((int_i-1 >= 0)&&(int_j+int_l-1 >= 0)) t[int_i-1][int_j+int_l-1].bip = 1;
                
                break;
            }
            
            // pose en suivant un sens
            switch (int_dsens) {
                case 0 : int_l++;      break;
                case 1 : int_l--;      break;
            }
        } 
 
        
    }

  return ok;  
    
}
int randomval (int x, int y) {
	return ((float)(rand() / (float)RAND_MAX)*(y-x+1)) + x;
}

void saisieGrille(int int_joueur, int int_n, int int_m, BATEAU t1[int_n][int_m],int int_nb_porteavion, int int_nb_croiseur, int int_nb_sousmarin, int int_nb_torpilleur){
    int int_nb; // int_nb de bateau à poser
    int int_taillebat; // taille des bateau
    int int_i,int_j; // coordonnée de la tete
    char char_j; // caractère saisie pour la colonne
    int int_d; // direction (horizontale,vertical = 1,0)
    int int_s; // sens (0,1)
    int ok; // booléen qui vaut 1 quand tout va bien
    int int_choix; // gauche droite haut bas

int int_boolencore = 1;
while (int_boolencore == 1) { // TAnt que l'utilisateur n'est pas satisfait on va recommencer  
	/* Initialisation de la Grille */
	ini0(int_n,int_m,t1);   
	
    // Pour chaque type de bateau
    for (int int_k=0; int_k<4;int_k++){
        
       // selon le type de bateau, on a une taille et un nombre de bateaux différents
        switch (int_k) {
            case 0 : int_nb = int_nb_porteavion; int_taillebat = 6; break;
            case 1 : int_nb = int_nb_croiseur; int_taillebat = 4;  break;
            case 2 : int_nb = int_nb_sousmarin; int_taillebat = 3;  break;
            case 3 : int_nb = int_nb_torpilleur; int_taillebat = 2;  break;
        }
        
/*** RENTREE DES BATEAUX ***/
		
        if (int_nb != 0) { // si le nombre de int_k-bateaux n'est pas nulle alors
			do {
			clrscr();
			printf("\n//////////////////////////////////////////////////\n");
			printf("//////////// ** DEPOT DES BATEAUX ** /////////////\n");
			printf("//////////////////////////////////////////////////\n");
			printf("                              ");if (int_joueur == 1) couleur_char(ROUGE); if (int_joueur == 2) {couleur_char(CYAN);}printf("////// JOUEUR %d ////\n",int_joueur);couleur_char(BLANC);
			printf("--------------- POSER VOS BATEAUX --------------- \n");
				
				
				do {
				/* Saisie des coordonnées de la tête */
					do {
					ok = 1;
					affichage(0,int_n,int_m,t1);
					
					// selon le type de bateau afficher :
					switch (int_k) {
					case 0 : printf("\n ## PORTE-AVIONS [%d CASES] #### \n\n",int_taillebat); break;
					case 1 : printf("\n ## CROISEURS [%d CASES] #### \n\n",int_taillebat);  break;
					case 2 : printf("\n ## SOUS-MARINS [%d CASES] #### \n\n",int_taillebat);  break;
					case 3 : printf("\n ## TORPILLEURS [%d CASES] #### \n\n",int_taillebat);  break;
					}
					
					printf(" %c COORDONNEES DE LA TETE : \n",35); 
					
					printf(" > colonne : ");scanf("%c",&char_j);viderBuffer();
					int_j = char2int(char_j); // conversion du caractère en entier
					printf(" >   ligne : ");scanf("%d",&int_i);viderBuffer();
					
					// si on ne peut pas choisir cette tête alors
					if (t1[int_i][int_j].bip == 1) {ok = 0;printf("Vous ne pouvez pas choisir cette tête \n");}
					
					} while ((int_m-1 < int_j) || (int_j < 0) || (int_i < 0) || (int_n-1 < int_i) || (ok != 1)); // tant que l'utilisateur n'a pas bien saisie alors recommencer
					
				/* Saisie de la direction du corps du bateau */    
					printf("\n %c DIRECTION : \n",35);
					printf(" 0. Vers le bas \n");
					printf(" 1. Vers le haut \n");
					printf(" 2. Vers le droite  \n");
					printf(" 3. Vers le gauche \n");
					do { ok = saisie1int(&int_choix,0,3);if (ok != 1) printf("! ERREUR, saisissez bien \n"); } while (ok != 1);
					
					//selon la direction choisi on obtiens un sens
					switch (int_choix) {
						case 0 : int_d = 0; int_s = 0; break;
						case 1 : int_d = 0; int_s = 1; break;
						case 2 : int_d = 1; int_s = 0; break;
						case 3 : int_d = 1; int_s = 1; break;
					}
					
					// on pose    
					ok = pose(int_taillebat,int_taillebat,int_i,int_j,int_d,int_s,int_n,int_m,t1); 
					if (ok == 0) printf("ERREUR, veuillez recommencer\n");
					
				} while (ok != 1); // si on peut pas poser, tout recommencer
				
				affichage(0,int_n,int_m,t1); // afficher tableau juste après avoir poser
				int_nb--; // on a poser un bateaux
			} while (int_nb != 0);
        }
    } // boucle for int_k++
    
    clrscr();
    /* AFFICHAGE FINAL */
    printf("///// VOICI VOTRE GRILLE PERSO : \n");
    affichage(1,int_n,int_m,t1);
    printf("Etes vous satisfait ou voulez vous resaisir ? \n");
	printf("(0 : SATISFAIT)               (1 : RECOMMENCER)");
	saisie1int(&int_boolencore,0,1);
}

}
 
void saisieGrillealea(int int_n, int int_m, BATEAU t1[int_n][int_m],int int_nb_porteavion, int int_nb_croiseur, int int_nb_sousmarin, int int_nb_torpilleur){
    int int_nb; // nombre de bateaux a poser
    int int_i,int_j; // coordonnés 
    int int_d,int_s; // direction, sens
    int ok; // booléen
    int int_taillebat; // taille du bateaux
    int int_choix;
    int int_combien_essai; // nombre int_d'essai effectué
    int reset; // booléen, lorsque qu'il vaut 1 on recommence

do { 
	reset = 0;
/* initiatialisation 0 de la grille  */
	ini0(int_n,int_m,t1);
  
    // pour tout les type de bateaux
    for (int int_k=0; int_k<4;int_k++){
        
       // selon le bateau
        switch (int_k) {
            case 0 : int_nb = int_nb_porteavion; int_taillebat = 6; break;
            case 1 : int_nb = int_nb_croiseur; int_taillebat = 4;  break;
            case 2 : int_nb = int_nb_sousmarin; int_taillebat = 3;  break;
            case 3 : int_nb = int_nb_torpilleur; int_taillebat = 2;  break;
        }
   
        
/*** RENTREE DES BATEAUX ***/       
	if (int_nb != 0) { 

			do {
			int_combien_essai = 0; // pour chaque navire on a va commencer à compter le nombre int_d'essai de posage
				do {
					
					// saisie aléatoire des coordonnées de la tête
					do {
						ok = 1;
						int_i = randomval(0,int_n-1); 
						int_j = randomval(0,int_m-1); 
						if (t1[int_i][int_j].bip == 1) ok = 0; // si on ne peut pas  choisir cette tête
						
					} while ((int_m-1 < int_j) || (int_n-1 < int_i) || (ok != 1));// recommencer
					
					// saisie aléatoire de la direction
						int_choix = randomval(0,3);
					
					// selon la direction choisie
						switch (int_choix) {
							case 0 : int_d = 0; int_s = 0; break;
							case 1 : int_d = 0; int_s = 1; break;
							case 2 : int_d = 1; int_s = 0; break;
							case 3 : int_d = 1; int_s = 1; break;
						} 
					
					// pose		
					ok = pose(int_taillebat,int_taillebat,int_i,int_j,int_d,int_s,int_n,int_m,t1);
					
					// +1 essai effectué
					int_combien_essai++;
					 
				} while ((ok != 1) && (int_combien_essai < 25)); // changer de tete, si on ne peut pas poser et que on a fait moins de 25 essai
					
				// si on a fait + de 25 essaies, alors il y a un problème de place dans la grille, donc on va réinitialiser la grille et tout recommencer	
				if (int_combien_essai >= 25){ reset = 1;printf("*");}       
			   
				int_nb--;
			} while (int_nb != 0); 
	}
	} // boucle for int_k++
} while (reset == 1);
    
}    

int chenille(int int_i, int int_j, int int_n, int int_m, BATEAU t[int_n][int_m]) {
    int int_l;
    int int_cb1 = 0,int_cb2 = 0; // nombre de touché trouvé (horizontal, vertical
    int total = 0;
    
    // si la case n'est pas vide alors on peut compter le nombre de touche aligné
    if (t[int_i][int_j].val != -1) {
     /* HONRIZONTAL */
            int_l = 1;
            do {
                printf(">[%d][%d] = %d \n",int_i,int_j+int_l,t[int_i][int_j+int_l].touche);
                
                // si la case contient un bateau touché alors : cb++
                if ((t[int_i][int_j+int_l].val != -1) && (t[int_i][int_j+int_l].touche == t[int_i][int_j].touche)) int_cb1++;
                
                if (t[int_i][int_j+int_l].val != -1 ) int_l++; 
                //if (int_j+int_l > int_m-1) break;
            } while ((t[int_i][int_j+int_l].touche == t[int_i][int_j].touche) && (t[int_i][int_j+int_l].val != -1 )); 
            
            int_l = -1;
            do {
                printf("<[%d][%d] = %d \n",int_i,int_j+int_l,t[int_i][int_j+int_l].touche);
                
                // si la case contient un bateau touché alors : cb++
                if ((t[int_i][int_j+int_l].val != -1) && (t[int_i][int_j+int_l].touche == t[int_i][int_j].touche)) int_cb1++;
                
                if (t[int_i][int_j+int_l].val != -1 ) int_l--;
               // if (int_j+int_l < 0) break;
            } while ((t[int_i][int_j+int_l].touche == t[int_i][int_j].touche) && (t[int_i][int_j+int_l].val != -1 )); 
            
    /* VERTICAL */     
            int_l = 1;
            do {
                printf(">[%d][%d] = %d \n",int_i+int_l,int_j,t[int_i+int_l][int_j].touche);
                // si la case contient un bateau touché alors : cb++
                if ((t[int_i+int_l][int_j].val != -1) && (t[int_i+int_l][int_j].touche == t[int_i][int_j].touche)) int_cb2++;
                
                
                if (t[int_i+int_l][int_j].val != -1 ) int_l++;
               // if (int_i+int_l > n-1) break;
            } while ((t[int_i+int_l][int_j].touche == t[int_i][int_j].touche) && (t[int_i+int_i][int_j].val != -1 )); 
            
            int_l = -1;
            do {
                printf("<[%d][%d] = %d \n",int_i+int_l,int_j,t[int_i+int_l][int_j].touche);
                // si la case contient un bateau touché alors : cb++
                if ((t[int_i+int_l][int_j].val != -1)&&(t[int_i+int_l][int_j].touche == t[int_i][int_j].touche)) int_cb2++;
                
                if (t[int_i+int_l][int_j].val != -1 ) int_l--;
               // if (int_i+int_l < 0) break;
            } while ((t[int_i+int_l][int_j].touche == t[int_i][int_j].touche) && (t[int_i+int_j][int_j].val != -1 )); 

     
    }  
    
    
    if ((int_cb1 != 0) || (int_cb2 != 0)) {
      
        if (int_cb1 > int_cb2) total = int_cb1+1; else total = int_cb2+1;} // le total vaut le nombre de touché aligné +1 (+ la case case central)
         
    return total;
    
}

void dead(int int_i, int int_j, int int_n, int int_m, BATEAU t[int_n][int_m]) {
    int int_l;
    int ok;
    
    if (t[int_i][int_j].val != -1) {
            t[int_i][int_j].mort = 1;
            int_l = 1;
            do {
                printf("[%d][%d] = %d \n",int_i,int_j+int_l,t[int_i][int_j+int_l].touche);
                if ((t[int_i][int_j+int_l].val != -1) && (t[int_i][int_j+int_l].touche == t[int_i][int_j].touche)) t[int_i][int_j+int_l].mort = 1;
                
                int_l++;
            } while ((t[int_i][int_j+int_l].touche == t[int_i][int_j].touche)&& (t[int_i][int_j+int_l].val != -1 )); 
            
            int_l = -1;
            do {
                printf("[%d][%d] = %d \n",int_i,int_j+int_l,t[int_i][int_j+int_l].touche);
                if ((t[int_i][int_j+int_l].val != -1) && (t[int_i][int_j+int_l].touche == t[int_i][int_j].touche)) t[int_i][int_j+int_l].mort = 1;
                
                int_l--;
            } while ((t[int_i][int_j+int_l].touche == t[int_i][int_j].touche)&& (t[int_i][int_j+int_l].val != -1 )); 
            
            
            int_l = 1;
            do {
                printf("[%d][%d] = %d \n",int_i+int_l,int_j,t[int_i+int_l][int_j].touche);
                if ((t[int_i+int_l][int_j].val != -1) &&(t[int_i+int_l][int_j].touche == t[int_i][int_j].touche)) t[int_i+int_l][int_j].mort = 1;
                
                int_l++;
            } while ((t[int_i+int_l][int_j].touche == t[int_i][int_j].touche)&& (t[int_i+int_j][int_j].val != -1 )); 
            
            int_l = -1;
            do {
                printf("[%d][%d] = %d \n",int_i+int_l,int_j,t[int_i+int_l][int_j].touche);
                if ((t[int_i+int_l][int_j].val != -1) &&(t[int_i+int_l][int_j].touche == t[int_i][int_j].touche)) t[int_i+int_l][int_j].mort = 1;
                
                int_l--;
            } while (( t[int_i+int_l][int_j].touche == t[int_i][int_j].touche )&& (t[int_i+int_j][int_j].val != -1 )); 

     
    }  
    
printf("**dead ");
}

int yfotuer(int int_i, int int_j, int int_n, int int_m, BATEAU t[int_n][int_m]) {
    int tuer = 0; // booléen qui vaut 1 si le bateaux est coulé
    int int_nbtouche; // nombre de case touché 
    
    // si il n'est pas déjà mort
    if (t[int_i][int_j].mort != 1) {
        
        int_nbtouche = chenille(int_i,int_j,int_n,int_m,t);
        
        // si le nombre de case touché = le nombre de case du bateau (caleur du bateau) alors coulé
        if (int_nbtouche == t[int_i][int_j].val) tuer = 1;
    }
    return tuer;
}

int char2int(char char_x) {
	
int int_val = -1;	
	if ((char_x >= 65) && ( char_x <= 90)) { int_val = (char_x - 65);}
	else if ((char_x >= 97) && (char_x <= 122)) { int_val = (char_x - 97);}
	
	return int_val;
}


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




void Menuparam(int *int_nb_porteavion, int *int_nb_croiseur, int *int_nb_sousmarin, int *int_nb_torpilleur,int *a2, int *b2, int *c2, int *d2, int *int_taille) {
	
    int taillemin = *int_taille; // taile minimum de la grille 
    int ok;  // booléen
    int int_choix;
    
    while (1) {
		clrscr();
		printf("\n/ *** PARAMETRES *** /////////////////////////////\n");
		printf("//////////////////////////////////////////////////\n\n");
		printf(" 0. - Retour au menu -  \n");
		printf("\n 1. NOMBRE PORTE-AVIONS     (6 cases) : %d \n",*int_nb_porteavion);
		printf(" 2. NOMBRE DE CROISEURS     (4 cases) : %d \n",*int_nb_croiseur);
		printf(" 3. NOMBRE DE SOUS-MARINS   (3 cases) : %d \n",*int_nb_sousmarin);
		printf(" 4. NOMBRE DE TORPILLEURS   (2 cases) : %d \n",*int_nb_torpilleur);
		
		// impose une int_taille minimum
		if (taillemin > *int_taille) *int_taille = taillemin;
		printf(" 5. TAILLE DE LA GRILLE       (N x N) : %d \n",*int_taille);
		
        printf("\n Que voulez voulez vous modifiez ?  \n");
			printf(" : ");
			do { ok = saisie1int(&int_choix,0,5);if (ok != 1) printf("/!%c ERREUR \n",92); } while (ok != 1);
			switch (int_choix) {
				case 1 : printf(" * Nouvelle valeur  : ");do { ok = saisie1int(int_nb_porteavion,0,100);if (ok != 1) printf("/!%c ERREUR \n",92); } while (ok != 1); break;
				case 2 : printf(" * Nouvelle valeur  : ");do { ok = saisie1int(int_nb_croiseur,0,100);if (ok != 1) printf("/!%c ERREUR \n",92); } while (ok != 1);break;
				case 3 : printf(" * Nouvelle valeur  : ");do { ok = saisie1int(int_nb_sousmarin,0,100);if (ok != 1) printf("/!%c ERREUR \n",92); } while (ok != 1); break;
				case 4 : printf(" * Nouvelle valeur  : ");do { ok = saisie1int(int_nb_torpilleur,0,100);if (ok != 1) printf("/!%c ERREUR \n",92); } while (ok != 1); break;
				case 5 : printf(" * N = ");do { ok = saisie1int(int_taille,0,100);if (ok != 1) printf("/!%c ERREUR \n",92); if (*int_taille * *int_taille < taillemin * taillemin ) printf("/!%c ERREUR, cette taille de grille est trop petite pour tous ses navires.. recommencer \n",92);  } while ((ok != 1) || (*int_taille * *int_taille < taillemin * taillemin )); break;

			}
		// int_choix vaut 0 alors quitter la boucle	
		if (int_choix == 0)	break;			
	
		// Calcul de la int_taille minimum
		taillemin = sqrt((7* *int_nb_porteavion + 5* *int_nb_croiseur + 4* *int_nb_sousmarin + 3* *int_nb_torpilleur)*3)-1;
	}
	

		
}

int saisie1int(int *a, int int_x, int int_y) {
    int ok = 1;
    int int_temp;
    scanf("%d",&int_temp);viderBuffer();
    
    if ((int_temp < int_x) || (int_temp > int_y)) {ok = 0;} else {*a = int_temp;}
    
    return ok;
}

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

float pourcentage(int n, int m, BATEAU t[n][m]) {
int i,j;float p; //Le but de cette fonction le pourcentage de réussite de tir de chaque joueurs
float c=0;
float r=0;
for(i=0;i<n;i++){
    for (j=0;j<m;j++) {
        if (t[i][j].touche==1) {
            if (t[i][j].val != -1) r += 1;
            else c+= 1;
        
        }        
    }
}
p =((r*100)/(c+r)); // pourcentage de réussite de tir pour J1 (nb de tir réussis)/(nb de tir réussis+ratés=nb total de tir du joueurs)
return p;
}

int main()
{
    
/* VARIABLE RELATIF AU JOUEUR */   
    int int_joueur; // entier du joueur
    float float_tirsreussi;
    int int_tour;

/* CHOIX MENU */    
    int int_choix_menu; // choix1 sur le menu
    int int_choix_modeia; // choix du mode humain ou IA
    int int_choix_levelia = 1; // choix du niveau de l'ia
    int int_choix_saisieg; // choix saisie aléatoire ou manuelle
    
/* BOOLEEN */
	int ok;
	int quit; // pour quitter
	
	int int_bool_toucher;
    int int_bool_couler; // booléen actif quand c'est coulé
    
 	int int_bool_gagnant;
	int int_boolencore = 1; 
	
/* "CERVEAU de l'IA" */
    int i0 = 0, j0 = 0; // coordonnée du touché précedent
    int int_cas = 0;
    int bool_touchefind = 0; // actif lorsque l'IA a trouvé une case
    
/* PARAMETRES PAR DEFAUT */
    int int_nb_porteavionsj1,int_nb_croiseursj1,int_nb_sousmarinsj1,int_nb_torpilleursj1 ,int_nb_porteavionsj2,int_nb_croiseursj2,int_nb_sousmarinsj2,int_nb_torpilleursj2;
	int_nb_porteavionsj1 = 1; int_nb_croiseursj1 = 2; int_nb_sousmarinsj1 = 3; int_nb_torpilleursj1 = 4;
    int_nb_porteavionsj2 = int_nb_porteavionsj1;int_nb_croiseursj2 = int_nb_croiseursj1;int_nb_sousmarinsj2 = int_nb_sousmarinsj1;int_nb_torpilleursj2 = int_nb_torpilleursj1;
    int int_SommeTOTALj1,int_SommeTOTALj2; 
    
    int taille = 10;
    int int_n = taille;// hauteur de la grille
    int int_m = taille;// lonngueur de la grille
    srand(time(NULL)); 
/* FICHIER SAUVEGARDE */
    FILE *fic_j1 = fopen("sauvegardej1.txt","r"); // sauvegarde du joueur 1
 	FILE *fic_j2 = fopen("sauvegardej2.txt","r"); // sauvegarde du joueur 2
 	

while (int_boolencore == 1) {
	    
	    
		/*printf("\n");
        printf(" ____        _        _ _ _                               _      \n");
		printf("| __ )  __ _| |_ __ _(_) | | ___   _ __   __ ___   ____ _| | ___ \n");
		printf("|  _ \\ / _` | __/ _` | | | |/ _ \\ | '_ \\ / _` \\ \\ / / _` | |/ _ \\\n");
		printf("| |_) | (_| | || (_| | | | |  __/ | | | | (_| |\\ V / (_| | |  __/\n");
		printf("|____/ \\__,_|\\__\\__,_|_|_|_|\\___| |_| |_|\\__,_| \\_/ \\__,_|_|\\___|\n\n");*/
/*** MENU PRINCIPALE ***/
        //clrscr();
        printf("//////////////////////////////////////////////////\n");
        printf("///////// * BATAILLE NAVALE * ////////////////////\n");
        printf("//////////////////////////////////////////////////\n");
        printf("/////// 1 : JOUER                     ////////////\n");
    if (fic_j2 != NULL) {    printf("////// 2 : CHARGER PARTIE PRECEDENTE  ////////////\n");}
        printf("////// ----                          /////////////\n");
        printf("///// 3 : MODIFIER PARAMETRES       //////////////\n");
        printf("//////////////////////////////////////////////////\n");
        printf("/// > ");	do { ok = saisie1int(&int_choix_menu,1,3);if ((fic_j1 == NULL) && (int_choix_menu == 2)) ok = 0;  if (ok != 1) printf("/! ERREUR \n"); } while (ok != 1);
	
/*** 3 : MODIFIER PARAMETRES ***/				
					if (int_choix_menu == 3) {
    						Menuparam(&int_nb_porteavionsj1,&int_nb_croiseursj1,&int_nb_sousmarinsj1,&int_nb_torpilleursj1 ,&int_nb_porteavionsj2,&int_nb_croiseursj2,&int_nb_sousmarinsj2,&int_nb_torpilleursj2,&taille);
							int_nb_porteavionsj2 = int_nb_porteavionsj1;int_nb_croiseursj2 = int_nb_croiseursj1;int_nb_sousmarinsj2 = int_nb_sousmarinsj1;int_nb_torpilleursj2 = int_nb_torpilleursj1;//
							int_n = taille;
    					    int_m = taille;
    					    
					}
BATEAU grille1[int_n][int_m]; // création grille du joueur 1
BATEAU grille2[int_n][int_m]; // création grille du joueur 2
					
/*** 2 : CHARGER PARAMETRES ***/					
					if (int_choix_menu == 2) { 
    					loadGrille(fic_j1,int_n,int_m,grille1,&int_nb_porteavionsj1,&int_nb_croiseursj1,&int_nb_sousmarinsj1,&int_nb_torpilleursj1,&int_tour,&int_choix_modeia); // chargement du fichier du joueur 1
    					loadGrille(fic_j2,int_n,int_m,grille2,&int_nb_porteavionsj2,&int_nb_croiseursj2,&int_nb_sousmarinsj2,&int_nb_torpilleursj2,&int_tour,&int_choix_modeia); // chargement du fichier du joueur 2
  
					}
					
/*** 1 : JOUER ***/
if ((int_choix_menu == 1) || (int_choix_menu == 2)) {
	if (int_choix_menu != 2) {	// si on n'a pas charger de partie, alors commencer nouvelle partie
		clrscr();
		int_tour = 0; // on commence int_tour vaut 0
		printf("\n/////////  -- MODE DE JEU ----     /////////////\n");
		printf("//////// 1 : MODE HUMAIN VS HUMAIN  //////////////\n");
		printf("/////// 2 : MODE HUMAIN VS IA      ///////////////\n");
		
        printf("////// > ");
		//int_choix_modeia = 2;
		// saisie
		do { ok = saisie1int(&int_choix_modeia,1,2);if (ok != 1) printf("/! ERREUR \n"); } while (ok != 1);
		
	/* CHOIX NIVEAU IA */  
		if (int_choix_modeia == 2) {

		printf("\n//////// - NIVEAU DU IA ---- ////////////////////\n");	
		printf("/////// 1 : NIVEAU 1   //////////////////////////\n");
		printf("////// 2 : NIVEAU 2   ///////////////////////////\n");
		printf("/// > ");
		do { ok = saisie1int(&int_choix_levelia,1,2);if (ok != 1) printf("/! ERREUR \n"); } while (ok != 1);
		}
	
	/* DEPOT DES BATEAUX */

		for (int_joueur = 1; int_joueur <= 2; int_joueur++ ) {
		clrscr();
	
	if ((int_choix_modeia != 2) || (int_joueur != 2)) {
		printf("\n///////// # CREATION GRILLE #  ///////////////////\n"); 
		printf("                              ");if (int_joueur == 1) couleur_char(ROUGE); if (int_joueur == 2) {couleur_char(CYAN);}printf("////// JOUEUR %d ////\n",int_joueur);couleur_char(BLANC);
		printf("/////// 1 : SAISIE ALEATOIRE /////////////////////\n");
		printf("////// 2 : SAISIE MANUELLE  //////////////////////\n");
		printf("///// > ");
	}
		// si le joueur est IA
		if ((int_choix_modeia == 2) && (int_joueur == 2)) {
		    int_choix_saisieg = 1;} // saisie aléatoire direct
		    
		// sinon demander mode de saisie
		else {do { ok = saisie1int(&int_choix_saisieg,1,2);if (ok != 1) printf("/! ERREUR \n"); } while (ok != 1);}
		
		/* 2 : saisie manuelle */
		if (int_choix_saisieg == 2) { switch(int_joueur) { case 1 : saisieGrille(int_joueur,int_n,int_m,grille1,int_nb_porteavionsj1,int_nb_croiseursj1,int_nb_sousmarinsj1,int_nb_torpilleursj1);break;case 2 : saisieGrille(int_joueur,int_n,int_m,grille2,int_nb_porteavionsj2,int_nb_croiseursj2,int_nb_sousmarinsj2,int_nb_torpilleursj2);break;}}
		/* 1 : saisie aléatoire */
		else {switch(int_joueur) { case 1 : saisieGrillealea(int_n,int_m,grille1,int_nb_porteavionsj1,int_nb_croiseursj1,int_nb_sousmarinsj1,int_nb_torpilleursj1);break;case 2 : saisieGrillealea(int_n,int_m,grille2,int_nb_porteavionsj2,int_nb_croiseursj2,int_nb_sousmarinsj2,int_nb_torpilleursj2);break;}};
		
		}// fin depot
		
}	
    clrscr();
	if (int_choix_menu == 1 ) printf("\n La partie va commencer êtes vous pret ?          \n ");
	else printf("\n La partie va reprendre la où vous avez quitter la dernière fois, êtes vous pret ?  \n ");
	printf("\n\n                               (1 : C'EST PARTI !)\n ");do { ok = saisie1int(&quit,1,1);if (ok != 1) printf("/! ERREUR \n"); } while (ok != 1);


int_bool_gagnant = 0;
/*** DEBUT DE LA GUERRE ***/
		/* Tir chacun leur int_tour */
			do {
			    // joueur
				int_joueur = 1 + (int_tour % 2);
				
				do {
				clrscr();
                
				printf("//////////////////////////////////////////////////\n");
		        printf("                              ");if (int_joueur == 1) couleur_char(ROUGE); if (int_joueur == 2) {couleur_char(CYAN);}printf("////// JOUEUR %d ////\n",int_joueur);couleur_char(BLANC);

// AFFICHAGE CI DESSOUS SEULEMENT POUR LES JOUEURS HUMAIN		        
if (((int_joueur != 2) && (int_choix_modeia == 2))||(int_choix_modeia == 1)) {
	            printf("///// VOTRE GRILLE PERSO : \n"); // affichage votre grille
				switch (int_joueur) { case 1 : affichage(1,int_n,int_m,grille1);/*affichage(1,n,int_m,grille2);*/ break; case 2 :affichage(1,int_n,int_m,grille2); break;} 
				
				printf("\n///// GRILLE DE L'ADVERSAIRE : \n"); // affiche grille de l'autre joueur	
				switch (int_joueur) { case 1 : affichage2(int_n,int_m,grille2); break; case 2 :affichage2(int_n,int_m,grille1);break;}
				// calcul pourcentage de tir reussi
				switch (int_joueur) { case 1 : float_tirsreussi = pourcentage(int_n,int_m,grille2); break; case 2 : float_tirsreussi = pourcentage(int_n,int_m,grille1); break;}
	    /* Saisie des coordonnées de tir */
	            printf("\n");
	            if (float_tirsreussi > 1) printf("//// (%3.f %c de TIRS REUSSIS )\n",float_tirsreussi,37);
	            printf("/// ");if (int_joueur == 1) couleur_char(ROUGE); if (int_joueur == 2) {couleur_char(CYAN);}printf("JOUEUR %d",int_joueur);couleur_char(BLANC);	printf(" ///\n");
				printf("                    # COORDONNEES DE TIR : \n");
	}			
				// Saisie du TIR
				int_bool_toucher = SaisieTir(int_choix_modeia,int_choix_levelia,int_joueur,&int_bool_couler,int_n,int_m,grille1,grille2,&int_nb_porteavionsj1,&int_nb_croiseursj1,&int_nb_sousmarinsj1,&int_nb_torpilleursj1,&int_nb_porteavionsj2,&int_nb_croiseursj2,&int_nb_sousmarinsj2,&int_nb_torpilleursj2,&i0,&j0,&int_cas,&bool_touchefind); 
		
	
		    
		/** PAUSE : **/
			clrscr();
			if ((int_choix_modeia == 2) && (int_joueur==2)) {printf("\n               L'IA est entrain de jouer...           \n ");
				printf("\n\n   (0 : SUIVANT )\n ");do { ok = saisie1int(&quit,0,0);if (ok != 1) printf("/! ERREUR \n"); } while (ok != 1);	
		    
			}
		
				  {
				     clrscr();
				     printf("//////////////////////////////////////////////////\n");
		            printf("                              ");if (int_joueur == 1) couleur_char(ROUGE); if (int_joueur == 2) {couleur_char(CYAN);}printf("////// JOUEUR %d ////\n",int_joueur);couleur_char(BLANC);
				     printf("///// GRILLE DE L'ADVERSAIRE : \n");
				     switch (int_joueur) { case 1 : affichage2(int_n,int_m,grille2); break; case 2 :affichage2(int_n,int_m,grille1); break;}
				     
				     // si touché et coulé alors
				     couleur_char(JAUNE);
				     if ((int_bool_toucher == 1) && (int_bool_couler == 1)) printf("               #TOUCHE!#COULE!  \n");
				     // si juste touché
				     else if (int_bool_toucher == 1) printf(" #TOUCHE!  ( C'est encore à vous JOUEUR %d )\n",int_joueur);
				     // sinon c'est raté
				     else printf(" #RATE!           (C'est au tour du JOUEUR %d)\n",(int_joueur%2)+1);
				     couleur_char(BLANC);
		 
		/* Calcul du nombre de bateaux restant */    
				 int_SommeTOTALj1 = int_nb_porteavionsj1 + int_nb_croiseursj1 + int_nb_sousmarinsj1 + int_nb_torpilleursj1; 
				 int_SommeTOTALj2 = int_nb_porteavionsj2 + int_nb_croiseursj2 + int_nb_sousmarinsj2 + int_nb_torpilleursj2;
                 
					
                  }  
        /* Continuer ou quitter ? */      
                  printf("\n\n (0 : CONTINUE)                   (1 : QUIT)\n ");do { ok = saisie1int(&quit,0,1);if (ok != 1) printf("/! ERREUR \n"); } while (ok != 1); 
                  
                    // si oui alors sortir de la boucle
                    if (quit == 1) {break;}
				
				
				} while ((int_bool_toucher == 1) && (int_SommeTOTALj1 > 0) && (int_SommeTOTALj2 > 0)); // tant que le joueur touche, il continue de jouer. (aussi tant qu'il gagne pas)
		    
		    // si l'utilisateur voulait quitter : sortir
			if (quit == 1) {break;}
			int_tour++;
			
			} while ((int_tour < int_n*int_m) && (int_SommeTOTALj1 > 0) && (int_SommeTOTALj2 > 0)); // tant qu'il reste des bateaux et le nombre de int_tour est inf au nombre de case total : les joueur jouent chacun leur int_tour.
			
			
		/* Affichage du gagnant	lorsqu'un joueur n'a plus de bateaux */

			if ((int_SommeTOTALj1 == 0) || (int_SommeTOTALj2 == 0)) {
			    clrscr(); 
			    int_bool_gagnant = 1; // alors on a un gagnant
			    
			    printf("\n//////////////////////////////////////////////////\n");
			    if (int_joueur == 1) couleur_char(ROUGE); if (int_joueur == 2) {couleur_char(CYAN);}printf("       ////// JOUEUR %d GAGNE LA PARTIE //////\n",int_joueur);couleur_char(BLANC);
			
			// on supprime alors la sauvegarde la partie
			remove("sauvegardej1.txt");remove("sauvegardej2.txt");
			}
		
		/* Sauvegarde de la partie si l'utiliseur à quitter */
		if ((quit == 1) && (int_bool_gagnant == 0)) {	
			fic_j1 = fopen("sauvegardej1.txt","w");fic_j2 = fopen("sauvegardej2.txt","w");if (int_bool_toucher != 1) int_tour++;
			saveGrille(fic_j1,int_n,int_m,grille1,int_nb_porteavionsj1,int_nb_croiseursj1,int_nb_sousmarinsj1,int_nb_torpilleursj1,int_tour,int_choix_modeia);saveGrille(fic_j2,int_n,int_m,grille2,int_nb_porteavionsj2,int_nb_croiseursj2,int_nb_sousmarinsj2,int_nb_torpilleursj2,int_tour,int_choix_modeia);printf(" save...");
			int_boolencore = 0;
		}
	    
		} // boucle 1 : JOUER
		if ((quit != 1) && (int_choix_menu != 3)) {
		printf("\n\n (0 : QUITTER LE PROGRAMMME)    (1 : RETOURNER AU MENU)\n ");do { ok = saisie1int(&int_boolencore,0,1);if (ok != 1) printf("/! ERREUR \n"); } while (ok != 1);
		}
} // boucle return au menu
	fclose(fic_j1);
	fclose(fic_j2);
    return 0;
}










