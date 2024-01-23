#include <stdio.h>
#include <stdlib.h>

//maneira de definir constantes em c
#define TRUE 0
#define FALSE 1

// definindo constantes com enumeração;


int main()
{
    int resposta;
    
    printf("voce gosta de algoritmos? \n 0- true\n 1-False\n");
    scanf("%d",&resposta);
    
    system("clear");

    if(resposta == TRUE)
    {
        printf("boa escolha\n");
    }
    else
    {
        printf("Que pena!\n");
    }
}