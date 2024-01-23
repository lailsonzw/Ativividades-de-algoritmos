//META:Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e genero, o genero deve ser armazenado como um enum. O progama deve ler e imprimir os dados da pessoa;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


//primeiro problema criar um enum para armazenar o genero da pessoa; RESOLVIDO
typedef enum individuo{
    masculino =1,
    feminino =2,
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
    
    printf("Digite seu nome:\n");
    scanf("%s",pessoa->nome);
    printf("Digite sua idade:\n");
    scanf("%d",&pessoa->idade);
    printf("Digite seu genero: 1-Masculino, 2-Feminino\n");
    scanf("%d",&pessoa->sexo);
}

//quarto problema: fazer um codigo que imprima os dados do usuario; RESOLVIDO
void imprimirdados(dados *pessoa)
{
    printf("Nome: %s\n",pessoa->nome);
    printf("Idade: %d\n",pessoa->idade);
    
    if(pessoa->sexo >= masculino && pessoa->sexo <= feminino)    {
        switch (pessoa->sexo)
        {
        case masculino:
            printf("Genero: masculino\n");
            break;
        
        case feminino:
            printf("Genero: feminino\n");
            break;

        default:
            break;
        }
    }
}

int main()
{
    dados pessoass;
    lerdados(&pessoass);
    imprimirdados(&pessoass);

    return 0;
}