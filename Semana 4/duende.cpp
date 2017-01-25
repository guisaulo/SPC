#include <iostream>
#include <queue>

using namespace std;

#define TAM     10
#define SAIDA   0
#define CRISTAL 2
#define INICIO  3
#define FALSE   0
#define TRUE    1

typedef struct {
    int valor;
    int visitado;
    int distancia;
} Grafo;

typedef struct {
    int x;
    int y;
} Vertice;

Grafo g[TAM][TAM];
int N, M, adjacentes[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool verificaDentroCaverna(int x, int y){

    return (x>=0 && x < N && y>=0 && y< M);
}

int buscaLargura(int x, int y){

    Vertice vInicial, u, prox;
    vInicial.x=x;
    vInicial.y=y;

    g[vInicial.x][vInicial.y].distancia=0;  //seta distancia do vertice inicial

    //marcar todos vertices do grafo como não visitados
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++)
            g[i][j].visitado=FALSE;
    }

    g[vInicial.x][vInicial.y].visitado=TRUE; //Marca vInicial como visitado
    queue<Vertice> fila; //Inicializa a fila
    fila.push(vInicial); //Colocar v no final da fila

    while(!fila.empty()){
        u=fila.front(); //pega o primeiro vertice da fila
        fila.pop();

        if(g[u.x][u.y].valor==SAIDA) //se o vertice for um vertice de saida, a busca acaba
            break;

        for(int i=0; i<4; i++){ //Para os 4 vertices adjacentes do vertice u
            prox.x=u.x+adjacentes[i][0]; //pega o proximo vertice adjacente
            prox.y=u.y+adjacentes[i][1];

            if(verificaDentroCaverna(prox.x,prox.y)){ //verifica se o vertice pertence a caverna
                if((g[prox.x][prox.y].visitado==FALSE) && (g[prox.x][prox.y].valor!=CRISTAL)){ //verifica se o vertice não foi visitado e se não é um cristal
                    g[prox.x][prox.y].distancia=g[u.x][u.y].distancia+1;
                    g[prox.x][prox.y].visitado=TRUE; //marca como visitado
                    fila.push(prox); //emfileira o prox vertice adjacente
                }
            }
        }
    }

    return g[u.x][u.y].distancia;

}

int main(){

    int x, y;

    cin >> N >> M;

    //insere valores da caverna na matriz
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> g[i][j].valor;
            if (g[i][j].valor==INICIO){
                x=i;
                y=j;
                g[i][j].valor=1;
            }
        }
    }

    cout << buscaLargura(x,y) << endl;

    return 0;
}
