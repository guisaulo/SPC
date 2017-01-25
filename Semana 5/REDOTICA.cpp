#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;
int compara (const void *a, const void * b){
return (*(int*)a - *(int*)b);
}

using namespace std;
class Grafo{
private:
int ** pesos;
bool * encoberto; 
list< vector<int> > ramos;
int tam;
public:
Grafo();
Grafo(int tam);
Grafo& setPeso(int v1,int v2,int peso);
Grafo& agm();
int getTam();
int getPesoAresta(int v1,int v2);
void imprimeSolucao();
int * menorArestaSegura();
};

Grafo::Grafo(){
pesos = NULL;
encoberto = NULL;
tam = 0;
}

Grafo::Grafo(int tam){
this->tam = tam;
pesos = new int * [tam]; 
encoberto = new bool [tam];
for (int i=0;i<tam;i++){
encoberto[i] = false;
pesos[i] = new int [tam];
for (int j=0;j<tam;j++){
pesos[i][j] = -1;
}
}
}


Grafo& Grafo::setPeso(int v1,int v2,int peso){
pesos[v1][v2]= peso;
pesos[v2][v1]= peso;
}

int * Grafo::menorArestaSegura(){
	int menorAresta = 101;
	int * aux = new int [2];
	aux[0]=-1;
	aux[1]=-1;
	for (int i=0;i<tam;i++){
		if (!encoberto[i]);
		else{
		for (int j=0;j<tam;j++){
			if (encoberto[j] || i==j);
			else{
				if (pesos[i][j]!=-1 && pesos[i][j]<=menorAresta){
					menorAresta=pesos[i][j];
aux[0]=i;
aux[1]=j;
}
					}
				}
			}
		}
return aux;
}

int Grafo::getPesoAresta(int v1,int v2){
return pesos[v1][v2];
}
int Grafo::getTam(){
return tam;
}

void Grafo::imprimeSolucao(){
agm();
list < vector<int> >::iterator listI;
vector<int>::iterator vecI;
for (listI = ramos.begin(); listI != ramos.end(); listI++){
for (vecI = listI->begin(); vecI!= listI->end(); vecI++){
cout << (*vecI)+1 << " ";
}
cout << "\n";
}
}

Grafo& Grafo::agm(){
	int i=0;
	while(!encoberto[i]){
		encoberto[0]=true;	
		int * aux = new int [2];
		aux = menorArestaSegura();
		if (aux[0]!=-1){
			encoberto[aux[1]]=true;
			vector<int> ramoAux;
			qsort(aux,2,sizeof(int),compara);
			ramoAux.push_back(aux[0]);
			ramoAux.push_back(aux[1]);
			ramos.push_back(ramoAux);
		}
		for (int j=0;j<tam;j++){
			if (!encoberto[j]){
				i = j;
				break;
				}	
			}
	}
}

int main(){
	int tam,nArestas,testeAtual=1;
	bool primeiraLinha = true;
	while (true){
		cin >> tam;
		cin >> nArestas;
		if (tam==0)
			break;
		else{
			if (!primeiraLinha)
			printf("\n");
			primeiraLinha=false;
			Grafo A(tam);
			for (int i=0;i<nArestas;i++){
				int pesoAux,v1,v2;
				cin >> v1;
				cin >> v2;
				v1--;
				v2--;
				cin >> pesoAux;
				A.setPeso(v1,v2,pesoAux);
			}
			cout << "Teste " << testeAtual << "\n";
			testeAtual++;
			A.imprimeSolucao();
		}
	}
	return 0;
}
