#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int L,C,R1,R2;

    while(true){
        cin>>L>>C>>R1>>R2;
        if(L==0 || C==0 || R1==0 || R2==0)
            break;

        if(!((R1+R1>L) || (R1+R1>C) || (R2+R2>L) || (R2+R2>C))){
            if(sqrt(pow((L-R2-R1),2)+pow((C-R2-R1),2))>=R1+R2)
                cout<<"S"<<endl;
            else
                cout<<"N"<<endl;
        }
        else
            cout<<"N"<<endl;
    }
    return 0;
}
