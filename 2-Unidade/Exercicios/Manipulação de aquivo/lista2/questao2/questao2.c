//META: Implemente um programa em C para ler o nome e as notas de um n´umero N de alunos e armazen´a-los
//em um arquivo.

#include <stdio.h>
#include <stdlib.h>

//Estrutura para armazenar os dados necessarios dos alunos;
typedef struct turma
{
    char nome[20];
    float notas[3];
}aluno;

//função para definir a quantidade de estudantes;
void quantidade(int * quantidade)
{
    printf("quantos alunos serão cadastrados??\nalunos: ");
    scanf("%d",&*quantidade);
}

//função para preencher os dados dos alunos;
void preencher(aluno * alunos)
{
    printf("Digite o nome do aluno: ");
    scanf("%s",alunos->nome);

    for(int ordem = 0; ordem < 3; ordem++)
    {
        alunos->notas[ordem] = 0;
        printf("quanto o aluno tirou na %d prova?\nnota: \n",ordem + 1);
        scanf("%f",&alunos->notas[ordem]);
    }
}

//função para imprimir os dados dos alunos?
void imprimir(aluno * alunos)
{
    printf("DADOS\n\n");
    printf("NOME: %s\n\n",alunos->nome);
    printf("NOTAS:\n");
    for(int ordem = 0; ordem < 3; ordem++)
    {
        printf("%d prova: %.2f \n",ordem + 1, alunos->notas[ordem]);
    }
    printf("\n");
}

int main()
{
    //variavel adicionada para receber a quantidade de alunos;
    int n = 0;
    quantidade(&n);

    //variavel adicionada para guardar os dados dos alunos
    aluno alunos[n];

    //variavel criada para criar um arquivo txt e depois imprimir a notas dos alunos;
    FILE *saida;

    saida = fopen("notas.txt","wt");

    if(saida == NULL)
    {
        printf("erro ao criar o aquivo notas\n");
        exit(1);
    }

    //laço de repetição adicionado para preencher todods alunos;
    for(int ordem = 0; ordem < n;ordem++)
    {
        preencher(&alunos[ordem]);
    }

    //laçoe de repetição adicionado para imprimir todos alunos;
    for(int ordem = 0; ordem < n;ordem++)
    {
        imprimir(&alunos[ordem]);
    }

    //laço de rep criado para imprimir as notas dos alunos do arquivos txt;
    for(int ordem = 0; ordem < n;ordem ++)
    {
        fprintf(saida, "Nome do aluno: %s\n\nNOTAS:\n",alunos[ordem].nome);
        for(int ordemp = 0; ordemp < 3;ordemp ++)
        {
            fprintf(saida,"%d primeira prova: %.2f\n",ordemp + 1, alunos[ordem].notas[ordemp]);
        }
        printf("\n");
    }
    
    return 0;
}