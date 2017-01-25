#include <iostream>
#include <string> 
#include <algorithm>
#include <iterator>
#include <vector>

#define POSFIB 0

using namespace std;

unsigned long long int * Calcfib46(){
   unsigned long long int * fib48aux= new unsigned long long int [48];
   fib48aux[0]=0;
   fib48aux[1]=1;
for (int i=2;i<48;i++){
      fib48aux[i] = fib48aux[i-1] + fib48aux[i-2];
   }
   return fib48aux;
}

void ordenaPorLinhas(vector<vector<unsigned long long int>>& matriz, int col) {    
    sort(matriz.begin(),
              matriz.end(),
              [col](const vector<unsigned long long int>& a, const vector<unsigned long long int>& b) {
                  return a[col] < b[col];
              });
}

string removeLixo(string texto){
   string textoAux,textoFinal;
   remove_copy_if(texto.begin(), texto.end(), back_inserter(textoAux), ptr_fun<int, int>(&ispunct));
   remove_copy_if(textoAux.begin(), textoAux.end(), back_inserter(textoFinal), ptr_fun<int, int>(&isspace));
   return textoFinal;
}

void descriptografa(string texto,vector < vector<unsigned long long int> >nFibAux, unsigned long long int seqFib[]){
   int posFib=2,espacos=0;
   string txtDescriptAux(texto.size() * 2, ',');
   string txtDescrtpt;
   auto vecI = nFibAux.begin();
   for (vecI; vecI != nFibAux.end();){
      if ((*vecI)[0]==seqFib[posFib]){
	 txtDescriptAux[posFib-2]=texto[(*vecI)[1]];
         vecI++;
      }
      else{
	 txtDescriptAux[posFib-2] = ' ';
      }
         posFib++;
   }
   remove_copy_if(txtDescriptAux.begin(), txtDescriptAux.end(), back_inserter(txtDescrtpt), ptr_fun<int, int>(&ispunct));
   cout << txtDescrtpt <<  "\n";
}

int main(){
   ios_base::sync_with_stdio(false);
   unsigned long long int * fib46=Calcfib46();
   int nInstancias;
   cin >> nInstancias;
   for (int i=0;i<nInstancias;i++){
      int seqFib;
      cin >> seqFib;
      vector< vector<unsigned long long int> > nFibAux;
      for (int j=0;j<seqFib;j++){
         vector<unsigned long long int> nFibAuxJ;
         unsigned long long int nFibAux1;
         cin >> nFibAux1;
         nFibAuxJ.push_back(nFibAux1);
         nFibAuxJ.push_back(j);
         nFibAux.push_back(nFibAuxJ);
      }
      string texto;
      cin.ignore();
      getline (cin,texto);
      string textoFinal = removeLixo(texto);
      string textoDescrip;
      vector < vector<unsigned long long int> >::iterator vecI;
      ordenaPorLinhas(nFibAux,POSFIB);
      descriptografa(textoFinal,nFibAux,fib46);
   }
}
