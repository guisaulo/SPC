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

    void NovaAresta(graph* grafo, int src, int dest){
        node* newnode = NovoNo(dest);
        newnode->next_node = grafo->adjListArr[src].head;
        grafo->adjListArr[src].head = newnode;
        grafo->adjListArr[src].num_members++;

        newnode = NovoNo(src);
        newnode->next_node = grafo->adjListArr[dest].head;
        grafo->adjListArr[dest].head = newnode;
        grafo->adjListArr[dest].num_members++;
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
    while(p!=NULL)
    {
       i=p->vertex;

       if(!visited[i])
            DFS(grafo, i, visited);
        p=p->next_node;
    }
}

int main(){
    int E, L, src, dest, i, visited[10000], resultados[10000], num_resultados=0;
    do{
        scanf("%d", &E);
        scanf("%d", &L);
        if(E!=0 || L!=0){
            graph* grafo = NovoGrafo(E);
            for(i=0; i<L; i++){
                scanf("%d", &src);
                scanf("%d", &dest);
                NovaAresta(grafo, src, dest);
            }
            for(i=0; i<10000; i++){
                visited[i]=0;
            }
            DFS(grafo, 1, &visited);
            for(i=1; i<=E; i++){
                if(i==E && visited[i]==1){
                    resultados[num_resultados]=1;
                    num_resultados++;
                }
                else if(visited[i]==0){
                    resultados[num_resultados]=0;
                    num_resultados++;
                    break;
                }
            }
            destroyGraph(grafo);
        }
    }while(E!=0 || L!=0);
    for(i=0; i<num_resultados; i++)
        if(resultados[i]==1) printf("Teste %d\nnormal\n\n", i+1);
        else printf("Teste %d\nfalha\n\n", i+1);
}
