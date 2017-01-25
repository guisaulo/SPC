#include <iostream>

using namespace std;

int main(){

    while(1){
        int N,P;

        cin>>N>>P;
        if(N==0 && P==0) break;

        int Q[P],numCaixa,numPilhaCaixa1,alturaCaixa1,desempilhaEsq=0,desempilhaDir=0;

        for(int i=0; i<P; i++){
            cin>>Q[i];
            for(int j=1; j<=Q[i]; j++){
                cin>>numCaixa;
                if(numCaixa==1){
                    numPilhaCaixa1=i;
                    alturaCaixa1=j;
                }
            }
        }

        for(int i=numPilhaCaixa1-1; i>=0 && Q[i]>=alturaCaixa1; i--)
            desempilhaEsq+=Q[i]-alturaCaixa1+1;
        for(int i=numPilhaCaixa1+1; i<P && Q[i]>=alturaCaixa1; i++)
            desempilhaDir+=Q[i]-alturaCaixa1+1;

        cout<<min(desempilhaEsq,desempilhaDir)+Q[numPilhaCaixa1]-alturaCaixa1<<endl;
    }
    return 0;
}
