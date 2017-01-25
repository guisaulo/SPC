#include <stdlib.h>
#include<stdio.h>

int main(){
    int i, j=0, soma, N, N2[10010], resposta[100000], inbox, N_res=0;
    for(i=0; i<100000; i++)resposta[i]=0;
    scanf("%d", &N);
    while(N!=-1){
        N_res++;
        soma=0;
        for(i=0; i<N; i++)scanf("%d", &N2[i]);
        for(i=0; i<N; i++)soma+=N2[i];
        if(soma%N!=0) resposta[j]=-1;
        else{
            inbox=soma/N;
            for(i=0; i<N; i++){
                if(N2[i]>inbox) resposta[j]+=N2[i]-inbox;
            }
        }
        scanf("%d", &N);
        j++;
    }
    for(i=0; i<N_res; i++)printf("%d\n", resposta[i]);
}
