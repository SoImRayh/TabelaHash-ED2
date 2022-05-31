#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "TabelaHash.h"

#define max 10007
int colisao;

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}


int main()
{
    ///para controle de tempo:
    struct timeval t0;
    struct timeval t1;
    float elapsed = 0;

    ///para gerar numeros aleatorios
    srand(15);
    int num;

    ///base para a tabela hash
    struct aluno* aluno;
    aluno = (struct aluno*) malloc(sizeof (struct aluno));
    Hash *hash = criaHash(max);

    ///preenchendo a tabela
    for (int i = 0; i < max; ++i) {
        num = rand();
        if(isEmpty(hash,num) == 0)
            colisao++;
        if (num%2 != 0){
            aluno->matricula = num;
            aluno->nome = "rayh";
            aluno->n1 = 1;
            aluno->n2 = 10;
            aluno->n3 = 100;
        }else{
            aluno->matricula = num;
            aluno->nome = "cabeca";
            aluno->n1 = 1;
            aluno->n2 = 10;
            aluno->n3 = 100;
        }

    ///inserindo na tabela hash a informação
        gettimeofday(&t0,0);
        insereHash_Encadeamento_Separado(hash,*aluno);
        gettimeofday(&t1,0);
        elapsed += timedifference_msec(t0,t1);
    }

    ///finalização do programa

    printf("\n quantidade de colisao: %d"
           "\n tempo: %f e %f",colisao,elapsed);

    ///interface com usuário
    printf("\nInsira a chave a ser procurada: ");
    scanf("%d",&num);

    ///tempo de busca na arvore
    gettimeofday(&t0,0);
    buscaHash_Encadeamento_Separado(hash,num,aluno);
    gettimeofday(&t1,0);
    elapsed = timedifference_msec(t0 ,t1);


    if ( aluno->matricula == num)
        printf("achamos o resultado:"
               "\nmatricula: %d"
               "\nnome: %s"
               "\nnotas:"
               "\n\t n1: %d"
               "\n\t n2: %d"
               "\n\t n3: %d"
               "\n busca feita no tempo de: %f milisegundos",aluno->matricula,aluno->nome,aluno->n1,aluno->n2,aluno->n3,elapsed);
    else
        printf("nao achei\n\n busca feita no tempo de: %f milisegundos",elapsed);

    return 0;
}
