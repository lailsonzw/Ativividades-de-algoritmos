#include <stdio.h>
#include <stdlib.h>


// definindo constantes com enumeração;

typedef enum Bool{
    true,
    false,
}bool;

int main()
{
    bool resposta;
    
    printf("voce gosta de algoritmos? \n 0- true\n 1-False\n");
    scanf("%d",&resposta);
    
    system("clear");

    if(resposta == true)
    {
        printf("boa escolha\n");
    }
    else if(resposta==false)
    {
        printf("Que pena!\n");
    }
}