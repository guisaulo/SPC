#include <stdlib.h>

int main(){

    int N, A, X=0, i;
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &A);
        X += A;
    }
    printf("%d\n", X);
    return 0;

}
