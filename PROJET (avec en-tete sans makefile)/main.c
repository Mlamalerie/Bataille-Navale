#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include "affichage.h"
#include "ini0.h"

#include "pose.h"
#include "saisieGrillealeatoire.h" 
#include "saisieGrille.h" 

#include "saveload.h"
#include "utile.h"

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
       // clrscr();
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










