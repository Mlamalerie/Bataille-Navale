#include "chenille.h" 

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