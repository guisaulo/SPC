#include <iostream>

using namespace std;

#define INF 100000000

int main(){

    int N, E, T, M, a, b, t, cont=0;

    cin >> N >> E >> T >> M;

    int grafo[N][N];

    //insere 0 e infinitos na matriz de adjacencia
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j)
                grafo[i][j]=0;
           else{
                grafo[i][j]=INF;
                grafo[j][i]=INF;
           }
        }
    }

    for(int i=0; i<M; i++){
        cin >> a >> b >> t;
        grafo[a-1][b-1]=t;
    }

    //algorimo de floyd warshall - gera na propria matriz o menor caminho entre todos os vertices do conjunto de vertices
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(grafo[i][k] + grafo[k][j] < grafo[i][j])
                    grafo[i][j] = grafo[i][k] + grafo[k][j];
            }
        }
    }

    for(int i=0; i<N; i++){
        if(grafo[i][E-1]<=T)
            cont++;
    }

    cout << cont << endl;

    return 0;
}
