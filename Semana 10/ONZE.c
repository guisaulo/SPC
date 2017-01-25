#include <stdio.h>
#include <stdlib.h>

int main(){
    char numero[2000];
    int soma=0, i;

    while(1){
        soma=0;
        scanf("%s", &numero);
        if(strcmp(numero, "0")==0)break;

        for(i=0; numero[i]!='\0'; i++){
            printf("%d",numero[i]-48);
            if(i%2==0)soma+=numero[i]-48;
            else soma-=numero[i]-48;
        }

        if(soma%11==0) printf(" is a multiple of 11.\n");
        else printf(" is not a multiple of 11.\n");
    }
}
