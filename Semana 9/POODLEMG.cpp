#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, p, i, pags;
    char *resultado;
    while(1){
        scanf("%d %d", &n, &p);

        if(n==0 && p==0)break;

        if(n%p>0) pags = (n/p)+1;
        else pags=n/p;

        resultado = (char*)malloc(sizeof(char)*(n/p)+200);

        if(pags<=6)printf("Poodle\n");
        else{
            strcpy (resultado,"P");

            for(i=0; i<pags-4; i++) if(i<16)strcat(resultado,"o");

            strcat(resultado,"dle\n");

            printf("%s", resultado);
        }
    }
}
