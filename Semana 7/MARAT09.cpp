#include <iostream>

using namespace std;

int main(){
    int N, M, posicao_agua[20000], resultado=0;
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> posicao_agua[i];
    for(int i=0; i<N-1; i++)
        if(posicao_agua[i+1]-posicao_agua[i] > M){
            cout << "N" << endl;
            resultado=1;
            break;
        }
    if(!resultado && 42195-posicao_agua[N-1] <= M) cout << "S" << endl;
    else if(!resultado) cout << "N" << endl;
}
