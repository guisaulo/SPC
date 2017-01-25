#include <iostream>
using namespace std;
int main(){
int nLinhas, nColunas, ** matriz, aux,
maxSoma = 0, somaAtual = 0;
cin >> nLinhas;
cin >> nColunas;
matriz = new int * [nLinhas];
for (int i=0;i< nLinhas; i++){
matriz[i] = new int [nColunas];
}
for (int i=0; i<nLinhas; i++){
somaAtual = 0;
for (int j=0; j<nColunas; j++){
cin >> aux;
matriz[i][j] = aux;
somaAtual+= aux;
}
if (somaAtual > maxSoma)
 maxSoma = somaAtual;
}
for (int j=0; j<nColunas; j++){
somaAtual = 0;
for (int i=0;i<nLinhas; i++)
somaAtual+= matriz[i][j];
if (somaAtual > maxSoma)
 maxSoma = somaAtual;
}
cout << maxSoma << endl;
return 0;}
