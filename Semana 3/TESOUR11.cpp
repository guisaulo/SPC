#define DICA  0
#define POSLOC  1 
#include <iostream>
#include <cstdio>
using namespace std;
class Mapa{
public:
int *** matriz;
int tam;
Mapa(int tam);
Mapa();
Mapa& adicionaPista(int x,int y,int distancia);
Mapa& achaLocais();
Mapa& imprimeSolucao();
};

Mapa::Mapa(){
tam = 0;
matriz = NULL;
}

Mapa::Mapa(int tam){
this->tam = tam;
matriz = new int ** [tam];
for (int i=0;i<tam;i++){
matriz[i] = new int * [tam];
for (int j=0;j<tam;j++){
matriz[i][j]=new int [2];
matriz[i][j][DICA] = -1;
matriz [i][j][POSLOC] = 0;
}
}
}

Mapa& Mapa::adicionaPista(int x,int y,int distancia){
matriz[x][y][DICA]=distancia;
}

Mapa& Mapa::achaLocais(){
for (int i=0;i<tam;i++){
for (int j=0;j<tam;j++){
if (matriz[i][j][DICA]>=0){
int dica = matriz[i][j][DICA];
int x=dica,y=0;
for (int k=0;k<=dica; k++){
if (x==0 && y==0){
matriz[i][j][POSLOC] +=1;
}

else if (y==0){
if (x+i < tam){
matriz[x+i][j][POSLOC] +=1;
}
if(i-x >=0){
matriz[i-x][j][POSLOC] +=1;
}
}

else if (x==0){
if (y+j < tam){
matriz[i][y+j][POSLOC] +=1;
}
if(j-y >=0){
matriz[i][j-y][POSLOC] +=1;
}
}

else {
if (x+i < tam && y+j < tam){
matriz[x+i][y+j][POSLOC] +=1;
}
if (x+i < tam && j-y >= 0){
matriz[x+i][j-y][POSLOC] +=1;
}
if (i-x >=0 && y+j < tam){
matriz[i-x][y+j][POSLOC] +=1;
}
if (i-x >=0 && j-y >= 0){
matriz[i-x][j-y][POSLOC] +=1;
}
}

x--;
y++;

}

}

}}

}



Mapa& Mapa::imprimeSolucao(){
bool solUnica = false;
int valorMax=0,valorAux=0,posSol[2] = {-1,-1};
for (int i=0;i<tam;i++){
for (int j=0;j<tam;j++){
valorAux=matriz[i][j][POSLOC];
if (valorAux > valorMax){
solUnica = true;
valorMax = valorAux;
posSol[0]= i;
posSol[1]= j;
}
else if (valorAux==valorMax){
solUnica = false;
}
}
}
if (!solUnica){
posSol[0]= -1;
posSol[1]= -1;
}
printf("%i %i\n",posSol[0],posSol[1]);
}


int main(){
int tam,nregras,x,y,dist;
scanf("%i",&tam);
scanf("%i",&nregras);
Mapa mapa(tam);
for (int i=0;i<nregras;i++){
scanf("%i",&x);
scanf("%i",&y);
scanf("%i",&dist);
mapa.adicionaPista(x,y,dist);
}
mapa.achaLocais();
mapa.imprimeSolucao();
return 0;}
