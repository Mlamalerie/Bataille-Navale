#include "saisieGrillealeatoire.h" 

int randomval (int x, int y) {
	return ((float)(rand() / (float)RAND_MAX)*(y-x+1)) + x;
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