#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//conhecendo a union em c;
typedef union dados
{
    char rg[15];
    char cpf[15];
}tipodados;

typedef struct pessoa
{
    char name[20];
    int age;
    tipodados documents;
}pessoa;


void dados_pessoa(pessoa *p)
{
    int opcao;
  
    printf("Informe o nome: \n");
    scanf(" %[^\n]", p->name);
  
    printf("Informe a idade: \n");
    scanf("%d", &p->age);
   
    printf("Adicione algum documento: 1-cpf ou 2-rg\nSua escolha: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("CPF:");
        scanf("%s",&p->documents.cpf);
        break;
    case 2:
        printf("RG:\n");
        scanf("%d",p->documents.rg);
        break;
    
    default:
        printf("numero invalido");
        break;
    }
}

void list_user(pessoa *p)
{
    printf("Nome: %s\n", p->name);
    printf("Age: %d\n", p->age);
    Printf("Documento: %d", p->documents.cpf);
}


int main(void)
{
    pessoa *pessoa = malloc(sizeof(pessoa));

    dados_pessoa(pessoa);
    system("clear");

    list_user(pessoa);
    sleep(5);


    //acessando os dados da union;
    
    free(pessoa);
    return 0;
}