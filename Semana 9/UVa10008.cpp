#include <vector>
#include<algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

#define n 256

int compare(pair<char, int> x, pair<char, int> y) {
    if(x.second>y.second)
        return 1;
    if(x.second<y.second)
        return 0;
    return x.first<y.first;
}

int main(){

    int linhas,tamanhoString;
    string S;
    pair<char, int> vetorSimbolos[256];

    for(int i=0; i<n; i++){
        vetorSimbolos[i].first=i;
        vetorSimbolos[i].second=0;
    }

    cin>>linhas;
    getline(cin,S);

    for(int i=0; i<linhas; i++){
        getline(cin, S);
        tamanhoString=S.size();
        for(int i=0; i<tamanhoString; i++){
            if(isalpha(toupper(S[i])))
                vetorSimbolos[toupper(S[i])].second++;
        }
    }

    sort(vetorSimbolos,vetorSimbolos+256,compare);

    for(int i=0; i<n; i++){
        if(vetorSimbolos[i].second>=1)
            cout<<vetorSimbolos[i].first<<" "<<vetorSimbolos[i].second<<endl;
    }
    return 0;
}
