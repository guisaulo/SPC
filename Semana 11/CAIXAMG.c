#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//fx = 4x^3-2x^2(a+b)+x(ab);
//dfx = 12x^2-4(a+b)x+a*b;
//d2fx = 24x-4(a+b);

double altura(int n, int n2){
    int a = 12;
    int b = -4*(n+n2);
    int c = n*n2;
    double determinante = sqrt(pow(b,2)-(4*a*c));
    double raiz1 = (-b+determinante)/(2*a);
    double raiz2 = (-b-determinante)/(2*a);

    if(24*raiz1<0) return raiz1;
    else return raiz2;
}

int main(){
    int a, b;
    double x;
    double resultado;
    while(1){
        scanf("%d %d", &a, &b);
        if(a==0 && b==0)break;
        x=altura(a, b);
        resultado=4*pow(x,3)-2*pow(x,2)*(a+b)+x*a*b;
        printf("%.4lf %.4lf\n", x, resultado);
    }
}
