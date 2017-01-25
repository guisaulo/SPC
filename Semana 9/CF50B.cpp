#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define n 256

int main(){

    int vetorSimbolos[n];
    for(int i=0; i<=n; i++)
        vetorSimbolos[i]=0;

    double pares=0;
    string S;
    cin>>S;

    int tamanhoString=S.size();
    for(long k=0; k<tamanhoString; k++)
        vetorSimbolos[S[k]]++;

    for(int k=0; k<n; k++){
        if(vetorSimbolos[k]>=1)
            pares+=(double)vetorSimbolos[k]*vetorSimbolos[k];
    }

    printf("%.0lf\n",pares);
    return 0;
}
