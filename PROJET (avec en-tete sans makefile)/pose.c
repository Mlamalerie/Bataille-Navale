#include "pose.h"

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