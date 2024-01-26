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
    printf("Existe algum ingresso que precisa trocar o preco?\n1-sim  2-nao\nDigite aqui: ");
    scanf("%d",&*escolha);
}

void n_de_ingressos(int *quantidade)
{
    printf("Digite a quantidade de ingressos que serao vendidos:\n");
    scanf("%d",&*quantidade);
}//funcao para definir a quantidade de ingressos;

void preencher(ingresso *ingresso)
{
    printf("===========INGRESSO===========\n");
    printf("Digite o preco do ingresso:\n");
    scanf("%f", &ingresso->preco);
    printf("Digite o local do ingresso:\n");
    scanf("%s", ingresso->local);
    printf("Digite a atracao:\n");
    scanf("%s", ingresso->atracao);
    printf("Adicone um id a este ingresso:\n");
    scanf("%d",&ingresso->id);
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

void altera_preco(ingresso * ingresso, float *newpreco)
{
    printf("Digite o novo preco do ingresso:\n");
    scanf("%f",&*newpreco);

    ingresso->preco = *newpreco;

    printf("===ATUALIZACAO===\n");
    printf("O preco do ingresso do id: %d foi alterado!",ingresso->id);
    printf("Novo valor: %.2f\n",ingresso->preco);
    salvandodados();
}

//Escreva uma função que receba, como parâmetros, um vetor de ingressos e o tamanho do vetor e
//imprima os eventos de ingresso mais barato e mais caro. Protótipo: void imprime_menor_maior_preco(int
//n, Ingresso* vet) - ;

void imprime_menor_maior_preco(int *n, ingresso *vet[])
{
    int maior;
    int menor;

    for(int ordem; ordem < n; ordem++)
    {
        if(vet[maior]->preco < vet[*n]->preco)
        {
            vet[maior]->preco = vet[*n]->preco;
        }
    }

    for(int ordem; ordem < n; ordem++)
    {
        if(vet[menor]->preco > vet[*n]->preco)
        {
            vet[menor]->preco = vet[*n]->preco;
        }
    }

    printf("O ingresso mais carro:\nPreco: %d\nLocal: %s\nAtracao: %s\nId:%d",vet[maior]->preco, vet[maior]->local, vet[maior]->atracao, vet[maior]->id);
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
    n_de_ingressos(&quantidade);

    ingresso ingresso[quantidade];

    for(int ordem = 0; ordem < quantidade; ordem++)
    {   
        preencher(&ingresso[ordem]);
        loading();
    }
    
    for(int ordem = 0; ordem < quantidade; ordem++)
    {
        imprime(&ingresso[ordem]);
    }
   
    int escolha = 0;
    opcao(&escolha);

    //Algoritmo feito para trocar o preco do ingresso;
    switch (escolha)
    {
    case 1:
        int id;//variavel para guardar o id do ingresso desejado;
        int local = 0;//vairavel para acessar o ingresso;
        float newpreco;
        loading();
        
        for(int ordem = 0; ordem < quantidade; ordem++)
        {
            imprime(&ingresso[ordem]);
        }
        printf("Digite o id do ingresso que sera alterado:\n");
        scanf("%d",&id);
        
        while (id != ingresso[local].id)
        {
            local ++;
        }
        
        altera_preco(&ingresso[local], &newpreco);
        break;
    
    case 2:
        printf("ok!");
        break;

    default:
        printf("O numero digitado não foi encontrado\n");
        printf("tente novamente");
        break;
    }

    imprime_menor_maior_preco(&quantidade, &ingresso[quantidade]);
    return 0;
}