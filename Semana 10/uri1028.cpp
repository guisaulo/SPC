#include <iostream>

using namespace std;

int mdc(int x, int y){
    if(y==0)
        return x;
    else
        return mdc(y,x%y);
}
int main(){
    int N,F1,F2;
    cin>>N;
    while(N--){
        cin>>F1>>F2;
        cout<<mdc(F1,F2)<<endl;
    }
    return 0;
}
