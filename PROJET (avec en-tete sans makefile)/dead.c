#include "dead.h"

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