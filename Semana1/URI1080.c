#include <stdio.h>

int main()
{
    int i, num, maior=-1, posicao=-1;
    for(i=1; i<=100; i++)
    {
        scanf("%d", &num);
        if(num > maior)
        {
            maior = num;
            posicao = i;
        }
    }
    printf("%d\n", maior);
    printf("%d\n", posicao);
    return 0;
}
