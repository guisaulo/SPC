#include <iostream>
#include <cstdlib>
using namespace std;

int compare (const void *a, const void * b){
return (*(int*)a - *(int*)b);
}

class Grafo{
private:
int ** pesosTotais;
int tam_;
public:
Grafo();
Grafo(int tam);
Grafo& setPeso(int v1,int v2,int peso);
int getTam();
int getPesosTotais(int v1,int v2);
void imprimeSolucao();
};

Grafo::Grafo(){
pesosTotais = NULL;
tam_ = 0;
}

Grafo::Grafo(int tam){
tam_ = tam;
pesosTotais = new int * [tam];
for (int i=0;i<tam;i++){
pesosTotais[i] = new int [tam];
}

for (int i=0;i<tam;i++){
for (int j=0;j<tam;j++){
pesosTotais[i][j] = 0;
}
}
}


Grafo& Grafo::setPeso(int v1,int v2,int peso){
pesosTotais[v1][v2]= peso;
pesosTotais[v2][v1]= peso;
}

int Grafo::getPesosTotais(int v1,int v2){
return pesosTotais[v1][v2];
}
int Grafo::getTam(){
return tam_;
}

void Grafo::imprimeSolucao(){
int pesoTotal=-1,pesoAux=-1;
int solucao[3] = {1,2,3};
for (int i=0;i<tam_;i++){
for (int j=i+1;j<tam_;j++){
for (int k=j+1;k<tam_;k++){
pesoAux=pesosTotais[i][j] + pesosTotais[i][k] + pesosTotais[j][k];
if (pesoAux > pesoTotal){
solucao[0] = i+1;
solucao[1] = j+1;
solucao[2] = k+1;
pesoTotal = pesoAux;
}
}
}
}
qsort (solucao,3,sizeof(int),compare);
cout << solucao[0] << " " << solucao[1] << " " << solucao[2] << " " << "\n";
}

int main (){
int tam, nPesos, aresta1Aux,aresta2Aux,pesoAux;
ios_base::sync_with_stdio(false);
cin >> tam;
cin >> nPesos;
Grafo A(tam);
for (int i=0;i<nPesos;i++){
cin >> aresta1Aux;
cin >> aresta2Aux;
aresta1Aux--;
aresta2Aux--;
cin >> pesoAux;
A.setPeso(aresta1Aux,aresta2Aux,pesoAux);
}
A.imprimeSolucao();
return (0);
}
