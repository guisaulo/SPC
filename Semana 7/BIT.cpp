#include <iostream>

using namespace std;

int main(){
    int V, x=1;
    while(1){
        cin >> V;
        if(V==0) break;

        cout << "Teste " << x << endl;

        cout << V/50 << " ";
        V-=50*(V/50);


        cout << V/10 << " ";
        V-=10*(V/10);


        cout << V/5 << " ";
        V-=5*(V/5);


        cout << V << endl << endl;
        x++;
    }
}
