#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MAX_L_C 100000

using namespace std;

int main (){
	int lin,col;
	scanf("%i",&lin);
	scanf("%i",&col);
	while (lin!=0){
		int linhaAux[MAX_L_C];
		int linhaAux2[MAX_L_C+3];
            	for (int i=0; i<lin; i++){
			int linhaI[MAX_L_C];
			for (int j=0; j<col; j++)
				scanf("%i",&linhaI[j]);
			linhaAux2[col] = 0; 
			linhaAux2[col+1] = 0;
			for (int j=col-1;j>=0;j--)
				linhaAux2[j] = max(linhaAux2[j+2] + linhaI[j],linhaAux2[j+1]);
		linhaAux[i] = linhaAux2[0];
		}
		linhaAux2[lin] = 0;
		linhaAux2[lin+1] =0;
		for (int i=lin-1;i>=0;i--)
			linhaAux2[i] = max(linhaAux2[i+2] + linhaAux[i], linhaAux2[i+1]);
		printf("%i\n",linhaAux2[0]);
		scanf("%i",&lin);
		scanf("%i",&col);
	}
	return 0;
}
