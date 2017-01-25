#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, x1, x2, y1, y2;
    int x1_2, x2_2, y1_2, y2_2;

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d %d %d %d", &x1_2, &y1_2, &x2_2, &y2_2);
        if(y1==y2 && y1_2==y2_2){//ambas horizontal
            if(x1<x1_2 && x1_2<x2 && x2<x2_2) printf("SEGMENT\n");
            else if(x1_2<x1 && x1<x2_2 && x2_2<x2) printf("SEGMENT\n");
            else if(x1<x2 && x2==x1_2 && x2<x2_2) printf("POINT\n");
            else if(x1_2<x1 && x1==x2_2 && x2_2<x2) printf("POINT\n");
            else if(x1==x2 && x1_2==x2_2 && x1==x1_2) printf("POINT\n");
            else if(x1_2>=x1 && x1==x2 && x1<=x2_2) printf("POINT\n");
            else if(x1<x1_2 && x1_2==x2_2 && x1_2<x2) printf("POINT\n");
            else printf("NO\n");
        }
        else if(x1==x2 && x1_2==x2_2){//ambas vertical
            if(y1>y1_2 && y2_2>y1 && y2>y2_2) printf("SEGMENT\n");
            else if(y1<y1_2 && y1_2<y2 && y2<y2_2) printf("SEGMENT\n");
            else if(y1_2<y1 && y2_2==y1 && y2>y2_2) printf("POINT\n");
            else if(y1_2==y2_2 && y1<=y1_2 && y2>=y1_2) printf("POINT\n");
            else if(y1==y2 && y1_2==y2_2 && y1_2==y1) printf("POINT\n");
            else if(y1==y2 && y1_2<=y1 && y2_2>=y1) printf("POINT\n");
            else if(y1<y1_2 && y2==y1_2 && y2<y2_2) printf("POINT\n");
            else printf("NO\n");
        }
        else if(x1==x2 && y1_2==y2_2){//vertical e horizontal
            if(x1_2<=x1 && x2_2>=x1 && y1_2<=y1 && y1_2>=y2) printf("POINT\n");
            else if(y1==y2 && y1==x1 && x1_2==x2_2 && x1_2==y1_2 && x1_2==x1) printf("POINT\n");
            else printf("NO\n");
        }
        else if(x1_2==x2_2 && y1==y2){//horizontal e verticual
            if(x1<=x1_2 && x2>=x1_2 && y1>=y2_2 && y1<=y1_2) printf("POINT\n");
            else if(y1_2==y2_2 && x1_2==y1_2 && x1==x2 && x1==y1 && x1==x1_2) printf("POINT\n");
            else printf("NO\n");
        }
    }
}
