//META: Implemente um programa em C para ler o nome e as notas de um n´umero N de alunos e armazen´a-los
//em um arquivo.

#include <stdio.h>
#include <stdlib.h>


typedef struct turma
{
    char nome[20];
    float notas[3];
}aluno;

void quantidade(int * quantidade)
{
    printf("quantos alunos serão cadastrados??\nalunos: ");
    scanf("%d",&*quantidade);
}

void preencher(aluno * alunos)
{
    printf("Digite o nome do aluno: ");
    scanf("%s",alunos->nome);

    for(int ordem = 0; ordem < 3; ordem++)
    {
        printf("quanto o aluno tirou na %d prova?\nnota: \n",ordem + 1);
        scanf("%f",alunos->notas[ordem]);
    }
}

void imprimir(aluno * alunos)
{
    printf("DADOS\n");
    printf("NOME: %s\n",alunos->nome);
    printf("NOTAS:\n");
    for(int ordem = 0; ordem < 3; ordem++)
    {
        printf("%d prova: %f \n",ordem + 1, alunos->notas[ordem]);
    }
}

int main()
{
    int n = 0;
    quantidade(&n);

    aluno alunos[n];

    for(int ordem = 0; ordem < n;ordem++)
    {
        preencher(&alunos[ordem]);
    }

    for(int ordem = 0; ordem < n;ordem++)
    {
        imprimir(&alunos[ordem]);
    }


    return 0;
}