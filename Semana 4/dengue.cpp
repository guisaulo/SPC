#include <iostream>
using namespace std;

#define INF 100000000

int main(){

    int v1, v2, n, maior, menorMaior, vila, contador=0;

    while(cin >> n){
        if(n==0)
            break;

        int grafo[n][n];

        //insere 0 e infinitos na matriz de adjacencia
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)
                    grafo[i][j]=0;
                else{
                    grafo[i][j]=INF;
                    grafo[j][i]=INF;
                }
            }
        }

        //insere peso 1 entre as arestas
        for(int i=0; i<n-1; i++){
            cin >> v1 >> v2;
            grafo[v1-1][v2-1]=1;
            grafo[v2-1][v1-1]=1;
        }

        //algorimo de floyd warshall - gera na propria matriz o menor caminho entre todos os vertices do conjunto de vertices
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(grafo[i][k] + grafo[k][j] < grafo[i][j])
                        grafo[i][j] = grafo[i][k] + grafo[k][j];
                }
            }
        }

        //encontra o vertice que contem o menor distancia entre as maiores distancias
        menorMaior=INF;
        for(int i=0; i<n; i++){
            maior=0;
            for(int j=0; j<n; j++){
                if(grafo[i][j] > maior)
                    maior=grafo[i][j];
            }
            if(maior < menorMaior){
                menorMaior=maior;
                vila=i+1;
            }
        }

        contador++;
        cout << "Teste " << contador << endl << vila << endl << endl;
    }
    return 0;
}
