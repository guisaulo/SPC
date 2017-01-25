#include <iostream>
#include <cstdio>

using namespace std;

int main(){

    int X1,Y1,X2,Y2,x,y,N,meteoritos,cont=0;

    while(1){
        scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
        if(X1==0 && Y1==0 && X2==0 && Y2==0)
            break;
        scanf("%d", &N);
        meteoritos=0;
        for(int i=0;i<N;i++){
            scanf("%d %d", &x, &y);
            if(x>=X1 && x<=X2 && y<=Y1 && y>=Y2)
                meteoritos++;
        }
        cout<<"Teste "<<++cont<<endl<<meteoritos<<endl;
    }

    return 0;
}
