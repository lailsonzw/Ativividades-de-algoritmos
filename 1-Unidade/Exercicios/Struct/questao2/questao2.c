#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct person
{
    char name [20];
    int documents;
    int age;
};//Estrutura criada para armazenar os dados de uma pessoa;

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

void mostrar(data *user)//Funcao para mostrar os dados dos usuarios;
{
    printf("DADOS\n");
    printf("Nome: %s\n",user->name);
    printf("Idade: %d\n",user->age);
    printf("Numero do documento: %d\n\n", user->documents);
}

void newage(data *user)
{
    int years;
    printf("Faz quantos anos essa pessoa nao atualizou sua idade:\n");
    scanf("%d",&years);
    
    printf("Idade atualizada\n");
    printf("Idade antiga: %d\n", user->age);
    user->age = user->age + years;
    printf("Idade atual: %d\n",user->age);
    
}

void maisvelho_maisnovo(data user[], int tamanho)
{
    int maisvelho = 0;
    int maisnovo = 0; 

    for(int ordem = 0; ordem < tamanho; ordem++)
    {
        if(user[ordem].age > user[maisvelho].age)
        {
            maisvelho = ordem;
        }
        if(user[ordem].age < user[maisvelho].age)
        {
            maisnovo = ordem;
        }
    }

    printf("O mais velho:\n");
    printf("Nome: %s\n",user[maisvelho].name);
    printf("Idade: %d\n\n",user[maisvelho].age);

    printf("O mais novo:\n");
    printf("Nome: %s\n", user[maisnovo].name);
    printf("Idade: %d\n", user[maisnovo].age);
}

int main()
{
    int quantidade; //Variavel criada para definir a quantidade de pessoas no progama;
    def_quantidade(&quantidade);

    //Questão 2, letra A - META, montar uma funcao que preencha os dados dos usuarios - COMPLETA;
    
    data person[quantidade];//Variavel do tipo data adicionada no progama;
    for(int ordem = 0; ordem < quantidade; ordem++)
    {
        preencher(&person[ordem]);
    }

    //Questão 2, letra B - META, montar uma funcao que imprima os dados de cada pessoa - COMPLETA;

    for(int ordem = 0; ordem < quantidade; ordem++)
    {
        printf("Usuario %d\n", ordem + 1);
        mostrar(&person[ordem]);
    }

    //Questão 2, letra C - META, fazer uma funcao que atualize a idade dos users - COMPLETA;
    
    int escolha = 0;//variavel criada para o usuario fazer a escolha abaixo;
    printf("Alguem precisa atualizar a idade?\n1-sim 2-nao\n");
    scanf("%d",&escolha);
    system("clear");

    if(escolha == 1)
    {
        for(int ordem = 0; ordem < quantidade; ordem++)
        {
            printf("Usuario %d\n", ordem + 1);
            mostrar(&person[ordem]);
        }
        
        int documento = 0;
        printf("Digite o numero do documento da pessoa que voce deseja alterar:\n");
        scanf("%d",&documento);
        system("clear");

        for(int ordem = 0; ordem < quantidade; ordem++)
        {
            if(person[ordem].documents == documento)
            {
                newage(&person[ordem]);
                sleep(5);
            }
        }

    }
    system("clear");
    
    //Questão 2, letra D - META, fazer uma funcao que mostre a pessoa mais velha e a pessoa mais nova - COMCLUIDA;

    maisvelho_maisnovo(person, quantidade);
}