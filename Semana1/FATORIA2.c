#include <stdlib.h>

int main(){

    int N, X=1, i;
    scanf("%d", &N);
    for(i=0; i<=N; i++){
        if(i>0)X *= i;
    }
    printf("%d\n", X);
    return 0;

}
