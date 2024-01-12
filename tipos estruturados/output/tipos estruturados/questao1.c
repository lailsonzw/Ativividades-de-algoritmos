#include <stdio.h> 
#include <stdlib.h> 

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

void preencher_funcionario(funcionarios **dados, int *quantidade)//funcao para preecher os dados de cada funcionario;
{
    *dados = (funcionarios*)malloc(*quantidade * sizeof(funcionarios));
    for(int ordem = 0; ordem <   quantidade; ordem++)
    {
        printf("Digite o nome do funcionario %d:",ordem + 1);
        scanf("%s", (*dados)[ordem].nome);
    }
}


int main() 
{ 
    //1 META: criar uma função que armazene a quantidade de funcionarios e fazer uma função para preencher os dados dos funcionarios;
    
    int quantidade = 0; //variavel que irar guardar o valor de quantos funcionarios irão ter;
    def_quantidade(&quantidade);

    funcionarios dados[quantidade];
    preencher_funcionario(&dados, &quantidade);
    return 0;
}