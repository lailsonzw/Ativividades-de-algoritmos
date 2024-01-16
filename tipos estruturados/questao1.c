#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>
typedef struct dados// estrutura para guardar os dados de cada funcionario;
{
    char nome[23];
    int salario;
    int indentificador;
    char cargo[23];
}funcionarios;

void def_quantidade(int *numero)//funcao para definir a quantidade de funcionarios;
{ 
    printf("Digite a quantidade de funcionarios: \n");
    scanf("%d", &*numero);    
}

void preencher_funcionario(funcionarios *dados)//funcao para preecher os dados de cada funcionario;
{
    printf("Digite o nome do funcionario:\n");
    scanf("%s", &*dados->nome);
    printf("Digite o salario do funcionario:\n");
    scanf("%d", &dados->salario);
    printf("Digite o indentificador do funcionario:\n");
    scanf("%d", &dados->indentificador);
    printf("Digite o cargo do funcionario:\n");
    scanf("%s", &*dados->cargo);
    
}

void imprimirdados(funcionarios *dados)//funcao para imprimir os dados de cada usuario;
{    
    printf("Funcionario: %s\n",dados->nome);
    printf("Salario: %d\n",dados->salario);
    printf("Indentificacao:%d\n",dados->indentificador);
    printf("Cargo:%s\n",dados->cargo);
    printf("\n");
}

void alterarsalario(funcionarios *dados)//funcao criada para alterar o valor do salario de qualquer funcionario;
{
    printf("Digite o novo salario do funcionario:\n");
    scanf("%d",&dados->salario);
}

void maior_menor(funcionarios vetor[], int tamanho) {
    
    int indiceMaiorSalario = 0;
    int indiceMenorSalario = 0;

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i].salario > vetor[indiceMaiorSalario].salario) {
            indiceMaiorSalario = i;
        }
        if (vetor[i].salario < vetor[indiceMenorSalario].salario) {
            indiceMenorSalario = i;
        }
    }

    // Imprimir informações do funcionário com maior salário
    printf("\nFuncionário com maior salário:\n");
    printf("Cargo: %s\n", vetor[indiceMaiorSalario].cargo);
    printf("Salário: %d\n", vetor[indiceMaiorSalario].salario);

    // Imprimir informações do funcionário com menor salário
    printf("\nFuncionário com menor salário:\n");
    printf("Cargo: %s\n", vetor[indiceMenorSalario].cargo);
    printf("Salário: %d\n", vetor[indiceMenorSalario].salario);
}

int main() 
{ 
    //1 META: criar uma função que armazene a quantidade de funcionarios e fazer uma função para preencher os dados dos funcionarios - COMPLETO;
    
    int quantidade = 0; //variavel que irar guardar o valor de quantos funcionarios irão ter;
    def_quantidade(&quantidade);

    funcionarios dados[quantidade];
    for(int ordem = 0; ordem < quantidade; ordem++)
    { 
        preencher_funcionario(&dados[ordem]);
        system("clear");
    }

    //2 META: criar uma função que imprima os dados dos funcionarios - COMPLETO;
    for(int ordem = 0; ordem < quantidade; ordem++)
    { 
        imprimirdados(&dados[ordem]);
    }
    sleep(3);
    system("clear");

    //3 META: criar uma função que altere os salarios dos funcionarios - COMCLUIDO;
    
    int escolha;
    
    printf("Existe algum funcionario que voce quer alterar o salario?\n");
    printf("Digite algum numero 1-Sim  2-Nao:\n");
    scanf("%d", &escolha);
   
   
    if(escolha == 1)
    {
        int indentificacao = 0;//variavel criada para entrar no endereco do usuario;
        
        printf("Qual funcionario voce deseja alterar o salario?\n\n");
        
        for(int ordem = 0; ordem < quantidade; ordem++)//Estrutura de repeticao criada para listar os funcionarios;
        { 
            imprimirdados(&dados[ordem]);
        }
       
        printf("Digite o indentificador do funcionario que voce deseja alterar o salario:\n");
        scanf("%d",&indentificacao);
        
        for(int ordem = 0; ordem < quantidade; ordem++)
        {
            if(dados[ordem].indentificador == indentificacao  )//estava errando aqui porque estava tentando comparar 2 tipos de array;
            {
                alterarsalario(&dados[ordem]);
            }
        }
        
        printf("Novo salario do funcionario:\n");
        imprimirdados(&dados[indentificacao]);
        
        sleep(5);
        system("clear"); 
    }
    else
    {
        printf("guardando os dados.\n");
        sleep(1);
        system("clear\n");
        printf("guardando os dados..\n");
        sleep(1);
        system("clear\n");
        printf("guardando os dados...\n");
        sleep(1);
        system("clear\n");
    }

    //4 META: escrever uma função que mostre o funcionario que ganha mais e o funcionario que ganha menos;
    
    maior_menor(dados,quantidade);

    return 0;
}