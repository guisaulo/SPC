#include <cstdio>
#include <cstdlib>
#include <iostream>
#define PRETO 2
#define CINZA 1
#define BRANCO 0

class Grafo{
private:
int ** pesos;
int * cor;
bool bipartido; 
int tam;
public:
Grafo& isBipartido();
Grafo();
Grafo(int tam);
Grafo& setPeso(int v1,int v2,int peso);
int getTam();
int getPesoAresta(int v1,int v2);

void imprimeSolucao(int maxPedagios);
};

Grafo::Grafo(){
pesos = NULL;
cor = NULL;
tam = 0;
bipartido = false;
}

Grafo::Grafo(int tam){
this->tam = tam;
bipartido = true;
pesos = new int * [tam];
cor = new int [tam];
for (int i=0;i<tam;i++){
cor[i] = BRANCO;
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

void Grafo::imprimeSolucao(int instancia){
isBipartido();
printf("Instancia %i\n", instancia);
if (bipartido)
	printf("sim");
else
	printf("nao");
printf("\n");
}

Grafo& Grafo::isBipartido(){
	for (int aux=0;aux<tam;aux++){
		if (!bipartido)
			break;
		bool vizinhoCinza = false,vizinhoPreto = false;
		if (cor[aux]==BRANCO){
			for (int i=0;i<tam;i++){
				if (i==aux || pesos[aux][i]==0);
				else if (cor[i]==PRETO){
					vizinhoPreto = true;
					}
				else if (cor[i]==CINZA){
					vizinhoCinza = true;
					}
				}
			if (vizinhoPreto && vizinhoCinza){
				bipartido=false;
				break;
			}
			else if (vizinhoCinza)
				cor[aux]=PRETO;
			else
				cor[aux]=CINZA;
			}
			for (int i=0;i<tam;i++){
				if (i==aux || pesos[aux][i]==0);
				else{
					if (cor[i]==BRANCO){
						if (cor[aux]==CINZA)
							cor[i]=PRETO;
					else if (cor[aux]==PRETO)
							cor[i]=CINZA;
					}
					else if (cor[i]==cor[aux]){
						bipartido=false;
						break;
					}
				}
			}
		}
	
}

int main(){
	int nConvidados,nAmizades,a1Aux,a2Aux,testeAtual=1;
	bool primeiraLinha = true;
	while(scanf("%i",&nConvidados)!=EOF){
		scanf("%i",&nAmizades);
		if (!primeiraLinha)
			printf("\n");
		primeiraLinha=false;
		Grafo A(nConvidados);
		for (int i=0;i<nAmizades;i++){
			scanf("%i %i",&a1Aux,&a2Aux);
			a1Aux--;
			a2Aux--;
			A.setPeso(a1Aux,a2Aux,1);
		}
		A.imprimeSolucao(testeAtual);
		testeAtual++;
	}
	return 0;
}
