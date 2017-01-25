#include <stdio.h>
#include <stdlib.h>

int compara(const void * a, const void * b){

   return (*(int*)a - *(int*)b);
}

int main(){

    int n, i, candidato, contVotos=1, maiorVoto=-1, vencedor;

    scanf("%d", &n);
    int votos[n];
    i=n;

    while(i--){
        scanf("%d", &candidato);
        votos[i]=candidato;
    }
    i=0;

    qsort(votos, n, sizeof(int), compara);

    while(i<n){

        if(votos[i]==votos[i+1]){
            contVotos++;

            if(contVotos>maiorVoto){
                maiorVoto=contVotos;
                vencedor=i;
            }
        }
        else
            contVotos=1;
        i++;
    }

    printf("%d", votos[vencedor]);
    return 0;
}
