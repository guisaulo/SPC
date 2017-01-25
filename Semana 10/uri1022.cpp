#include <cstdio>
#include <cmath>

using namespace std;

int mDC (int a,int b){
   a=fabs(a);
   b=fabs(b);
   int resto = a%b;
   while (resto!=0){
   a = b;
   b = resto;
   resto = a%b;
   }
   return b;
}


int main(){
   int nOperacoes = 0;
   scanf("%i",&nOperacoes);
   for (int i=0;i<nOperacoes;i++){
      int den1=1,num1=0,den2=1,num2=0,numFin=0,denFin=1,numFinSimp = 0,denFinSimp = 1,mdcAux = 1;
      char barra1,barra2, op;
      scanf("%i %c %i %c %i %c %i",&num1,&barra1,&den1,&op,&num2,&barra2,&den2);
      if (op=='-'){
         numFin = (num1*den2) - (num2*den1);
         denFin = den1 * den2;
      }
      else if (op=='+'){
         numFin = (num1*den2) + (num2*den1);
         denFin = den1 * den2;
      }
      else if (op=='*'){
	 numFin = num1 * num2;
	 denFin = den1 * den2;
      }
      else if (op=='/'){
	 numFin = num1 * den2;
	 denFin = num2 * den1;
      }
      if (numFin > 0 && denFin < 0){
	 numFin = numFin*(-1);
	 denFin = denFin*(-1);
      }
      else if (numFin < 0 && denFin < 0){
	 denFin = denFin*(-1);
	 numFin = numFin*(-1);
      }
      mdcAux = mDC(numFin,denFin);
      numFinSimp = numFin / mdcAux;
      denFinSimp = denFin / mdcAux;
      printf("%i/%i = %i/%i\n",numFin,denFin,numFinSimp,denFinSimp);
   }
}
