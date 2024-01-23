//META:Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e genero, o genero deve ser armazenado como um enum. O progama deve ler e imprimir os dados da pessoa;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


//primeiro problema criar um enum para armazenar o genero da pessoa; RESOLVIDO
typedef enum individuo{
    masculino,
    feminino,
}genero;

//segundo problema: criar uma strcut do tipo pessoa; RESOLVIDO
typedef struct pessoa
{
    char nome[50];
    int idade;
    genero sexo;
}dados;

//terceiro problema: fazer um codigo que leia os dados do usuario; RESOLVIDO
void lerdados(dados *pessoa)
{
    int opcao;
    printf("Digite seu nome:\n");
    scanf("%s",pessoa->nome);
    printf("Digite sua idade:\n");
    scanf("%d",&pessoa->idade);
    printf("Digite seu genero: 1-Masculino, 2-Feminino\n");
    scanf("%d",&opcao);

    switch(opcao)
    {
        case 1:
            pessoa->sexo = masculino;
            break;

        case 2: 
            pessoa->sexo = feminino;
            break;
        default:
            printf("erro tente novamente");
            lerdados(&pessoa);
            break;
    }
}

//quarto problema: fazer um codigo que imprima os dados do usuario; 
void imprimirdados(dados *pessoa)
{
    printf("Nome: %s\n",pessoa->nome);
    printf("Idade: %d\n",pessoa->idade);
    printf("Genero: %d\n",pessoa->sexo.feminino);
}

int main()
{
    dados *pessoass;
    *pessoass = malloc(sizeof(dados));

    return 0;
}