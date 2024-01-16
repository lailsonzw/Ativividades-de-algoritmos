#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Função que irar determinar quantas questões a prova terar;
void quantidade_questoes(int *quantidade)
{
    printf("Digite a quantidade de questões que terar na prova:\n");
    scanf("%d",&*quantidade);
}

//Função que irar salvar as respostas do gabarito no progama;
void gabarito_prova(int *quantidade, char ***gabarito)
{
    *gabarito = (char**)malloc((*quantidade) * sizeof(char*));//aloquei o espaço para a resposta de acordo com o tanto de questoes;
    for(int numero = 0; numero < *quantidade; numero++)
    { 
        printf("digite a resposta para a questão %d\n", numero + 1);
        (*gabarito)[numero] = (char*)malloc(10 * sizeof(char));//Cada vez que ocorre o loop é alocado em cada vetor um espaço de 10 bytes ou cada resposta pode armazenar 10 letras;
        scanf("%s",(*gabarito)[numero]);
    }
    system("clear");
    printf("Gabarito Final\n");
    for(int numero = 0; numero < *quantidade; numero++)
    { 
        printf("Resposta da questao %d = %s.\n ", numero + 1,(*gabarito)[numero]);
    }
    printf("aguarde 3 segundos.\n");
    sleep(1);//Função para pausar o progama durante um periodo definido pelo usuario;
    printf("aguarde 2 segundos.\n");
    sleep(1);
    printf("aguarde 1 segundos.\n");
    sleep(1);
}

//Função para mostrar a porcentagem de aprovação;
void porcentagem_aprovados(int *valor_da_porcentagem, int *resultado)
{
    int total = 0;
    
    printf("Quantos alunos fizeram a prova: \n");
    scanf("%d",&total);

    *resultado = ((*valor_da_porcentagem) * 100) / total;  
    
    printf("A porcentagem dos alunos aprovados foran de: %d por cento\n",*resultado);
}
//Estrutura para guardar o dado de cada aluno; 
typedef struct aluno
{
    char nome[21];
    char respostas[10][2];
    int nota;
}dados;


int main()
{
    // Primeira etapa, meta: definir a quantidade de questões e montar um gabarito - CONCLUIDA
   
    int quantidade = 0;//criei uma variavel que irar guardar o valor de quantas questões terão na prova;
    
    int aprovados = 0;//variavel criada para calcular a quantidade de pessoas aprovadas na sala;
    int resultados = 0;//variavel criada para mostrar a porcentagens de aprovados;

    int numero = 0; // variada criada para ser utilizada em estruturas de repetição;
    int ordem = 0; // variada criada para ser utilizada em estruturas de repetição;

    dados aluno[2];//adcionei uma variavel alunos do tipo struct;

    quantidade_questoes(&quantidade);//coloquei essa variavel dentro da função para determinar a quantidade de questões;
    
    char **gabarito;//Fiz um ponteiro que irar alocar espaço para armazenar o resultado do gabarito;
   
    gabarito_prova(&quantidade, &gabarito);
    
    system("clear");

    //Segunda etapa, meta: mostrar a nota de cada aluno - CONCLUIDA!!!!! 3 DIAS DE LUTA PRA ACHAR O ERRO DA FUNÇÃO CORRIGIR PROVA;

    //função para preencher a prova de cada aluno;
    for(numero = 0; numero < 2; numero++)//função que irar guardar o nome do aluno;
    {
        printf("---HORA DA PROVA---\n");
        printf("digite seu nome:\n");
        scanf("%s",aluno[numero].nome); //PROBLEMA, não esta lendo o nome do primeiro aluno - Consertado: tive que ajeitar a linha 29, pois estava lendo errado;  
        
        for(int ordem = 0; ordem < quantidade; ordem++)//função que irar pegar as respostas do aluno;
        {
            printf("Digite a resposta para a questao %d\n", ordem + 1);
            scanf("%s",aluno[numero].respostas[ordem] );
        }
        
        system("clear");
        
        printf("Nome: %s\n", aluno[numero].nome);
        for(int ordem = 0; ordem < quantidade; ordem ++)//função que irar mostras o nome e as respostas do aluno;
        {
            
            printf("questão %d = %s\n",ordem + 1, aluno[numero].respostas[ordem]);
        }
        system("clear");
    }

    //função para corrigir a prova do aluno;
    for(numero = 0; numero < 2; numero++)
    {
        aluno[numero].nota = 0;
        for(ordem = 0; ordem < quantidade; ordem++)
        { 
            if(strcmp(aluno[numero].respostas[ordem], gabarito[ordem]) == 0)
            {
                aluno[numero].nota = aluno[numero].nota + 10/quantidade;
            }
        }
        printf("nota do aluno %s: %d\n\n", aluno[numero].nome, aluno[numero].nota);
    }

    //Terceira etapa, meta: mostrar a porcentagem de aprovação de cava aluno, nota minima para ser aprovado = 6 - EM PROCESO...

    //Função para verificar a quantidade de alunos aprovados;

    for(numero = 0; numero < 2; numero ++)
    { 
        if(aluno[numero].nota > 6)
        {
            aprovados++;
        }
    }

    porcentagem_aprovados(&aprovados, &resultados);

    return 0;
}
    