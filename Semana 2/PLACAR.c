#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int instacias, cont=0, menorNota=1000, nota, i;
    char aluno[21], alunoMenorNota[21];

    while(scanf("%d", &instacias) != EOF){

	i=0;
        while(i<instacias){

            scanf("%s %d", aluno, &nota);

            if(nota < menorNota){
                menorNota=nota;
                strcpy(alunoMenorNota, aluno);
            }

            else if(nota==menorNota){
                if(strcmp(aluno, alunoMenorNota)>0)
                    strcpy(alunoMenorNota, aluno);
            }
	    i++;	
        }

        menorNota=1000;
        cont++;
        printf("Instancia %d\n", cont);
        printf("%s\n\n", alunoMenorNota);

    }

    return 0;
}
