#include <cstdio>
#include <cmath>

using namespace std;

double calcDistancia(double x1, double x2,double y1, double y2){
   double pow_x=(x1-x2)*(x1-x2);
   double pow_y=(y1-y2)*(y1-y2);
   return ((double)sqrt(pow_x+pow_y));
}

int main(){
   double x1=0,y1=0,x2=0,y2=0,cmd=0,enf=0;
   while (scanf("%lf",&x1)!=EOF){
      scanf("%lf %lf %lf %lf %lf",&y1,&x2,&y2,&cmd,&enf);
      double ab = calcDistancia(x1,x2,y1,y2);
      double cmdRad = ((cmd*M_PI)/180.0);
      double enfRad = ((enf*M_PI)/180.0);
      double cotgCmd = (1/tan(cmdRad));
      double cotgEnf = (1/tan(enfRad));
      double maxDist = ab*(cotgCmd+cotgEnf);
      printf("%.3lf\n",maxDist);
      
      
   }
}
