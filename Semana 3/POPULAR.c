#include <stdio.h>
#include <stdlib.h>

int main() {

    int instancia, i, j, popular=0, cont=0;

    scanf("%d", &instancia);

    while(instancia!=0){

        int votos[instancia][instancia];

        for(i=0; i<instancia; i++){
            for(j=0; j<instancia; j++)
                scanf("%d", &votos[i][j]);
        }

        for(i=0; i<instancia; i++){
            for(j=0; j<instancia; j++)
                cont+=votos[j][i];
            if(cont>popular)
                popular=cont;
            cont=0;
        }

        printf("%d\n", popular);
        popular=0;
        scanf( "%d",&instancia);
    }
    return 0;
}
