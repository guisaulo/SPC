#include <string>
#include <iostream>
#include <list>

using namespace std;

int * computarPref(string pref){
   int aux = -1;
   int * valoresPref = new int [pref.size()];
   valoresPref[0] = -1;
   for (int i=1; i < pref.size(); i++){
      while (aux > -1 && pref[aux+1] != pref[i])
	 aux = valoresPref[aux];
      if (pref[i] == pref[aux+1])
	 aux++;
      valoresPref[i] = aux;
   }
   return valoresPref;
}

list<int> matchs(string pref, string texto){
   list<int> posOcorrencias;
   int i=0,j=0,k=0,nil=0;
   int * valoresPref=computarPref(pref);
      while (texto.size() - k >= pref.size()){
	 while (j < pref.size() && texto[i]==pref[j]){
	    i++;
            j++;
      }
      if (j > pref.size()-1)
	 posOcorrencias.push_back(k);
      if (j!=0){
         if (valoresPref[j-1] > -1){
            k = i - (valoresPref[j-1]+1);}
         else{
            if (i==k)
               i++;
            k=i;
         }
      }
      else{ 
         if (i==k)
            i++;
         k=i;
      }
      if (j>0)
         j=valoresPref[j-1]+1;
   }
   return posOcorrencias;
}
int main(){
   ios_base::sync_with_stdio(false);
   int tamString;
   while (cin >> tamString){
      int atualPos=0;
      string padrao,texto;
      cin >> padrao;
      cin >> texto;
      list<int> posOcorrencias;
      posOcorrencias = matchs(padrao, texto);
      list <int>::iterator listI;
      for (listI = posOcorrencias.begin(); listI!= 		 posOcorrencias.end(); listI++){
	 cout << (*listI);
	 cout << endl;
      }
      cout << endl;
   }
}
