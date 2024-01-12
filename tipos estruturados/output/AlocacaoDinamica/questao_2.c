#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura que irar guardar os dados basicos do aluno;
typedef struct aluno
{
    char nome[20];
    char resposta[10][1];
    int nota;
} perfil;



//funcao para determinar a quantidade de questoes da prova;
void quantidade_questoes(int *quantidade)
{
    printf("Quantas questões terar a prova?\n Digite a quantidade de questoes:");
    scanf("%d",&*quantidade);
}

//funcao para preencher o gabarito;
void gabarito_prova(int n_questoes, char ***gabarito)
{
    *gabarito = (char**)malloc((n_questoes) * sizeof(char*));
    printf("Diga o gabarito para as seguintes questoes:\n");
    for(int numero = 0; numero < n_questoes; numero++)
    {
        printf("O gabarito da questão %d e:",numero + 1);
        (*gabarito)[numero] = (char*)malloc(sizeof(char));
        scanf("%s",(*gabarito)[numero]);
    }
}

int main()
{
    //primeira etapa do progama concluida;
    int questoes = 0;
    int numero;
    quantidade_questoes(&questoes);
    char **gabarito;
    gabarito_prova(questoes,&gabarito);
    //Q2-a;

    int quantidade_alunos;
    printf("Quantos alunos irao fazer a prova?\n Digite a quantidade de alunos:");
    scanf("%d", &quantidade_alunos);
    perfil alunos[quantidade_alunos];

    //função para preencher a prova de cada aluno;
    for(numero = 0; numero < quantidade_alunos; numero++)
    {
        printf("---HORA DA PROVA---\n");
        printf("digite seu nome:\n");
        scanf("%s", alunos[numero].nome);

        for(int ordem = 0; ordem < questoes; ordem++)
        {
            printf("Digite a resposta para a questao %d\n", ordem + 1);
            scanf(" %s", alunos[numero].resposta[ordem]);
            printf("questão %d = %s\n",ordem + 1, alunos[numero].resposta[ordem]);
        }
    }
    
    //funcao para corrigir a prova de cada aluno;
    for(numero = 0; numero < quantidade_alunos; numero++)
    {
        for(int ordem = 0; ordem < questoes; ordem++)
        {
           if(strcmp(alunos[numero].resposta[ordem],gabarito[ordem]) == 0)
           {
            alunos[numero].nota++;
           }
        }
        printf("nota final= %d", alunos[numero].nota);
    }
    
}