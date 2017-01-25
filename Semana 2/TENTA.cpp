#include <stdio.h>
#include <iostream>
#include <algorithm>

int main(){
    int n_cartas, n_cartas2[10000], cartas[10000][20], i, j, k=0, temp;
    scanf("%d", &n_cartas);
    while(n_cartas!=0){
        n_cartas2[k]=n_cartas;
        //PEGA
        for(i=0; i<n_cartas; i++) scanf("%d", &cartas[k][i]);
        //ORGANIZA
        for(i=0; i<n_cartas; i++){
            for(j=i; j<n_cartas; j++){
                if(cartas[k][i]>cartas[k][j]){
                    temp=cartas[k][i];
                    cartas[k][i]=cartas[k][j];
                    cartas[k][j]=temp;
                }
            }
        }
        k++;
        scanf("%d", &n_cartas);
    }
        //PERMUTA E IMPRIME
        for(i=0; i<k; i++){
            do {
            for(j=0; j<n_cartas2[i]; j++) std::cout << cartas[i][j] << ' ';
            printf("\n");
            } while ( std::next_permutation(cartas[i],cartas[i]+n_cartas2[i]) );
            if(i!=k-1)printf("\n");
        }

}
