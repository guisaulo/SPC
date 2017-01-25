#include <cstdio>
#include <cmath>

using namespace std;
#define X 0
#define Y 1
#define MAX_DIST 8000001.000

long double calcDistancia(long double x1, long double x2,long double y1, long double y2){
   long double pow_x=(x1-x2)*(x1-x2);
   long double pow_y=(y1-y2)*(y1-y2);
   return ((long double)sqrt(pow_x+pow_y));
}



int main(){
   int nPontos=0;
   scanf("%i",&nPontos);
   long double ** vecPontos = new long double * [nPontos];
   for (int i=0;i<nPontos;i++){
      vecPontos[i] = new long double [2];
      scanf("%Lf %Lf",&vecPontos[i][X],&vecPontos[i][Y]);
   }
   long double menDist = MAX_DIST;
   for (int i=0;i<nPontos;i++){
      for (int j=0;j<nPontos;j++){
	 if (i==j);
	 else{
	    if (calcDistancia(vecPontos[i][X],vecPontos[j][X],vecPontos[i][Y],vecPontos[j][Y]) <= menDist)
	    menDist = calcDistancia(vecPontos[i][X],vecPontos[j][X],vecPontos[i][Y],vecPontos[j][Y]);
	 }
      }
   }
   printf("%.3Lf\n",menDist);
}
