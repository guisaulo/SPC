#include <cstdio>
using namespace std;
 int main(){
       int tam, nPesq,valorPesq;
       scanf("%i", &tam);
       scanf("%i", &nPesq);
       int * vec = new int [tam];
       for (int i =0; i< tam; i++){
          scanf("%i", &vec[i]);
        }
       for (int i=0; i < nPesq; i++){
        scanf("%i", &valorPesq);
         int limInf = 0;
         int limSup = tam;
         int metade = (limInf+limSup)/2;
         while (limInf <= limSup){
               if(vec[metade] < valorPesq)
                   limInf= metade + 1;
          else if (vec[metade] == valorPesq){
                while(vec[metade-1]== valorPesq)
                    metade--;
                printf("%i\n",metade);
                break;
          }
         else
              limSup = metade - 1;
         metade = (limInf + limSup)/2;
         }
         if (limInf > limSup)
           printf("-1\n");;
         
}
return (0);
}
