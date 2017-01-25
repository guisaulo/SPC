#include <stdlib.h>
#include <stdio.h>

int main(){
    int i, j, entrada, len;

    scanf("%d", &entrada);

    char **palavra = malloc(sizeof(char*)*entrada);
    char **palavrasaida = malloc(sizeof(char*)*entrada);
    char *c = malloc(sizeof(char)*entrada);

    for(i=0; i<entrada; i++)palavra[i] = malloc(sizeof(char)*50);
    for(i=0; i<entrada; i++)palavrasaida[i] = malloc(sizeof(char)*50);

    for(i=0; i<entrada; i++){
        scanf("%s", palavra[i]);
        strcpy(palavrasaida[i],palavra[i]);
        len=strlen(palavra[i]);
        if(len==1) c[i] = 'O';
        else{
            for(j=0; j<len-1; j++){
                if(palavra[i][j]<97) palavra[i][j]+=32;
                if(palavra[i][j+1]<97) palavra[i][j+1]+=32;
                if(palavra[i][j]<palavra[i][j+1]) c[i] = 'O';
                else{
                    c[i] = 'N';
                    break;
                }
            }
        }
    }
    for(i=0; i<entrada; i++){
        printf("%s: %c\n", palavrasaida[i], c[i]);
    }
}
