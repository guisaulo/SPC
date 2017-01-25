#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

int main(){
    int entrada, i;
    scanf("%d", &entrada);
    int *leite = (int*)malloc(sizeof(int)*entrada+1);
    for(i=0; i<entrada; i++) scanf("%d", &leite[i]);
    std::sort(leite, leite+entrada);
    //for(i=0; i<entrada; i++) printf("%d ", leite[i]);
    if(entrada%2==1) printf("%d", leite[(entrada/2)]);
    else printf("%d", (leite[(entrada-1)/2]+leite[(entrada-1)/2+1])/2);
}
