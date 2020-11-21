#include "ini0.h"

void ini0(int int_n, int int_m, BATEAU tab0[int_n][int_m]) {
    
    for (int i=0;i<int_n;i++){
        for (int j=0;j<int_m;j++){
            
        tab0[i][j].val = -1;
        tab0[i][j].touche = 0;
        tab0[i][j].bip = 0;
        tab0[i][j].mort = 0;//
        }
    }
    
    
}