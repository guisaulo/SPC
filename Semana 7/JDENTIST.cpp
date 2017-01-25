#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

#define TEMPO_TERM 1
using namespace std;

void ordenaPorLinhas(vector<vector<int>>& matriz, int col) {    
    sort(matriz.begin(),
              matriz.end(),
              [col](const vector<int>& a, const vector<int>& b) {
                  return a[col] < b[col];
              });
}

int main(){
   int nConsultas;
   vector< vector<int> > consultas;
   int ultimaConsRealziada=0,consRealziadas=0;
   scanf("%i",&nConsultas);
      for (int i=0;i<nConsultas;i++){
         vector<int> consultaAux;
         int tempIni,tempFim;
	 scanf("%i",&tempIni);
	 scanf("%i",&tempFim);
         consultaAux.push_back(tempIni);
	 consultaAux.push_back(tempFim);
	 consultas.push_back(consultaAux);
      }
	 ordenaPorLinhas(consultas,TEMPO_TERM);
	 vector < vector<int> >::iterator vecI;
	 for (vecI = consultas.begin(); vecI!= consultas.end(); vecI++){
	    if (ultimaConsRealziada > (*vecI)[0]);
	    else{
	       ultimaConsRealziada = (*vecI)[1];
	       consRealziadas++;
	    }
      }
      printf("%i\n",consRealziadas);
}
