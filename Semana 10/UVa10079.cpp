#include <iostream>

using namespace std;

int main() {

    long long N;
    cin>>N;
    while(N>=0){
        cout<<((N*(N+1))/2+1)<<endl;
        cin>>N;
    }
}
