#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  typedef enum Dados {alimento = 1, bebida = 2, eletronico = 3}tipo;

typedef struct Produto
{
    char nome[20];
    int preco;
    tipo tipo;
}produto;

void imprimir(produto *dados)
{
    printf("Nome: %s\n", dados->nome);
    printf("Preco: %d\n",dados->preco);
    
    if(dados->tipo > alimento && dados->tipo <= eletronico)
    {
        switch (dados->tipo)
        {
        case alimento:
            printf("Tipo: Alimento\n",dados->tipo);
            break;

        case bebida:
            printf("Tipo: Bebida\n",dados->tipo);
            break;
        
        case eletronico:
            printf("Tipo: Eletronico\n",dados->tipo);
            break;

        default:
            printf("numero inesistente\n");
            break;
        }
    }
}


int main()
{
    produto produto;

    printf("digite o nome do produto:\n");
    scanf("%s",produto.nome);

    printf("digite o preco do produto:\n");
    scanf("%d",&produto.preco);

    printf("digite o tipo do produto: 1 - alimento, 2 - bebida, 3 - eletronico\n");
    scanf("%d",&produto.tipo);

    imprimir(&produto);


    return 0;
}