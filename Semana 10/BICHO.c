#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n;
    double v, resultado;
    while(1){
        resultado=0;
        scanf("%lf %d %d", &v ,&m, &n);
        if(m==0 && n==0 && v==0)break;

        if(m%10000==n%10000) resultado=v*3000;
        else if(m%1000==n%1000) resultado=v*500;
        else if(m%100==n%100) resultado=v*50;
        else if(n%100==0 || m%100==0){
            if((ceil(n%100/4.00)==0 && ceil(m%100/4.00)==25) || (ceil(m%100/4.00)==0 && ceil(n%100/4.00)==25)) resultado=v*16;
        }
        else if(ceil(n%100/4.00)==ceil(m%100/4.00)) resultado=v*16;
        printf("%.2lf\n", resultado);
    }
}
