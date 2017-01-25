#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, p, i, pags;
    char resultado[100];
    while(scanf("%s", &resultado)!=EOF){

        for(i=0; resultado[i]!='\0'; i++) {
            if(resultado[i]=='A' || resultado[i]=='B' || resultado[i]=='C') printf("2");
            else if(resultado[i]=='D' || resultado[i]=='E' || resultado[i]=='F') printf("3");
            else if(resultado[i]=='G' || resultado[i]=='H' || resultado[i]=='I') printf("4");
            else if(resultado[i]=='J' || resultado[i]=='K' || resultado[i]=='L') printf("5");
            else if(resultado[i]=='M' || resultado[i]=='N' || resultado[i]=='O') printf("6");
            else if(resultado[i]=='P' || resultado[i]=='Q' || resultado[i]=='R' || resultado[i]=='S') printf("7");
            else if(resultado[i]=='T' || resultado[i]=='U' || resultado[i]=='V') printf("8");
            else if(resultado[i]=='W' || resultado[i]=='X' || resultado[i]=='Y' || resultado[i]=='Z') printf("9");
            else if(resultado[i]=='-') printf("-");
            else printf("%c", resultado[i]);
        }
       printf("\n");

    }
}
