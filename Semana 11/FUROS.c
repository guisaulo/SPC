#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, x[1010], y[1010], **distancia, i, j, maior[1010], menor = 99999999, current=0;
    distancia = (int**) malloc(sizeof(int*)*1010);
    for(i=0; i<1010; i++) distancia[i] = (int*) malloc(sizeof(int)*1010);
    while(1){
        current++;
        menor=99999999;
        for(i=0; i<1010; i++) maior[i]=0;
        scanf("%d", &n);
        if(n==0) break;
        for(i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++) {
                distancia[i][j]=sqrt(pow(x[i]-x[j],2) + pow(y[i]-y[j],2));
                if(distancia[i][j]>maior[i]) maior[i]=distancia[i][j];
            }
        for(i=0; i<n; i++){
            if(maior[i]<menor) menor=maior[i];
        }
        printf("Teste %d\n%d\n\n", current, 2*menor+6);

    }
}
