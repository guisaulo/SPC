#include <stdlib.h>
#include <stdio.h>

int main(){
    int T, N, i, j, destino[11000], atual[11000], troca=0;

    scanf("%d", &T);
    for(i=0; i<T; i++){
        scanf("%d", &N);
        for(j=1; j<=N; j++) {
            scanf("%d", &atual[j]);
            destino[atual[j]]=j;
        }

       for (j = 1; j <= N; j++) {
			if (atual[j] != j) {
				atual[destino[j]] = atual[j];
				destino[atual[j]] = destino[j];
				atual[j] = j;
				destino[j] = j;
				troca++;
			}
		}
        printf("%d\n", troca);
        troca=0;
    }
}
