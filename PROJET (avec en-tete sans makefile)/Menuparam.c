#include "Menuparam.h" 

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