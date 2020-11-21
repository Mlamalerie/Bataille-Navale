#include "yfotuer.h" 

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
