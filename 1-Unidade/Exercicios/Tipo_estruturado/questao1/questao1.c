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
}ingresso;

//1 objetivo: Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Ingresso e
//preencha seus campos com valores fornecidos pelo usuário via teclado. Protótipo: void
//preenche(Ingresso* i) - FEITO;

void salvandodados();

void opcao(int *escolha)
{
    printf("Existe algum ingresso que precisa trocar o preco?\n1-sim  2-nao\nDigite aqui: \n\n");
    scanf("%d",&*escolha);
}

//funcao para definir a quantidade de ingressos;

void preencher(ingresso *ingresso)
{
    printf("===========INGRESSO===========\n");
    printf("Digite o preco do ingresso:\n");
    scanf("%f", &ingresso->preco);
    getchar();
    printf("Digite o local do ingresso:\n");
    scanf("%[^\n]", ingresso->local);
    getchar();
    printf("Digite a atracao:\n");
    scanf("%[^\n]", ingresso->atracao);
    getchar();
    printf("Adicone um id a este ingresso:\n");
    scanf("%d",&ingresso->id);
    getchar();
    printf("==============================\n\n");
}

//2 objetivo: Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Ingresso e imprima
//os valores dos seus campos. Protótipo: void imprime(Ingresso* i) - Feito;

void imprime(ingresso *ingresso)
{
    printf("=====SEU_INGRESSO=====\n");
    printf("Preco: %.2f\n", ingresso->preco);
    printf("Local: %s\n", ingresso->local);
    printf("Atracao: %s\n", ingresso->atracao);
    printf("Id: %d\n",ingresso->id);
    printf("======================\n\n");
}

//Escreva uma função que receba, como parâmetros, o endereço de uma estrutura do tipo Ingresso e um
//novo valor de preço e atualize o preço do ingresso para o novo valor. Protótipo: void
//altera_preco(Ingresso* i, float valor) - FEITO;

void altera_preco(ingresso * ingresso, float newpreco)
{
    printf("Digite o novo preco do ingresso:\n");
    scanf("%f",&newpreco);

    ingresso->preco = newpreco;

    printf("===ATUALIZACAO===\n");
    printf("O preco do ingresso do id: %d foi alterado!",ingresso->id);
    printf("Novo valor: %.2f\n",ingresso->preco);
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
    printf("Digite a quantidade de ingressos:\n");
    scanf("%d",&quantidade);

    ingresso *ingresso = malloc(quantidade*sizeof(ingresso));

    for(int ordem = 0; ordem < quantidade; ordem++)
    {   
        preencher(&ingresso[ordem]);
    }
   
    int escolha = 0;
    opcao(&escolha);

    int id = 0;
    float newpreco = 0;

    //Algoritmo feito para trocar o preco do ingresso;
    switch (escolha)
    {
    case 1:
        
        loading();
        
        for(int ordem = 0; ordem < quantidade; ordem++)
        {
            imprime(&ingresso[ordem]);
        }
        
        printf("Digite o id do ingresso que sera alterado:\n");
        scanf("%d",&id);
        
        for(int ordem = 0; ordem < quantidade; ordem++)
        {
            if(ingresso[ordem].id == id)
            {
                altera_preco(&ingresso[ordem].id, newpreco);
                break;
            }
        }
        case 2:
            break;
        break;

    default:
        printf("O numero digitado não foi encontrado\n");
        printf("tente novamente\n");
        break;
    }

    imprime_menor_maior_preco(quantidade, ingresso);
    return 0;
}