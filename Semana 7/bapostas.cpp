#include <iostream>

using namespace std;

int main(){

    int N, num, soma, somaMax;

    cin>>N;

    while(N!=0){
        soma=0;
        somaMax=-1;
        for(int i=0; i<N; i++){
            cin>>num;
            soma+=num;

            if(soma<0)
                soma=0;
            if(soma>somaMax)
                somaMax=soma;
        }

        if(soma>0)
            cout<<"The maximum winning streak is "<<somaMax<<"."<<endl;
        else
            cout<<"Losing streak."<<endl;

        cin>>N;
    }

    return 0;
}
