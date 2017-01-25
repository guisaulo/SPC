#include <stdio.h>


unsigned long long primNZeroFat (unsigned long long nFat){
   unsigned long long fat = 1;
   unsigned long long i=1;
   for (i=2;i<=nFat;i++){
      if ((fat*i)%100000!=0)
      fat=((fat*i)%100000);
      //fat=(((fat+10000)/10000)-1);
      //printf("%llu\n",fat);
      while (fat%10000==0)
         //fat/=10000;
      //if (fat%1000==0)
       // fat/=1000;
     // if (fat%100==0)
      //  fat/=100;
     // if (fat%10==0)
        fat/=10000;
      while (fat%10==0)
         fat/=10;
      //fat=fat%100000;
   }	
   return fat%10;
}

int main(){
   unsigned long long nFat=0;
   int instancia=1;
   while (scanf("%llu",&nFat)!= EOF){
      printf("Instancia %i\n%llu\n",instancia,primNZeroFat(nFat));
      }
   return 0;
}
