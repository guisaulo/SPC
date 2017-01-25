#include <iostream>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
long long nLinhas,dist,sol;
cin >> nLinhas;
for (int i=0;i<nLinhas;i++){
cin >> dist;
if (dist%3==0)
sol = dist/3;
else
sol = 0;
cout << sol << '\n';
}
return 0;
}
