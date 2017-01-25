#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#define PRETO 2
#define CINZA 1
#define BRANCO 0

using namespace std;
int compare (const void *a, const void * b){
return (*(int*)a - *(int*)b);
}

class Grafo{
private:
int ** pesos;
int * cor;
int * menDistInicio; 
int tam;
int posInicial;
public:
Grafo& calculaDist();
Grafo();
Grafo(int tam,int posInicial);
Grafo& setPeso(int v1,int v2,int peso);
int getTam();
int getPesoAresta(int v1,int v2);

void imprimeSolucao(int maxPedagios);
};

Grafo::Grafo(){
pesos = NULL;
cor = NULL;
menDistInicio = NULL;
tam = 0;
}

Grafo::Grafo(int tam,int posInicial){
this->tam = tam;
this->posInicial= posInicial;
pesos = new int * [tam];
cor = new int [tam];
menDistInicio = new int [tam];
for (int i=0;i<tam;i++){
cor[i] = BRANCO;
menDistInicio[i] = -1;
pesos[i] = new int [tam];
for (int j=0;j<tam;j++){
pesos[i][j] = 0;
}
}
}


Grafo& Grafo::setPeso(int v1,int v2,int peso){
pesos[v1][v2]= peso;
pesos[v2][v1]= peso;
}

int Grafo::getPesoAresta(int v1,int v2){
return pesos[v1][v2];
}
int Grafo::getTam(){
return tam;
}

void Grafo::imprimeSolucao(int MaxPedagios){
list<int> resultados;
for (int i=0;i<tam;i++){
if (i==posInicial);
else if (menDistInicio[i]<=MaxPedagios && menDistInicio[i]!=-1)
resultados.push_back(i+1);
}
for (list<int>::iterator i=resultados.begin(); i!= resultados.end(); i++)
printf("%i ", *i);
printf("\n");
}

Grafo& Grafo::calculaDist(){
	int aux = posInicial;
	menDistInicio[aux]=0;
	while (cor[aux]!=PRETO){
int pesoMin=10000;
		for (int i=0;i<tam;i++){
			if (aux==i || pesos[i][aux]==0);
			else{
				if(menDistInicio[i]==-1 || menDistInicio[i]>menDistInicio[aux]+pesos[i][aux]){
					menDistInicio[i]=menDistInicio[aux]+pesos[i][aux];
				}
			}
		}
		cor[aux]=PRETO;
		for (int i=0;i<tam;i++){
			if (cor[i]==PRETO || menDistInicio[i]==-1);
			else
				if (menDistInicio[i]<pesoMin){
					pesoMin=menDistInicio[i];
					aux = i;
				}
			
		}
	}
}


int main(){
int nCidades,nEstradas,pInicial,MaxPedagios,a1Aux,a2Aux,
testeAtual=1;
bool primeiraLinha = true;
scanf("%i %i %i %i", &nCidades,&nEstradas,&pInicial,&MaxPedagios);
while (nCidades!=0){
if (!primeiraLinha)
printf("\n");
primeiraLinha=false;
Grafo A(nCidades,pInicial-1);
for (int i=0;i<nEstradas;i++){
scanf("%i %i",&a1Aux,&a2Aux);
a1Aux--;
a2Aux--;
A.setPeso(a1Aux,a2Aux,1);
}
A.calculaDist();
printf("Teste %i\n",testeAtual);
A.imprimeSolucao(MaxPedagios);
scanf("%i %i %i %i", &nCidades,&nEstradas,&pInicial,&MaxPedagios);
testeAtual++;}
return 0;
}


