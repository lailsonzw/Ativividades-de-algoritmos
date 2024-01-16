#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct person
{
    char name [20];
    int documents;
    int age;
}data;//Estrutura criada para armazenar os dados de uma pessoa;

void def_quantidade(int *quantidade)//Funcao criada para definir a quantidade de pessoas no progama;
{
    printf("Quantas pessoas vao participar?\n");
    scanf("%d",&*quantidade);
}

void preencher(data *user)//Funcao criada para preencher os dados das pessoas;
{
    printf("Digite o seu nome:\n");
    scanf("%s",user->name);
    printf("Digite o numero do seu documento:\n");
    scanf("%d",&user->documents);
    printf("Digite sua idade:\n");
    scanf("%d",&user->age);
    system("clear");
}

int main()
{
    int quantidade; //Variavel criada para definir a quantidade de pessoas no progama;
    def_quantidade(&quantidade);

    //Questão 1, letra A - META montar uma funcao que preencha os dados dos usuarios - COMPLETA;
    
    data person[quantidade];//Variavel do tipo data adicionada no progama;
    for(int ordem = 0; ordem < quantidade; ordem++)
    {
        preencher(&person[ordem]);
    }

}