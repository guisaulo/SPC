#include <iostream>
#include <cstdio>

using namespace std;

int main(){

    int S,N;

    cin>>S>>N;

    int tamanho[N+1],valor[N+1];

    for(int i=1;i<=N;i++)
        cin>>tamanho[i]>>valor[i];

    //Algoritmo da Mochila Limitado 0/1
    //Matriz bidimensional com S+1 e N+1 colunas, inicializada com zeros
    int K[S+1][N+1];
    for(int i=0;i<S+1;i++){
        for(int j=0;j<N+1;j++){
            K[i][j]=0;
        }
    }


	for(int j=1; j<=N; j++) { //j são os itens
		for(int w=1; w<=S; w++) { //w é o tamanho da mochila
			if(tamanho[j]>w)
                K[w][j]=K[w][j-1];
			else
                K[w][j]=max(K[w][j-1],K[w-tamanho[j]][j-1] + valor[j]);
		}
	}

	cout<<K[S][N]<<endl;

    return 0;
}
