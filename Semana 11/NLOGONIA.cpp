#include <iostream>
#include <cstdio>

using namespace std;

int main(){

    int K,N,M,X,Y;

    while(1){
        cin>>K;
        if(K==0)
            break;
        cin>>N>>M;
        for(int i=0;i<K;i++){
            cin>>X>>Y;
            if(X==N || Y==M)
                cout<<"divisa"<<endl;
            else if(X<N && Y>M)
                cout<<"NO"<<endl;
            else if(X>N && Y>M)
                cout<<"NE"<<endl;
            else if(X>N && Y<M)
                cout<<"SE"<<endl;
            else if(X<N && Y<M)
                cout<<"SO"<<endl;
        }
    }
    return 0;
}
