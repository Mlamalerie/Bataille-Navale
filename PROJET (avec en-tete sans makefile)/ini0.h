#ifndef __INITIA

#define __INITIA 

typedef struct BATEAU BATEAU; //
struct BATEAU
{
	int val;
	int touche;
	
	int mort;
	int bip;
	
};

void ini0(int n, int m, BATEAU tab0[n][m]); 


#endif