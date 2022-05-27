#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h"

#define max 1000
int main()
{
    srand(15);
    int num;
    struct aluno* aluno;
    aluno = (struct aluno*) malloc(sizeof (struct aluno));
    Hash *hash = criaHash(max);
    for (int i = 0; i < 100; ++i) {
        num = rand();
        printf("%d\t",num);
        if(i%10 == 0)
            printf("\n");
        if (num%2 != 0){
            aluno->matricula = num;
            aluno->nome = "rayh";
            aluno->n1 = 1;
            aluno->n2 = 10;
            aluno->n3 = 100;
        }else{
            aluno->matricula = num;
            aluno->nome = "cabeça";
            aluno->n1 = 1;
            aluno->n2 = 10;
            aluno->n3 = 100;
        }
        insereHash_Encadeamento_Separado(hash,*aluno);
    }
    if (buscaHash_Encadeamento_Separado(hash,2,aluno) == 1)
        printf("achamos o resultado");
    else
        printf("nao achei");

    return 0;
}
