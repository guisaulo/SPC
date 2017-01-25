#include <iostream>

using namespace std;

#define INF 100000000

int main(){

    int n, m, t, b, s, src, d;

    do{
    cin >> n >> m;
    if(!n && !m) break;
    int grafo[n+10][n+10];

    //insere 0 e infinitos na matriz de adjacencia
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==j)
                grafo[i][j]=0;
           else{
                grafo[i][j]=INF;
                grafo[j][i]=INF;
           }
        }
    }

    for(int i=0; i<m; i++){
        cin >> s >> t >> b;
        grafo[s][t]=b;
    }
    cin >> src >> d;

    //algorimo de floyd warshall - gera na propria matriz o menor caminho entre todos os vertices do conjunto de vertices
    for(int k=0; k<=n; k++){
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(grafo[i][k] + grafo[k][j] < grafo[i][j])
                    grafo[i][j] = grafo[i][k] + grafo[k][j];
            }
        }
    }

    if(grafo[src][d]==INF) cout << -1 << endl;
    else cout << grafo[src][d] << endl;
    }while(n!=0 || m!=0);

    return 0;
}
