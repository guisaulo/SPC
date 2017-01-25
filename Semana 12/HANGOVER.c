#include <stdio.h>
#include <stdlib.h>

int main(){
    float n, k, i;
    while(1){
        k=0;
        scanf("%f", &n);
        if(n==0.00) break;
        for(i=2; k<n; i++) k+= 1/i;
        printf("%.0f card(s)\n", i-2);
    }
}
