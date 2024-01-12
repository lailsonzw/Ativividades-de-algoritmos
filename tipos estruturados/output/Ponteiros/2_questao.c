#include <stdio.h>

//D-
int main(void){

    int x, *p;
    x = 100;
    p = &x;
    printf("Valor de p = %p/Valor de *p = %d", p, *p); 
    return 0;
}

// Sim;
//A- Uma mensagem de erro;
//B- Na linha 7 o x nao e acompanhado do &, logo o poteiro não sabe aonde esta o endereco do x, na linha 9 no printf não foi colocado aspas duplas;
//C- Não;
//E- Sim;
