//META: Crie um tipo estruturado para armazenar dados de um ingresso. Uma estrutura deste tipo possui os
//seguintes campos: preço, local e atração. 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

typedef struct Ingresso
{
    float preco;
    char local [20];
    char atracao [20];
    int id;
} ingresso;

void salvandodados();

void opcao(int *escolha)
{
    printf("Existe algum ingresso que precisa trocar o preco?\n1-sim  2-nao\nDigite aqui: ");
    scanf("%d", escolha);
}

//1 objetivo: Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Ingresso e
//preencha seus campos com valores fornecidos pelo usuário via teclado. Protótipo: void
//preenche(Ingresso* i) - FEITO;
void preencher(ingresso *ingresso)
{
    printf("Digite o preco do ingresso:\n");
    scanf("%f", &ingresso->preco);
    getchar();
    printf("Digite o local do evento:\n");
    scanf("%[^\n]", ingresso->local);
    getchar();
    printf("Digite a atracao do evento:\n");
    scanf("%[^\n]", ingresso->atracao);
    getchar();
    printf("Adicone um id a este ingresso:\n");
    scanf("%d", &ingresso->id);
    getchar();
    printf("==============================\n\n");
}

//2 objetivo: Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Ingresso e imprima
//seus campos. Protótipo: void imprime(Ingresso* i) - FEITO;
void imprime(ingresso *ingresso)
{
    printf("Preco: %.2f\n", ingresso->preco);
    printf("Local: %s\n", ingresso->local);
    printf("Atracao: %s\n", ingresso->atracao);
    printf("Id: %d\n\n", ingresso->id);
}

//Escreva uma função que receba, como parâmetros, o endereço de uma estrutura do tipo Ingresso e um
//novo valor de preço e atualize o preço do ingresso para o novo valor. Protótipo: void
//altera_preco(Ingresso* i, float valor) - FEITO;
void altera_preco(ingresso * ingresso, float newpreco)
{
    printf("Digite o novo preco do ingresso:\n");
    scanf("%f", &newpreco);

    ingresso->preco = newpreco;

    printf("===ATUALIZACAO===\n");
    printf("O preco do ingresso do id: %d foi alterado!\n", ingresso->id);
    printf("Novo valor: %.2f\n\n", ingresso->preco);
    salvandodados();
}

//Escreva uma função que receba, como parâmetros, um vetor de ingressos e o tamanho do vetor e
//imprima os eventos de ingresso mais barato e mais caro. Protótipo: void imprime_menor_maior_preco(int
//n, Ingresso* vet) - ;
void imprime_menor_maior_preco(int n, ingresso vet[])
{
    int maior = 0;
    int menor = 0;

    for(int ordem = 0; ordem < n; ordem++)
    {
        if(vet[maior].preco < vet[ordem].preco)
        {
            maior = ordem;
        }
        if(vet[menor].preco > vet[ordem].preco)
        {
            menor = ordem;
        }
    }

    printf("O ingresso mais caro:\nPreco: %.2f\nLocal: %s\nAtracao: %s\nId:%d\n\n", vet[maior].preco, vet[maior].local, vet[maior].atracao, vet[maior].id);
    printf("O ingresso mais barato:\nPreco: %.2f\nLocal: %s\nAtracao: %s\nId:%d\n\n", vet[menor].preco, vet[menor].local, vet[menor].atracao, vet[menor].id);
}

void loading()
{
    printf("carregando.\n");
    sleep(1);
    printf("carregando..\n");
    sleep(1);
    printf("carregando...\n");
}

void salvandodados()
{
    printf("Salvando os dados.\n");
    sleep(1);
    printf("Salvando os dados..\n");
    sleep(1);
    printf("Salvando os dados...\n");
}

int main(void)
{
    int quantidade;
    printf("Digite a quantidade de ingressos que serao vendidos:\n");
    scanf("%d", &quantidade);

    ingresso *vet = malloc(quantidade * sizeof(ingresso));

    for(int i = 0; i < quantidade; i++)
    {
        preencher(&vet[i]);
    }

    int escolha = 0;
    opcao(&escolha);

    int id;
    float newpreco;

    switch (escolha)
    {
    case 1:
        loading();

        printf("Digite o id do ingresso que deseja alterar o preco:\n");
        scanf("%d", &id);

        for(int i = 0; i < quantidade; i++)
        {
            if(vet[i].id == id)
            {
                altera_preco(&vet[i], newpreco);
                break;
            }
        }
        break;
    default:
        break;
    }

    imprime_menor_maior_preco(quantidade, vet);

    free(vet);

    return 0;
}