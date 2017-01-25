#include <stdio.h>
#include <stdlib.h>

//Implementação da estrutura de grafos
    typedef struct node{
        int vertex;
        struct node* next_node;
    }node;

    typedef struct adjlist{
        int num_members;
        node *head;
    }adjlist;

    typedef struct graph{
        int num_vertices;
        adjlist* adjListArr;
    }graph;
//Fim

//Implementação das funções de grafos
    node* NovoNo(int v){
        node* newnode = (node*)malloc(sizeof(node));
        newnode->vertex = v;
        newnode->next_node = NULL;
        return newnode;
    }

    graph* NovoGrafo(int n){
        int i;
        graph* grafo = (graph*)malloc(sizeof(graph));
        grafo->num_vertices = n;
        grafo->adjListArr = (adjlist*)malloc(sizeof(adjlist)*(n+1));
        for(i = 0; i <= n; i++){
            grafo->adjListArr[i].head = NULL;
            grafo->adjListArr[i].num_members = 0;
        }
        return grafo;
    }

    void NovaAresta(graph* grafo, int src, int dest, int tipo){
        node* newnode = NovoNo(dest);
        newnode->next_node = grafo->adjListArr[src].head;
        grafo->adjListArr[src].head = newnode;
        grafo->adjListArr[src].num_members++;

        if(tipo==2){
            newnode = NovoNo(src);
            newnode->next_node = grafo->adjListArr[dest].head;
            grafo->adjListArr[dest].head = newnode;
            grafo->adjListArr[dest].num_members++;
        }
    }

    void destroyGraph(graph* graph){
        if(graph)
        {
            if(graph->adjListArr)
            {
                int v;
                for (v = 0; v < graph->num_vertices; v++)
                {
                    node* adjListPtr = graph->adjListArr[v].head;
                    while (adjListPtr)
                    {
                        node* tmp = adjListPtr;
                        adjListPtr = adjListPtr->next_node;
                        free(tmp);
                    }
                }
                free(graph->adjListArr);
            }
            free(graph);
        }
    }
//Fim

void DFS(graph* grafo, int i, int* visited){
    node* p;

    //printf("\n%d",i);
    p=grafo->adjListArr[i].head;
    visited[i]=1;
    while(p!=NULL){
       i=p->vertex;

       if(!visited[i]){
            DFS(grafo, i, visited);
       }
        p=p->next_node;
    }
}

int main(){
    int i, j, k, N, M, V, W, P, **visited, resultados[2000], num_resultados, break_again;

    visited=(int**)malloc(sizeof(int*)*220);
    for(i=0; i<220; i++) visited[i]=(int*)malloc(sizeof(int)*2000);

        do{
        scanf("%d", &N);
        scanf("%d", &M);

        if(N!=0 || M!=0){
            num_resultados=0;
            break_again=0;
            graph* grafo = NovoGrafo(N);

            for(i=0; i<M; i++){
                scanf("%d", &V);
                scanf("%d", &W);
                scanf("%d", &P);
                NovaAresta(grafo, V, W, P);
            }

            for(j=0; j<200; j++){
                for(i=0; i<2100; i++){
                    visited[j][i]=0;
                }
            }

            for(j=1; j<=N; j++){
                DFS(grafo, j, visited[j]);

                for(i=1; i<=N; i++){
                    if(i==N && j==N && visited[j][i]==1){
                        resultados[num_resultados]=1;
                        num_resultados++;
                    }

                    else if(visited[j][i]==0){
                        resultados[num_resultados]=0;
                        num_resultados++;
                        break_again=1;
                        break;
                    }
                }
                if(break_again==1)break;
            }
            destroyGraph(grafo);
        }
    }while(N!=0 || M!=0);

    for(i=0; i<num_resultados; i++)
        if(resultados[i]==1) printf("1\n");
        else printf("0\n");

}

