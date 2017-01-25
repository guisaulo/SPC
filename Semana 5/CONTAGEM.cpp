#include <iostream>
#include <string>
#include <cstdio>
#include <list>
#include <cmath>
using namespace std;

int main(){
list<string> palavras;
char * aux;
string aux2;
bool haveB = false;
int isntancia=1;
while(cin >> aux2){
palavras.push_back(aux2);
}
bool primeiraLinha = true;
for (list<string>::iterator i=palavras.begin(); i!= palavras.end(); i++){
int aux3=0;
long long sumAux=0;
	for (int j=0; j< (*i).length(); j++){
		if ((*i).at(j)=='b')
sumAux+=pow(2, ( (*i).length() ) - (j+1) );
		}
		if (!primeiraLinha)
		cout << "\n";
		primeiraLinha=false;
		cout << "Palavra " << isntancia << "\n" << sumAux << "\n";
		isntancia++;
		aux3=0;sumAux=0;
		haveB = false;
	}
return 0;
}
