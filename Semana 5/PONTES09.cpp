#include <iostream>

using namespace std;

#define INF 100000000

int distMin(int* distancia, int* visited, int ver_num){
   int min = INF, min_index, i;

    for (i = 0; i <=ver_num; i++){
        if (visited[i] == 0 && distancia[i] <= min){
            min = distancia[i];
            min_index = i;
        }
    }
   return min_index;
}

int Dijkstra(int** graph, int ver_num, int a, int b){
    int distancia[ver_num], u, i, j, count, visited[ver_num];

    for (i = 0; i <=ver_num; i++){
        distancia[i] = INF;
        visited[i] = 0;
    }
    distancia[a] = 0;

    for (count = 0; count < ver_num; count++){
        u = distMin(distancia, visited, ver_num);

        visited[u] = 1;

        for (j=0; j<=ver_num; j++)
            if (!visited[j] && graph[u][j]!=-1 && distancia[u]+graph[u][j] < distancia[j]) {
                distancia[j] = distancia[u] + graph[u][j];
            }
     }

      return distancia[b];
}


int main(){

    int n, m, t, b, s, src, d;

    cin >> n >> m;

    int **grafo = new int*[1001];
    for(int i=0; i<=1001; i++) grafo[i] = new int[1001];

    //insere 0 e infinitos na matriz de adjacencia
    for(int i=0; i<n+2; i++){
        for(int j=0; j<n+2; j++){
            if(i==j)
                grafo[i][j]=0;
           else{
                grafo[i][j]=INF;
           }
        }
    }

    for(int i=0; i<m; i++){
        cin >> s >> t >> b;
        grafo[s][t]=b;
        grafo[t][s]=b;
    }

    cout << Dijkstra(grafo, n+1, 0, n+1);

    return 0;
}
