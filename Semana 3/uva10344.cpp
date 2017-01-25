#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){

    int condicao, a, b, c, d, e, i, j, k, l, n, resultado=0, possivel=0, achou=0;
    int vetor[5], operacao[4];

    cin >> a >> b >> c >> d >> e;
    condicao=a+b+c+d+e;

    while(condicao!=0){

        vetor[0]=a;
        vetor[1]=b;
        vetor[2]=c;
        vetor[3]=d;
        vetor[4]=e;

        std::sort(vetor,vetor+5);

        do{

            //std::cout << vetor[0] << ' ' << vetor[1] << ' ' << vetor[2] << ' ' << vetor[3] << ' ' << vetor[4] <<'\n';
            for(i=0; i<=2; i++){
                for(j=0; j<=2; j++){
                    for(k=0; k<=2; k++){
                        for(l=0; l<=2; l++){

                            //printf("%d %d %d %d\n", i, j, k, l);
                            operacao[0]=i;
                            operacao[1]=j;
                            operacao[2]=k;
                            operacao[3]=l;

                            resultado=0;
                            resultado=vetor[1];

                            for(n=0; n<=3; n++){

                                if(operacao[n]==0)
                                    resultado = resultado + vetor[n+1];

                                else if(operacao[n]==1)
                                    resultado = resultado - vetor[n+1];

                                else if(operacao[n]==2)
                                    resultado = resultado * vetor[n+1];
                            }

                            //printf("%d\n", resultado);
                            if(resultado==23){
                                //printf("Possible\n");
                                possivel++;
                            }
                        }
                    }
                }
            }

            if(possivel!=0){
                //printf("Possible\n");
                achou++;
            }

            //else    printf("Impossible\n");
            resultado=0;
            possivel=0;

        }while(std::next_permutation(vetor,vetor+5));

            if(achou!=0)
                printf("Possible\n");

            else
                printf("Impossible\n");

            achou=0;

            scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
            condicao=a+b+c+d+e;
    }

    return 0;
}
