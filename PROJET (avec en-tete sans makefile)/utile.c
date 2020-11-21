#include "utile.h" 

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

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}


void clrscr(){
	for (int z=0; z < 4; z++) {
			system ("clear");
			}
    
}

int saisie1int(int *a, int int_x, int int_y) {
    int ok = 1;
    int int_temp;
    scanf("%d",&int_temp);viderBuffer();
    
    if ((int_temp < int_x) || (int_temp > int_y)) {ok = 0;} else {*a = int_temp;}
    
    return ok;
}

int char2int(char char_x) {
	
int int_val = -1;	
	if ((char_x >= 65) && ( char_x <= 90)) { int_val = (char_x - 65);}
	else if ((char_x >= 97) && (char_x <= 122)) { int_val = (char_x - 97);}
	
	return int_val;
}
