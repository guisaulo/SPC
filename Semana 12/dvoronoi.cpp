#include <cstdio>
#include <cmath>
#include <iostream>
#define X 0
#define Y 1
#define Z 2


using namespace std;

long double areaDet(int * vec1, int * vec2, int * vec3){
   long double a1,a2,a3,b1,b2,b3;
   a1=(long double)(vec1[X]*vec2[Y]*vec3[Z]);
   a2=(long double)(vec1[Y]*vec2[Z]*vec3[X]);
   a3=(long double)(vec1[Z]*vec2[X]*vec3[Y]);
   b1=(long double)(vec3[X]*vec2[Y]*vec1[Z]);
   b2=(long double)(vec3[Y]*vec2[Z]*vec1[X]);
   b3=(long double)(vec3[Z]*vec2[X]*vec1[Y]);
   return abs((a1+a2+a3-(b1+b2+b3))/6);
}

int main(){
   int instancias = 0;
   scanf("%i",&instancias);
   for (int i=0;i<instancias;i++){
      int p1[3],p2[3],p3[3],p4[3],vec1[3],vec2[3],vec3[3];
      long double area=0;
      for (int j=0;j<3;j++){
	 p1[j]=0;   p2[j]=0; 
	 p3[j]=0;   p4[j]=0;
	 vec1[j]=0; vec2[j]=0;
	 vec3[j]=0;
      }
      scanf("%i %i %i %i %i %i %i %i %i %i %i %i",&p1[X],&p1[Y],&p1[Z],&p2[X],&p2[Y],&p2[Z],&p3[X],&p3[Y],&p3[Z],&p4[X],&p4[Y],&p4[Z]);
      for (int j=0;j<3;j++){
	 vec1[j] = p1[j] - p4[j];
	 vec2[j] = p2[j] - p4[j];
	 vec3[j] = p3[j] - p4[j];
      }
      area = areaDet(vec1,vec2,vec3);
      printf("%.6LF\n",area);
   }
}

